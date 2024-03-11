/**
 * @file ble_keyboard.h
 * @author Yogurt(thapdarely@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <Arduino.h>

void ble_keyboard_init(void);
bool check_keyboard_connected(void);
void keyboard_enable_player(void);
int keyboard_player_next(void);
void Task_BLE(void *pvParamters);