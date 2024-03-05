// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_ScreenHome
void ui_ScreenHome_screen_init(void);
void ui_event_ScreenHome(lv_event_t * e);
lv_obj_t * ui_ScreenHome;
lv_obj_t * ui_PanelElectric;
lv_obj_t * ui_ArcElectric;
lv_obj_t * ui_LabelElectric;
lv_obj_t * ui_ImageElectric;
lv_obj_t * ui_PanelDate;
lv_obj_t * ui_LabelSymbol;
lv_obj_t * ui_LabelDate;
lv_obj_t * ui_LabelWeek;
lv_obj_t * ui_LabelHour;
lv_obj_t * ui_LabelMinute;
lv_obj_t * ui_PanelStep;
lv_obj_t * ui_ImageStep;
lv_obj_t * ui_LabelStep;
void ui_event_SliderStep(lv_event_t * e);
lv_obj_t * ui_SliderStep;
lv_obj_t * ui_PanelWeather;
void ui_event_ArcTem(lv_event_t * e);
lv_obj_t * ui_ArcTem;
lv_obj_t * ui_ImageTem;
lv_obj_t * ui_LabelTem;
void ui_event_ArcHum(lv_event_t * e);
lv_obj_t * ui_ArcHum;
lv_obj_t * ui_ImageHum;
lv_obj_t * ui_LabelHum;
void ui_event_ArcAQI(lv_event_t * e);
lv_obj_t * ui_ArcAQI;
lv_obj_t * ui_ImageAQI;
lv_obj_t * ui_LabelAQI;


// SCREEN: ui_ScreenMenu
void ui_ScreenMenu_screen_init(void);
void ui_event_ScreenMenu(lv_event_t * e);
lv_obj_t * ui_ScreenMenu;
lv_obj_t * ui_PanelMenu;
void ui_event_PanelWeaIcon(lv_event_t * e);
lv_obj_t * ui_PanelWeaIcon;
lv_obj_t * ui_ImageWeaIcon;
lv_obj_t * ui_LabelWeaIcon;


// SCREEN: ui_ScreenWeather
void ui_ScreenWeather_screen_init(void);
void ui_event_ScreenWeather(lv_event_t * e);
lv_obj_t * ui_ScreenWeather;
lv_obj_t * ui_PanelBase;
lv_obj_t * ui_LabelLocation;
lv_obj_t * ui_ImageLocation;
lv_obj_t * ui_LabelTemp;
lv_obj_t * ui_LabelDegree;
lv_obj_t * ui_LabelSplit;
lv_obj_t * ui_LabelWea;
lv_obj_t * ui_LabelAir;
lv_obj_t * ui_PanelWeaTimePre;
lv_obj_t * ui_LabelTime1;
lv_obj_t * ui_LabelTime2;
lv_obj_t * ui_LabelTime3;
lv_obj_t * ui_LabelTime4;
lv_obj_t * ui_LabelTimeWea1;
lv_obj_t * ui_LabelTimeWea2;
lv_obj_t * ui_LabelTimeWea3;
lv_obj_t * ui_LabelTimeWea4;
lv_obj_t * ui_LabelDegree1;
lv_obj_t * ui_LabelDegree2;
lv_obj_t * ui_LabelDegree3;
lv_obj_t * ui_LabelDegree4;
lv_obj_t * ui_PanelWeaDayPre;
lv_obj_t * ui_LabelYesterday;
lv_obj_t * ui_LabelYesWea;
lv_obj_t * ui_LabelYesTem;
lv_obj_t * ui_LabelToday;
lv_obj_t * ui_LabelTomorrow;
lv_obj_t * ui_LabelTodayWea;
lv_obj_t * ui_LabelTomWea;
lv_obj_t * ui_LabelTodayTem;
lv_obj_t * ui_LabelTomTem;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * ui_imgset_flash[2] = {&ui_img_flash2_png, &ui_img_flash3_png};
const lv_img_dsc_t * ui_imgset_location[1] = {&ui_img_location2_png};
const lv_img_dsc_t * ui_imgset_temp[1] = {&ui_img_temp2_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_ScreenHome(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenMenu, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, &ui_ScreenMenu_screen_init);
    }
}
void ui_event_SliderStep(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_LabelStep, target, "", "");
    }
}
void ui_event_ArcTem(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_LabelTem, target, "", "°");
    }
}
void ui_event_ArcHum(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_LabelHum, target, "", "%");
    }
}
void ui_event_ArcAQI(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_LabelAQI, target, "", "");
    }
}
void ui_event_ScreenMenu(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenHome, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, &ui_ScreenHome_screen_init);
    }
}
void ui_event_PanelWeaIcon(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ScreenWeather, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_ScreenWeather_screen_init);
    }
}
void ui_event_ScreenWeather(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_ScreenMenu, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 300, 0, &ui_ScreenMenu_screen_init);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScreenHome_screen_init();
    ui_ScreenMenu_screen_init();
    ui_ScreenWeather_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_ScreenHome);
}