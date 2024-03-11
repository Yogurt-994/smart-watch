/**
 * @file display.cpp
 * @author Yogurt (thapdarely@gmail.com)
 * @brief lvgl驱动
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <TFT_eSPI.h>
#include <CST816S.h>
#include <lvgl.h>
#include <ui_pages/ui.h>
#include <main.h>
#include "display.h"

CST816S touch(21, 22, 5, 32); // sda, scl, rst, irq

TFT_eSPI tft = TFT_eSPI(); /* TFT instance */

static const uint16_t screenWidth = 240;
static const uint16_t screenHeight = 280;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{

    if (touch.available())
    {
        data->state = LV_INDEV_STATE_PR;
        /*Set the coordinates*/
        data->point.x = touch.data.x;
        data->point.y = touch.data.y;
        Serial.print("Data x ");
        Serial.println(touch.data.x);
        Serial.print("Data y ");
        Serial.println(touch.data.y);
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }
}

static void btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
        static uint8_t cnt = 0;
        cnt++;
        /*Get the first child of the button which is the label and change its text*/
        lv_obj_t *label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", cnt);
    }
}
void lv_example_get_started_1(void)
{
    lv_obj_t *btn = lv_btn_create(lv_scr_act()); /*Add a button the current screen*/
    lv_obj_set_size(btn, 120, 50);               /*Set its size*/
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL); /*Assign a callback to the button*/

    lv_obj_t *label = lv_label_create(btn); /*Add a label to the button*/
    lv_label_set_text(label, "Button");     /*Set the labels text*/
    lv_obj_center(label);
}

/**
 * @brief lvgl进程
 *
 * @param pvParameters
 */
void Task_lvgl(void *pvParameters)
{
    (void)pvParameters;

    touch.begin();
    tft.begin();
    tft.setRotation(0);

    lv_init();
    tft.fillScreen(TFT_BLACK);

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 10);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);

    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    /*编写代码*/
    ui_init();

    for (;;)
    {
        lv_obj_t *current_screen = lv_scr_act();
        if (current_screen == ui_ScreenHome)
        {
            ui_SrceenHome_load_data();
        }
        else if (current_screen == ui_ScreenMenu)
        {
        }
        else if (current_screen == ui_ScreenWeather)
        {
            ui_SrceenWeather_load_data();
        }
        else if (current_screen == ui_ScreenRemote)
        {
        }
        lv_task_handler();
        vTaskDelay(50);
    }
}