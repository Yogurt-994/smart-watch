/**
 * @file step_count.cpp
 * @author Yogurt (thapdarely@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-03-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <algorithm>
#include "step_count.h"

// 初始化电池电量检测端口
const int BATpin = 39; // ADC，电压传感器
int BATvalue = 0;      // 用于ADC采集的电压的变量
int BATvalue_precent = 0;

MPU6050 mpu6050(Wire);
uint16_t step_count = 0;
uint32_t step = 0;

// 三轴数据
typedef struct
{
    int16_t X;
    int16_t Y;
    int16_t Z;
} axis_value_t;
axis_value_t old_ave_GyroValue, ave_GyroValue;
// 极值数据
typedef struct
{
    axis_value_t max;
    axis_value_t min;
} peak_value_t;
peak_value_t peak_value;

/**
 * @brief 测试用
 *
 * @return true
 * @return false
 */
bool MPU6050_ReadGyro(int16_t gyroX, int16_t gyroY, int16_t gyroZ)
{
    mpu6050.update();

    gyroX = static_cast<int>(mpu6050.getGyroX());
    gyroY = static_cast<int>(mpu6050.getGyroY());
    gyroZ = static_cast<int>(mpu6050.getGyroZ());

    // Serial.print("\ngyroX : ");
    // Serial.print(gyroX);
    // Serial.print("\tgyroY : ");
    // Serial.print(gyroY);
    // Serial.print("\tgyroZ : ");
    // Serial.println(gyroZ);
    return true;
}

/**
 * @brief MPU6050_ReadGyro(&GyroValue.X , &GyroValue.Y , &GyroValue.Z )
 * 是读取三轴角速度原始数据的函数，将数据保存在GyroValue中；succee_num是用来
 * 防止这个函数返回的是false从而影响结果。
 *（但实际采用过程中大概率是不会采样失败的，可以删去，直接除以SAMPLE_NUM就行）
 *
 */
void Gyro_sample_update(void)
{
    axis_value_t GyroValue;
    axis_value_t change;
    int sum[3] = {0, 0, 0};
    uint8_t success_num = 0;

    // 保存上一次测量的原始数据
    old_ave_GyroValue.X = ave_GyroValue.X;
    old_ave_GyroValue.Y = ave_GyroValue.Y;
    old_ave_GyroValue.Z = ave_GyroValue.Z;

    // 多次测量取平均值
    for (uint8_t i = 0; i < SAMPLE_NUM; i++)
    {
        mpu6050.update();

        GyroValue.X = mpu6050.getGyroX();
        GyroValue.Y = mpu6050.getGyroY();
        GyroValue.Z = mpu6050.getGyroZ();
        sum[0] += GyroValue.X;
        sum[1] += GyroValue.Y;
        sum[2] += GyroValue.Z;
        // Serial.print("\ngyroX : ");
        // Serial.print(GyroValue.X);
        // Serial.print("\tgyroY : ");
        // Serial.print(GyroValue.Y);
        // Serial.print("\tgyroZ : ");
        // Serial.println(GyroValue.Z);
    }
    // Serial.print("\nsum[0] : ");
    // Serial.print(sum[0]);
    // Serial.print("\tsum[1] : ");
    // Serial.print(sum[1]);
    // Serial.print("\tsum[0] : ");
    // Serial.print(sum[2]);
    ave_GyroValue.X = sum[0] / SAMPLE_NUM;
    ave_GyroValue.Y = sum[1] / SAMPLE_NUM;
    ave_GyroValue.Z = sum[2] / SAMPLE_NUM;
    // Serial.print("\nave X : ");
    // Serial.print(ave_GyroValue.X);
    // Serial.print("\tave Y : ");
    // Serial.print(ave_GyroValue.Y);
    // Serial.print("\tave Z : ");
    // Serial.println(ave_GyroValue.Z);

    // 原始数据变化量
    change.X = ABS(ave_GyroValue.X - old_ave_GyroValue.X);
    change.Y = ABS(ave_GyroValue.Y - old_ave_GyroValue.Y);
    change.Z = ABS(ave_GyroValue.Z - old_ave_GyroValue.Z);
    // Serial.print("\nchangeX : ");
    // Serial.print(change.X);
    // Serial.print("\tchangeY : ");
    // Serial.print(change.Y);
    // Serial.print("\tchangeZ : ");
    // Serial.println(change.Z);

    // 如果变化量超出可接受的变化值，则将原始数据退回到上一次的大小
    if (change.X < MIN_RELIABLE_VARIATION || change.X > MAX_RELIABLE_VARIATION)
    {
        ave_GyroValue.X = old_ave_GyroValue.X;
    }
    if (change.Y < MIN_RELIABLE_VARIATION || change.Y > MAX_RELIABLE_VARIATION)
    {
        ave_GyroValue.Y = old_ave_GyroValue.Y;
    }
    if (change.Z < MIN_RELIABLE_VARIATION || change.Z > MAX_RELIABLE_VARIATION)
    {
        ave_GyroValue.Z = old_ave_GyroValue.Z;
    }

    // 分别保存三轴角速度原始数据的最大值和最小值
    peak_value.max.X = std::max(peak_value.max.X, ave_GyroValue.X);
    peak_value.min.X = std::min(peak_value.min.X, ave_GyroValue.X);
    peak_value.max.Y = std::max(peak_value.max.Y, ave_GyroValue.Y);
    peak_value.min.Y = std::min(peak_value.min.Y, ave_GyroValue.Y);
    peak_value.max.Z = std::max(peak_value.max.Z, ave_GyroValue.Z);
    peak_value.min.Z = std::min(peak_value.min.Z, ave_GyroValue.Z);
}

uint8_t most_active_axis = ACTIVE_NULL; // 记录最活跃轴
/**
 * @brief 50ms被调用一次。
 *  每一次被调用时，都会计算一次change值，也就是上一次和这一次原始数据的差值，
 * 然后比较这三个差值的大小，增加最大差值轴的活跃度权重。这里是每1.5秒
 * (由ACTIVE_NUM决定)比较一次权重值，权重最大的轴就是最活跃轴，然后把权重都清零，
 * 下一个1.5秒再重新判断一次。
 *
 */
void which_is_active(void)
{
    axis_value_t change;
    static axis_value_t active; // 三个轴的活跃度权重
    static uint8_t active_sample_num;

    Gyro_sample_update();
    active_sample_num++;

    // 每隔一段时间，比较一次权重大小，判断最活跃轴
    if (active_sample_num >= ACTIVE_NUM)
    {
        if (active.X > active.Y && active.X > active.Z)
        {
            most_active_axis = ACTIVE_X;
        }
        else if (active.Y > active.X && active.Y > active.Z)
        {
            most_active_axis = ACTIVE_Y;
        }
        else if (active.Z > active.X && active.Z > active.Y)
        {
            most_active_axis = ACTIVE_Z;
        }
        else
        {
            most_active_axis = ACTIVE_NULL;
        }
        active_sample_num = 0;
        active.X = 0;
        active.Y = 0;
        active.Z = 0;
    }

    // 原始数据变化量
    change.X = ABS(ave_GyroValue.X - old_ave_GyroValue.X);
    change.Y = ABS(ave_GyroValue.Y - old_ave_GyroValue.Y);
    change.Z = ABS(ave_GyroValue.Z - old_ave_GyroValue.Z);

    // 增加三轴活跃度权重
    if (change.X > change.Y && change.X > change.Z)
    {
        active.X++;
    }
    else if (change.Y > change.X && change.Y > change.Z)
    {
        active.Y++;
    }
    else if (change.Z > change.X && change.Z > change.Y)
    {
        active.Z++;
    }
}

/**
 * @brief 计步
 *
 */
void detect_step(void)
{
    int16_t mid;
    which_is_active();
    switch (most_active_axis)
    {
    case ACTIVE_NULL:
        break;
    // 捕捉原始数据骤增和骤减现象
    case ACTIVE_X:
        mid = (peak_value.max.X + peak_value.min.X) / 2;
        if (old_ave_GyroValue.X < mid && ave_GyroValue.X > mid)
        {
            step_count++;
        }
        else if (old_ave_GyroValue.X > mid && ave_GyroValue.X < mid)
        {
            step_count++;
        }
        break;
    case ACTIVE_Y:
        mid = (peak_value.max.Y + peak_value.min.Y) / 2;
        if (old_ave_GyroValue.Y < mid && ave_GyroValue.Y > mid)
        {
            step_count++;
        }
        else if (old_ave_GyroValue.Y > mid && ave_GyroValue.Y < mid)
        {
            step_count++;
        }
        break;
    case ACTIVE_Z:
        mid = (peak_value.max.Z + peak_value.min.Z) / 2;
        if (old_ave_GyroValue.Z < mid && ave_GyroValue.Z > mid)
        {
            step_count++;
        }
        else if (old_ave_GyroValue.Z > mid && ave_GyroValue.Z < mid)
        {
            step_count++;
        }
        break;
    default:
        break;
    }
}

/**
 * @brief 计步 定时器回调函数
 *
 * @param pxTimer
 */
void step_count_callback(TimerHandle_t pxTimer)
{
    static uint8_t step_time_count = 0;
    detect_step();
    // Serial.print(step);
    step_time_count++;
    if (step_time_count >= 6) // 300ms
    {
        // Serial.print(step);
        step_time_count = 0;
        if (step_count != 0)
        {
            step_count = 0;
            step++;
            // Serial.print(step);
        }
    }
}

/**
 * @brief 电池电量检测
 *
 */
void batteryDetect()
{
    // 满 2400
    // 低 1650
    BATvalue = analogRead(BATpin); // 读取ADC电压采集值
    Serial.print(BATvalue);
    BATvalue_precent = (BATvalue - 1650) * 100 / 750;
    if (BATvalue_precent > 100)
        BATvalue_precent = 100;
    else if (BATvalue_precent <= 0)
        BATvalue_precent = 0;
    Serial.print(BATvalue_precent);
}
/**
 * @brief mpu6050进程
 *
 * @param pvParameters
 */
void Task_MPU6050(void *pvParameters)
{
    (void)pvParameters;
    Wire.begin();
    mpu6050.begin();
    mpu6050.calcGyroOffsets(true);

    pinMode(BATpin, INPUT);

    TimerHandle_t step_timer = xTimerCreate("Step_Timer", pdMS_TO_TICKS(50), pdTRUE, nullptr, step_count_callback);
    if (step_timer != nullptr)
    {
        // 启动定时器
        xTimerStart(step_timer, 0);
        for (;;)
        {
            // BATvalue = analogRead(BATpin); // 读取ADC电压采集值
            batteryDetect(); // 电量检测
            // 测试
            //  mpu6050.update();
            //  Serial.println("=======================================================");
            //  Serial.print(step);
            //  Serial.print("temp : ");
            //  Serial.println(mpu6050.getTemp());
            //  Serial.print("accX : ");
            //  Serial.print(mpu6050.getAccX());
            //  Serial.print("\taccY : ");
            //  Serial.print(mpu6050.getAccY());
            //  Serial.print("\taccZ : ");
            //  Serial.println(mpu6050.getAccZ());

            // Serial.print("gyroX : ");
            // Serial.print(mpu6050.getGyroX());
            // Serial.print("\tgyroY : ");
            // Serial.print(mpu6050.getGyroY());
            // Serial.print("accAngleX : ");
            // Serial.print(mpu6050.getAccAngleX());
            // Serial.print("\taccAngleY : ");
            // Serial.println(mpu6050.getAccAngleY());

            // Serial.print("\tgyroZ : ");
            // Serial.println(mpu6050.getGyroZ());

            // Serial.print("gyroAngleX : ");
            // Serial.print(mpu6050.getGyroAngleX());
            // Serial.print("\tgyroAngleY : ");
            // Serial.print(mpu6050.getGyroAngleY());
            // Serial.print("\tgyroAngleZ : ");
            // Serial.println(mpu6050.getGyroAngleZ());

            // Serial.print("angleX : ");
            // Serial.print(mpu6050.getAngleX());
            // Serial.print("\tangleY : ");
            // Serial.print(mpu6050.getAngleY());
            // Serial.print("\tangleZ : ");
            // Serial.println(mpu6050.getAngleZ());
            // Serial.println("=======================================================\n");
            vTaskDelay(5000);
        }
    }
}