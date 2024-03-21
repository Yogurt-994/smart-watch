/**
 * @file display.h
 * @author Yogurt (thapdarely@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>
#include <CST816S.h>
#include <lvgl.h>
#include <ui_pages/ui.h>
#include <main.h>
#include "web_get.h"

extern lv_obj_t *current_screen;

void Task_lvgl(void *pvParameters);
