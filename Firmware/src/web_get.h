/**
 * @file web_get.h
 * @author Yogurt(thapdarely@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-28
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once
#ifndef _WEB_GET_H
#define _WEB_GET_H

#include <Arduino.h>
#include <main.h>

extern const char *cstr_hour;
extern const char *cstr_minute;
extern const char *cstr_week;
extern const char *cstr_date;

extern const char *cstr_tem;
extern const char *cstr_hum;
extern const char *cstr_aqi;

void Wifi_Connect();
void Task_Wifi(void *pvParameters);

#endif
