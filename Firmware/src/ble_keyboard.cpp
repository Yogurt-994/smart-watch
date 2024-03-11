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
    Serial.println("BLE Connected!");
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

/**
 * @brief ble进程
 *
 * @param pvParamters
 */
void Task_BLE(void *pvParamters)
{
    // (void)pvParamters;
    // for (;;)
    // {
    //     // 等待事件位，只有 EVENT_BIT_TASK_BLE 被设置时才执行
    //     bits_wifi_ble = xEventGroupWaitBits(switch_event_group, EVENT_BIT_TASK_BLE, pdTRUE, pdTRUE, portMAX_DELAY);

    //     Serial.print(bits_wifi_ble);
    //     Serial.print("\t ble");

    //     WiFi.disconnect();
    //     WiFi.mode(WIFI_OFF);
    //     vTaskDelay(300);

    //     ble_keyboard_init();
    //     while (bits_wifi_ble == EVENT_BIT_TASK_BLE)
    //     {
    //         Serial.print("ble");
    //         vTaskDelay(1000);
    //     }
    // }
    // for (;;)
    // {
    //     if (isWifiOrBle == false)
    //     {
    //         Serial.print("ble");
    //         ble_keyboard_init();
    //         while(isWifiOrBle == false)
    //         {
    //             vTaskDelay(1000);
    //         }
    //     }
    //     else
    //     {
    //         bleKeyboard.end();
    //         vTaskDelay(1000);
    //     }
    // }
}