/**
 * @file step_count.h
 * @author Yogurt (thapdarely@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#ifndef _STEP_COUNT_H
#define _STEP_COUNT_H

#include <main.h>
#include <cmath>
#include <Arduino.h>

#define ABS(a) (0 - (a)) > 0 ? (-(a)) : (a)   //取a的绝对值
#define SAMPLE_NUM                10          //采样10次取平均值
#define MIN_RELIABLE_VARIATION    100         //最小可信赖变化量
#define MAX_RELIABLE_VARIATION    2000        //最大可信赖变化量

#define ACTIVE_NUM          30            //最活跃轴更新周期
#define ACTIVE_NULL         0             //最活跃轴未知
#define ACTIVE_X            1             //最活跃轴是X
#define ACTIVE_Y            2             //最活跃轴是Y
#define ACTIVE_Z            3             //最活跃轴是Z

extern uint32_t step;

extern int BATvalue;
extern int BATvalue_precent;

void Task_MPU6050(void *pvParameters);

#endif