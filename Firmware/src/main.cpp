/**
 * @file main.cpp
 * @author Yogurt (thapdarely@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <main.h>

TaskHandle_t Task_lvgl_Handle;
TaskHandle_t Task_wifi_Handle;
TaskHandle_t Task_mpu6050_Handle;
// TaskHandle_t Task_button_Handle;
// TaskHandle_t Task_ble_Handle;
// EventGroupHandle_t switch_event_group;
// EventBits_t bits_wifi_ble;
// bool isWifiOrBle = true;

void setup()
{
    pinMode(14, OUTPUT);
    digitalWrite(14, HIGH);
    Serial.begin(115200);

#ifdef ESP32_ENABLE
    xTaskCreate(Task_lvgl, "Task_lvgl", 4096, NULL, 3, &Task_lvgl_Handle);
    xTaskCreate(Task_Wifi, "Task_Wifi", 4096, NULL, 4, &Task_wifi_Handle);
    xTaskCreate(Task_MPU6050, "Task_MPU6050", 4096, NULL, 5, &Task_mpu6050_Handle);
#else
    xTaskCreatePinnedToCore(
        Task_lvgl, "Task_lvgl", 4096, NULL, 1, &Task_lvgl_Handle, LVGL_RUNNING_CORE);
    xTaskCreatePinnedToCore(
        Task_Wifi, "Task_Wifi", 4096, NULL, 4, &Task_wifi_Handle, ESP32_RUNNING_CORE);
    xTaskCreatePinnedToCore(
        Task_MPU6050, "Task_MPU6050", 4096, NULL, 3, &Task_mpu6050_Handle, ESP32_RUNNING_CORE);
    // xTaskCreatePinnedToCore(
        // Task_Button, "Task_Button", 4096, NULL, 2, &Task_button_Handle, ESP32_RUNNING_CORE);
    // xTaskCreatePinnedToCore(
    //     Task_BLE, "Task_BLE", 4096, NULL, 2, &Task_ble_Handle, ESP32_RUNNING_CORE);
#endif
}

void loop()
{
    delay(10000);
}
