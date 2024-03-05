// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ScreenMenu_screen_init(void)
{
    ui_ScreenMenu = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(ui_ScreenMenu, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenMenu, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelMenu = lv_obj_create(ui_ScreenMenu);
    lv_obj_set_width(ui_PanelMenu, 240);
    lv_obj_set_height(ui_PanelMenu, 280);
    lv_obj_set_align(ui_PanelMenu, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelMenu, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags

    ui_PanelWeaIcon = lv_obj_create(ui_PanelMenu);
    lv_obj_set_width(ui_PanelWeaIcon, 240);
    lv_obj_set_height(ui_PanelWeaIcon, 70);
    lv_obj_set_x(ui_PanelWeaIcon, 0);
    lv_obj_set_y(ui_PanelWeaIcon, -105);
    lv_obj_set_align(ui_PanelWeaIcon, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelWeaIcon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelWeaIcon, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelWeaIcon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageWeaIcon = lv_img_create(ui_PanelWeaIcon);
    lv_img_set_src(ui_ImageWeaIcon, &ui_img_wea_png);
    lv_obj_set_width(ui_ImageWeaIcon, 48);
    lv_obj_set_height(ui_ImageWeaIcon, 48);
    lv_obj_set_x(ui_ImageWeaIcon, -76);
    lv_obj_set_y(ui_ImageWeaIcon, -2);
    lv_obj_set_align(ui_ImageWeaIcon, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageWeaIcon, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageWeaIcon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelWeaIcon = lv_label_create(ui_PanelWeaIcon);
    lv_obj_set_width(ui_LabelWeaIcon, 120);
    lv_obj_set_height(ui_LabelWeaIcon, 24);
    lv_obj_set_x(ui_LabelWeaIcon, 21);
    lv_obj_set_y(ui_LabelWeaIcon, -2);
    lv_obj_set_align(ui_LabelWeaIcon, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelWeaIcon, "Weather");
    lv_obj_set_style_text_align(ui_LabelWeaIcon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelWeaIcon, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_PanelWeaIcon, ui_event_PanelWeaIcon, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenMenu, ui_event_ScreenMenu, LV_EVENT_ALL, NULL);

}