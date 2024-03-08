/**
 * @file ble_keyboard.cpp
 * @author Yogurt(thapdarely@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-03-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <main.h>
#ifdef ENABLE_BLE_KEY_BOARD
#include <BleKeyboard.h>
#endif
#include <ble_keyboard.h>

#ifdef ENABLE_BLE_KEY_BOARD
BleKeyboard bleKeyboard("Smart Watch", "Espressif", 100);
#endif

void ble_keyboard_init(void)
{
#ifdef ENABLE_BLE_KEY_BOARD
    bleKeyboard.begin();
    Serial.println("Start BLE work!");
#endif
}

bool check_keyboard_connected(void)
{
#ifdef ENABLE_BLE_KEY_BOARD
    return bleKeyboard.isConnected();
#else
    return false;
#endif
}

void keyboard_enable_player(void)
{
    if (!check_keyboard_connected())
    {
        Serial.println("check_keyboard_connected error...");
    }

    Serial.println("Sending Play/Pause media key...");
#ifdef ENABLE_BLE_KEY_BOARD
    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
#endif
    return;
}

int keyboard_player_next(void)
{
    if (!check_keyboard_connected())
        return -1;

    Serial.println("Sending Play/Pause media key...");
#ifdef ENABLE_BLE_KEY_BOARD
    bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
#endif
    return 0;
}