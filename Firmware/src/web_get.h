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

extern const char *cstr_now_weather;
extern const char *cstr_tem;
extern const char *cstr_hum;
extern const char *cstr_aqi;

// time weather
extern const char *cstr_hour1;
extern const char *cstr_hour2;
extern const char *cstr_hour3;
extern const char *cstr_hour4;
extern const char *cstr_wea_hour1;
extern const char *cstr_wea_hour2;
extern const char *cstr_wea_hour3;
extern const char *cstr_wea_hour4;
extern const char *cstr_wea_tem_hour1;
extern const char *cstr_wea_tem_hour2;
extern const char *cstr_wea_tem_hour3;
extern const char *cstr_wea_tem_hour4;

// day weather
extern const char *cstr_wea_day0;
extern const char *cstr_wea_day1;
extern const char *cstr_wea_day2;
extern const char *cstr_wea_day_tem0;
extern const char *cstr_wea_day_tem1;
extern const char *cstr_wea_day_tem2;

void Wifi_Connect();
void Task_Wifi(void *pvParameters);

#endif
