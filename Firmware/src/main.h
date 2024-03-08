/**
 * @file main.h
 * @author Yogurt(thapdarely@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#ifndef _MAIN_H
#define _MAIN_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <string>
#include "display.h"
#include "web_get.h"
#include "step_count.h"

#define ENABLE_BLE_KEY_BOARD

#define LVGL_RUNNING_CORE     0
#define ESP32_RUNNING_CORE    1

#define TIMER_DIVIDER 80  // 改变分频器值以改变定时器频率
#define TIMER_SCALE    (TIMER_BASE_CLK / TIMER_DIVIDER)  // 定时器刻度
#define TIMER_INTERVAL_50MS 50000  // 50ms

#endif
