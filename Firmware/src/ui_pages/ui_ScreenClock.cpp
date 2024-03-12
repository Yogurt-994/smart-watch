// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "ui.h"
#include "web_get.h"

void ui_ScreenClock_screen_init(void)
{
    ui_ScreenClock = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenClock, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_ScreenClock, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenClock, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ArcSecond = lv_arc_create(ui_ScreenClock);
    lv_obj_set_width(ui_ArcSecond, 220);
    lv_obj_set_height(ui_ArcSecond, 220);
    lv_obj_set_align(ui_ArcSecond, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ArcSecond, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_arc_set_range(ui_ArcSecond, 0, 60);
    lv_arc_set_value(ui_ArcSecond, 31);
    lv_arc_set_bg_angles(ui_ArcSecond, 0, 360);
    lv_arc_set_rotation(ui_ArcSecond, 270);
    lv_obj_set_style_arc_color(ui_ArcSecond, lv_color_hex(0x251E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcSecond, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcSecond, lv_color_hex(0x251E1E), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcSecond, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_pad_left(ui_ArcSecond, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ArcSecond, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ArcSecond, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ArcSecond, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_ArcMinute = lv_arc_create(ui_ScreenClock);
    lv_obj_set_width(ui_ArcMinute, 180);
    lv_obj_set_height(ui_ArcMinute, 180);
    lv_obj_set_align(ui_ArcMinute, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ArcMinute, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_arc_set_range(ui_ArcMinute, 0, 60);
    lv_arc_set_value(ui_ArcMinute, 48);
    lv_arc_set_bg_angles(ui_ArcMinute, 0, 360);
    lv_arc_set_rotation(ui_ArcMinute, 270);
    lv_obj_set_style_arc_color(ui_ArcMinute, lv_color_hex(0x251E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcMinute, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcMinute, lv_color_hex(0x251E1E), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcMinute, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ArcMinute, lv_color_hex(0x6BCC80), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcMinute, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ArcMinute, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ArcMinute, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ArcMinute, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ArcMinute, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_ArcHour = lv_arc_create(ui_ScreenClock);
    lv_obj_set_width(ui_ArcHour, 140);
    lv_obj_set_height(ui_ArcHour, 140);
    lv_obj_set_align(ui_ArcHour, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ArcHour, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_arc_set_range(ui_ArcHour, 0, 12);
    lv_arc_set_value(ui_ArcHour, 4);
    lv_arc_set_bg_angles(ui_ArcHour, 0, 360);
    lv_arc_set_rotation(ui_ArcHour, 270);
    lv_obj_set_style_arc_color(ui_ArcHour, lv_color_hex(0x251E1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcHour, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcHour, lv_color_hex(0x251E1E), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcHour, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ArcHour, lv_color_hex(0x3C2DC0), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcHour, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ArcHour, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ArcHour, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ArcHour, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ArcHour, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_LabelTime = lv_label_create(ui_ScreenClock);
    lv_obj_set_width(ui_LabelTime, 80);
    lv_obj_set_height(ui_LabelTime, 16);
    lv_obj_set_align(ui_LabelTime, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelTime, "16:48:31");
    lv_obj_set_style_text_color(ui_LabelTime, lv_color_hex(0xFF0707), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ScreenClock, ui_event_ScreenClock, LV_EVENT_ALL, NULL);
}

void ui_ScreenClock_load_data(void)
{
    lv_arc_set_value(ui_ArcSecond, time_second);
    lv_arc_set_value(ui_ArcMinute, time_minute);
    if (time_hour > 12)
        lv_arc_set_value(ui_ArcHour, time_hour - 12);
    else
        lv_arc_set_value(ui_ArcHour, time_hour);
    lv_label_set_text(ui_LabelTime, cstr_time);

    lv_scr_load(ui_ScreenClock);
}