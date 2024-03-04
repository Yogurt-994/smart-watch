SET(SOURCES screens/ui_ScreenHome.c
    screens/ui_ScreenMenu.c
    screens/ui_ScreenWeather.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.cpp
    images/ui_img_flash3_png.c
    images/ui_img_step_png.c
    images/ui_img_temp2_png.c
    images/ui_img_hum_png.c
    images/ui_img_aqi_png.c
    images/ui_img_wea_png.c
    images/ui_img_location2_png.c
    images/ui_img_flash2_png.c)

add_library(ui ${SOURCES})
