// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.2.0
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
// #include "..main.h"
#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_ScreenHome
void ui_SrceenHome_load_data(void);
void ui_ScreenHome_screen_init(void);
void ui_event_ScreenHome(lv_event_t *e);
extern lv_obj_t *ui_ScreenHome;
extern lv_obj_t *ui_PanelElectric;
extern lv_obj_t *ui_ArcElectric;
extern lv_obj_t *ui_LabelElectric;
extern lv_obj_t *ui_ImageElectric;
extern lv_obj_t *ui_PanelDate;
// extern lv_obj_t *ui_LabelTime;
extern lv_obj_t *ui_LabelSymbol;
extern lv_obj_t *ui_LabelHour;
extern lv_obj_t *ui_LabelMinute;
extern lv_obj_t *ui_LabelDate;
extern lv_obj_t *ui_LabelWeek;
extern lv_obj_t *ui_PanelStep;
extern lv_obj_t *ui_ImageStep;
extern lv_obj_t *ui_LabelStep;
// void ui_event_SliderStep( lv_event_t * e);
extern lv_obj_t *ui_SliderStep;
extern lv_obj_t *ui_PanelWeather;
void ui_event_ArcTem( lv_event_t * e);
extern lv_obj_t *ui_ArcTem;
extern lv_obj_t *ui_ImageTem;
extern lv_obj_t *ui_LabelTem;
void ui_event_ArcHum( lv_event_t * e);
extern lv_obj_t *ui_ArcHum;
extern lv_obj_t *ui_ImageHum;
extern lv_obj_t *ui_LabelHum;
void ui_event_ArcAQI( lv_event_t * e);
extern lv_obj_t *ui_ArcAQI;
extern lv_obj_t *ui_ImageAQI;
extern lv_obj_t *ui_LabelAQI;
// SCREEN: ui_ScreenMenu
void ui_ScreenMenu_screen_init(void);
void ui_event_ScreenMenu( lv_event_t * e);
extern lv_obj_t *ui_ScreenMenu;
extern lv_obj_t *ui_PanelMenu;
void ui_event_PanelWeaIcon( lv_event_t * e);
extern lv_obj_t *ui_PanelWeaIcon;
extern lv_obj_t *ui_ImageWeaIcon;
extern lv_obj_t *ui_LabelWeaIcon;
// SCREEN: ui_ScreenWeather
void ui_SrceenWeather_load_data(void);
void ui_ScreenWeather_screen_init(void);
void ui_event_ScreenWeather( lv_event_t * e);
extern lv_obj_t *ui_ScreenWeather;
extern lv_obj_t * ui_PanelBase;
extern lv_obj_t * ui_LabelLocation;
extern lv_obj_t * ui_ImageLocation;
extern lv_obj_t * ui_LabelTemp;
extern lv_obj_t * ui_LabelDegree;
extern lv_obj_t * ui_LabelSplit;
extern lv_obj_t * ui_LabelWea;
extern lv_obj_t * ui_LabelAir;
extern lv_obj_t * ui_PanelWeaTimePre;
extern lv_obj_t * ui_LabelTime1;
extern lv_obj_t * ui_LabelTime2;
extern lv_obj_t * ui_LabelTime3;
extern lv_obj_t * ui_LabelTime4;
extern lv_obj_t * ui_LabelTimeWea1;
extern lv_obj_t * ui_LabelTimeWea2;
extern lv_obj_t * ui_LabelTimeWea3;
extern lv_obj_t * ui_LabelTimeWea4;
extern lv_obj_t * ui_LabelDegree1;
extern lv_obj_t * ui_LabelDegree2;
extern lv_obj_t * ui_LabelDegree3;
extern lv_obj_t * ui_LabelDegree4;
extern lv_obj_t * ui_PanelWeaDayPre;
extern lv_obj_t * ui_LabelYesterday;
extern lv_obj_t * ui_LabelYesWea;
extern lv_obj_t * ui_LabelYesTem;
extern lv_obj_t * ui_LabelToday;
extern lv_obj_t * ui_LabelTomorrow;
extern lv_obj_t * ui_LabelTodayWea;
extern lv_obj_t * ui_LabelTomWea;
extern lv_obj_t * ui_LabelTodayTem;
extern lv_obj_t * ui_LabelTomTem;
extern lv_obj_t *ui____initial_actions0;

LV_IMG_DECLARE( ui_img_flash3_png);   // assets\flash3.png
LV_IMG_DECLARE( ui_img_step_png);   // assets\step.png
LV_IMG_DECLARE( ui_img_temp2_png);   // assets\temp2.png
LV_IMG_DECLARE( ui_img_hum_png);   // assets\hum.png
LV_IMG_DECLARE( ui_img_aqi_png);   // assets\AQI.png
LV_IMG_DECLARE( ui_img_wea_png);   // assets\wea.png
LV_IMG_DECLARE(ui_img_location2_png);    // assets/location2.png
LV_IMG_DECLARE( ui_img_flash2_png);   // assets\flash2.png



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
