#include "button.h"
#include "web_get.h"
#include "display.h"
#include <ui_pages/ui.h>

const int buttonPinUp = 34;
const int buttonPinDown = 35;
const int buttonPin = 15;

void Task_Button(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        if (!digitalRead(buttonPinUp))
        {
            while (!digitalRead(buttonPinUp))
                ; // 等待按键松开
            if (current_screen == ui_ScreenCalendar)
            {
                lv_calendar_set_showed_date(ui_Calendar, year, month + 1);
                lv_scr_load(ui_ScreenCalendar);
            }
        }
        if (!digitalRead(buttonPinDown))
        {
            while (!digitalRead(buttonPinDown))
                ; // 等待按键松开
            if (current_screen == ui_ScreenCalendar)
            {
                lv_calendar_set_showed_date(ui_Calendar, year, month - 1);
                lv_scr_load(ui_ScreenCalendar);
            }
        }
    }
}