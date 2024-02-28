// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.2.0
// Project name: SquareLine_Project

#include "ui.h"
#include "web_get.h"

void ui_ScreenHome_screen_init(void)
{
    ui_ScreenHome = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenHome, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_ScreenHome, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenHome, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ScreenHome, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenHome, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelElectric = lv_obj_create(ui_ScreenHome);
    lv_obj_set_width(ui_PanelElectric, 74);
    lv_obj_set_height(ui_PanelElectric, 74);
    lv_obj_set_x(ui_PanelElectric, -63);
    lv_obj_set_y(ui_PanelElectric, -79);
    lv_obj_set_align(ui_PanelElectric, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelElectric, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_PanelElectric, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelElectric, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelElectric, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelElectric, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ArcElectric = lv_arc_create(ui_PanelElectric);
    lv_obj_set_width(ui_ArcElectric, 60);
    lv_obj_set_height(ui_ArcElectric, 63);
    lv_obj_set_x(ui_ArcElectric, 1);
    lv_obj_set_y(ui_ArcElectric, 0);
    lv_obj_set_align(ui_ArcElectric, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ArcElectric, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_arc_set_value(ui_ArcElectric, 50);
    lv_obj_set_style_bg_grad_color(ui_ArcElectric, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ArcElectric, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ArcElectric, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ArcElectric, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_ArcElectric, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_ArcElectric, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcElectric, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcElectric, lv_color_hex(0x1AEE38), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcElectric, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcElectric, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ArcElectric, lv_color_hex(0x1AEE38), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcElectric, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ArcElectric, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ArcElectric, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ArcElectric, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ArcElectric, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_LabelElectric = lv_label_create(ui_ArcElectric);
    lv_obj_set_width(ui_LabelElectric, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_LabelElectric, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_LabelElectric, 0);
    lv_obj_set_y(ui_LabelElectric, -2);
    lv_obj_set_align(ui_LabelElectric, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelElectric, "50%");
    lv_obj_set_style_text_font(ui_LabelElectric, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageElectric = lv_img_create(ui_ArcElectric);
    lv_img_set_src(ui_ImageElectric, &ui_img_flash3_png);
    lv_obj_set_width(ui_ImageElectric, 16);
    lv_obj_set_height(ui_ImageElectric, 16);
    lv_obj_set_x(ui_ImageElectric, 0);
    lv_obj_set_y(ui_ImageElectric, 21);
    lv_obj_set_align(ui_ImageElectric, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageElectric, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_ImageElectric, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_PanelDate = lv_obj_create(ui_ScreenHome);
    lv_obj_set_width(ui_PanelDate, 118);
    lv_obj_set_height(ui_PanelDate, 90);
    lv_obj_set_x(ui_PanelDate, 46);
    lv_obj_set_y(ui_PanelDate, -85);
    lv_obj_set_align(ui_PanelDate, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelDate, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_PanelDate, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelDate, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelDate, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelDate, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTime = lv_label_create(ui_PanelDate);
    // lv_obj_set_width(ui_LabelTime, 75);
    // lv_obj_set_height(ui_LabelTime, 31);
    // lv_obj_set_x(ui_LabelTime, 0);
    // lv_obj_set_y(ui_LabelTime, 17);
    // lv_obj_set_align(ui_LabelTime, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_LabelTime, cstr_combinedTime);
    // lv_obj_set_style_text_color(ui_LabelTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_LabelTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_LabelTime, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_LabelSymbol = lv_label_create(ui_PanelDate);
    lv_obj_set_width(ui_LabelSymbol, 8);
    lv_obj_set_height(ui_LabelSymbol, 31);
    lv_obj_set_x(ui_LabelSymbol, 0);
    lv_obj_set_y(ui_LabelSymbol, 17);
    lv_obj_set_align(ui_LabelSymbol, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSymbol, ":");
    lv_obj_set_style_text_color(ui_LabelSymbol, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSymbol, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSymbol, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelHour = lv_label_create(ui_PanelDate);
    lv_obj_set_width(ui_LabelHour, 42);
    lv_obj_set_height(ui_LabelHour, 31);
    lv_obj_set_x(ui_LabelHour, -23);
    lv_obj_set_y(ui_LabelHour, 19);
    lv_obj_set_align(ui_LabelHour, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelHour, "20");
    lv_obj_set_style_text_color(ui_LabelHour, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHour, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHour, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHour, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelMinute = lv_label_create(ui_PanelDate);
    lv_obj_set_width(ui_LabelMinute, 41);
    lv_obj_set_height(ui_LabelMinute, 31);
    lv_obj_set_x(ui_LabelMinute, 31);
    lv_obj_set_y(ui_LabelMinute, 21);
    lv_obj_set_align(ui_LabelMinute, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelMinute, "28");
    lv_obj_set_style_text_color(ui_LabelMinute, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelMinute, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelMinute, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelMinute, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelDate = lv_label_create(ui_PanelDate);
    lv_obj_set_width(ui_LabelDate, 30);
    lv_obj_set_height(ui_LabelDate, 15);
    lv_obj_set_x(ui_LabelDate, -27);
    lv_obj_set_y(ui_LabelDate, -17);
    lv_obj_set_align(ui_LabelDate, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelDate, "2-28");
    lv_obj_set_style_text_color(ui_LabelDate, lv_color_hex(0xEC2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelDate, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelWeek = lv_label_create(ui_PanelDate);
    lv_obj_set_width(ui_LabelWeek, 39);
    lv_obj_set_height(ui_LabelWeek, 15);
    lv_obj_set_x(ui_LabelWeek, 20);
    lv_obj_set_y(ui_LabelWeek, -17);
    lv_obj_set_align(ui_LabelWeek, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelWeek, "Wed.");
    lv_obj_set_style_text_color(ui_LabelWeek, lv_color_hex(0xEC2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelWeek, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelStep = lv_obj_create(ui_ScreenHome);
    lv_obj_set_width(ui_PanelStep, 201);
    lv_obj_set_height(ui_PanelStep, 69);
    lv_obj_set_align(ui_PanelStep, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelStep, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_PanelStep, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelStep, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageStep = lv_img_create(ui_PanelStep);
    lv_img_set_src(ui_ImageStep, &ui_img_step_png);
    lv_obj_set_width(ui_ImageStep, 16);
    lv_obj_set_height(ui_ImageStep, 16);
    lv_obj_set_x(ui_ImageStep, -78);
    lv_obj_set_y(ui_ImageStep, -15);
    lv_obj_set_align(ui_ImageStep, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageStep, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_ImageStep, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_LabelStep = lv_label_create(ui_PanelStep);
    lv_obj_set_width(ui_LabelStep, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_LabelStep, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_LabelStep, -46);
    lv_obj_set_y(ui_LabelStep, -13);
    lv_obj_set_align(ui_LabelStep, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelStep, "3568");
    lv_obj_set_style_text_color(ui_LabelStep, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SliderStep = lv_slider_create(ui_PanelStep);
    lv_slider_set_range(ui_SliderStep, 0, 10000);
    lv_slider_set_value(ui_SliderStep, 3568, LV_ANIM_OFF);
    if (lv_slider_get_mode(ui_SliderStep) == LV_SLIDER_MODE_RANGE)
        lv_slider_set_left_value(ui_SliderStep, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_SliderStep, 174);
    lv_obj_set_height(ui_SliderStep, 10);
    lv_obj_set_x(ui_SliderStep, 0);
    lv_obj_set_y(ui_SliderStep, 12);
    lv_obj_set_align(ui_SliderStep, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SliderStep, LV_OBJ_FLAG_CLICKABLE); /// Flags

    lv_obj_set_style_pad_left(ui_SliderStep, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SliderStep, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SliderStep, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SliderStep, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_PanelWeather = lv_obj_create(ui_ScreenHome);
    lv_obj_set_width(ui_PanelWeather, 200);
    lv_obj_set_height(ui_PanelWeather, 85);
    lv_obj_set_x(ui_PanelWeather, 1);
    lv_obj_set_y(ui_PanelWeather, 84);
    lv_obj_set_align(ui_PanelWeather, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelWeather, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_PanelWeather, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelWeather, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelWeather, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelWeather, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ArcTem = lv_arc_create(ui_PanelWeather);
    lv_obj_set_width(ui_ArcTem, 54);
    lv_obj_set_height(ui_ArcTem, 68);
    lv_obj_set_x(ui_ArcTem, -64);
    lv_obj_set_y(ui_ArcTem, 0);
    lv_obj_set_align(ui_ArcTem, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ArcTem, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_arc_set_range(ui_ArcTem, -10, 50);
    lv_arc_set_value(ui_ArcTem, 5);
    lv_obj_set_style_arc_color(ui_ArcTem, lv_color_hex(0x2C2C34), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcTem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcTem, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcTem, lv_color_hex(0xF4EA2A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcTem, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcTem, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ArcTem, lv_color_hex(0xF4EA2A), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcTem, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ArcTem, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ArcTem, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ArcTem, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ArcTem, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_ImageTem = lv_img_create(ui_ArcTem);
    lv_img_set_src(ui_ImageTem, &ui_img_temp2_png);
    lv_obj_set_width(ui_ImageTem, 24);
    lv_obj_set_height(ui_ImageTem, 24);
    lv_obj_set_x(ui_ImageTem, -1);
    lv_obj_set_y(ui_ImageTem, -4);
    lv_obj_set_align(ui_ImageTem, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageTem, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_ImageTem, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_LabelTem = lv_label_create(ui_ArcTem);
    lv_obj_set_width(ui_LabelTem, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_LabelTem, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_LabelTem, 1);
    lv_obj_set_y(ui_LabelTem, 22);
    lv_obj_set_align(ui_LabelTem, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelTem, "5°");
    lv_obj_set_style_text_color(ui_LabelTem, lv_color_hex(0xF4EA2A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ArcHum = lv_arc_create(ui_PanelWeather);
    lv_obj_set_width(ui_ArcHum, 54);
    lv_obj_set_height(ui_ArcHum, 64);
    lv_obj_set_x(ui_ArcHum, 0);
    lv_obj_set_y(ui_ArcHum, -2);
    lv_obj_set_align(ui_ArcHum, LV_ALIGN_CENTER);
    lv_arc_set_value(ui_ArcHum, 60);
    lv_obj_set_style_arc_width(ui_ArcHum, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcHum, lv_color_hex(0x1296DB), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcHum, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcHum, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ArcHum, lv_color_hex(0x1296DB), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcHum, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ArcHum, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ArcHum, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ArcHum, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ArcHum, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_ImageHum = lv_img_create(ui_ArcHum);
    lv_img_set_src(ui_ImageHum, &ui_img_hum_png);
    lv_obj_set_width(ui_ImageHum, 24);
    lv_obj_set_height(ui_ImageHum, 24);
    lv_obj_set_x(ui_ImageHum, 0);
    lv_obj_set_y(ui_ImageHum, -4);
    lv_obj_set_align(ui_ImageHum, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageHum, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_ImageHum, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_LabelHum = lv_label_create(ui_ArcHum);
    lv_obj_set_width(ui_LabelHum, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_LabelHum, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_LabelHum, 1);
    lv_obj_set_y(ui_LabelHum, 23);
    lv_obj_set_align(ui_LabelHum, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelHum, "60%");
    lv_obj_set_style_text_color(ui_LabelHum, lv_color_hex(0x1296DB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ArcAQI = lv_arc_create(ui_PanelWeather);
    lv_obj_set_width(ui_ArcAQI, 54);
    lv_obj_set_height(ui_ArcAQI, 63);
    lv_obj_set_x(ui_ArcAQI, 64);
    lv_obj_set_y(ui_ArcAQI, -2);
    lv_obj_set_align(ui_ArcAQI, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ArcAQI, LV_OBJ_FLAG_CLICKABLE); /// Flags
    lv_arc_set_range(ui_ArcAQI, 0, 300);
    lv_arc_set_value(ui_ArcAQI, 157);
    lv_obj_set_style_arc_color(ui_ArcAQI, lv_color_hex(0x2C2C34), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcAQI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcAQI, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcAQI, lv_color_hex(0x1AFA29), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcAQI, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcAQI, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ArcAQI, lv_color_hex(0x1AFA29), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcAQI, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ArcAQI, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ArcAQI, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ArcAQI, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ArcAQI, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_ImageAQI = lv_img_create(ui_ArcAQI);
    lv_img_set_src(ui_ImageAQI, &ui_img_aqi_png);
    lv_obj_set_width(ui_ImageAQI, 24);
    lv_obj_set_height(ui_ImageAQI, 24);
    lv_obj_set_x(ui_ImageAQI, 0);
    lv_obj_set_y(ui_ImageAQI, -3);
    lv_obj_set_align(ui_ImageAQI, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageAQI, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_ImageAQI, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_LabelAQI = lv_label_create(ui_ArcAQI);
    lv_obj_set_width(ui_LabelAQI, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_LabelAQI, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_LabelAQI, 0);
    lv_obj_set_y(ui_LabelAQI, 23);
    lv_obj_set_align(ui_LabelAQI, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelAQI, "157");
    lv_obj_set_style_text_color(ui_LabelAQI, lv_color_hex(0x1AFA29), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAQI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_SliderStep, ui_event_SliderStep, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ArcTem, ui_event_ArcTem, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ArcHum, ui_event_ArcHum, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ArcAQI, ui_event_ArcAQI, LV_EVENT_ALL, NULL);
}

void ui_SrceenHome_load_date(void)
{
    lv_label_set_text(ui_LabelHour, cstr_hour);
    lv_label_set_text(ui_LabelMinute, cstr_minute);
    lv_label_set_text(ui_LabelWeek,cstr_week);
    lv_label_set_text(ui_LabelDate,cstr_date);
    lv_scr_load(ui_ScreenHome);
}