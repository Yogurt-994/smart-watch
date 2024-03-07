#include "web_get.h"
#include "main.h"
#include <ctime>
#include <ArduinoJson.h>
#include <HTTPClient.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.aliyun.com", 8 * 3600, 60000);

// time
int time_hour;
int time_minute;
std::string _time_hour, _time_minute;
const char *cstr_hour;
const char *cstr_minute;
// date
std::string date;
const char *cstr_date;
// week
std::string week[7] = {"Mon", "Tue.", "Wed.", "Thu.", "Fri.", "Sat.", "Sun"};
const char *cstr_week;

// time weather
const char *cstr_hour1;
const char *cstr_hour2;
const char *cstr_hour3;
const char *cstr_hour4;
const char *cstr_wea_hour1;
const char *cstr_wea_hour2;
const char *cstr_wea_hour3;
const char *cstr_wea_hour4;
const char *cstr_wea_tem_hour1;
const char *cstr_wea_tem_hour2;
const char *cstr_wea_tem_hour3;
const char *cstr_wea_tem_hour4;

// day weather
const char *cstr_wea_day0;
const char *cstr_wea_day1;
const char *cstr_wea_day2;
const char *cstr_wea_day_tem0;
const char *cstr_wea_day_tem1;
const char *cstr_wea_day_tem2;

// 心知天气api
// String apikey = "SCip88i9pJcY90FZ0";
String apikey = "SzP5qUH8j8QEPdl7a";
String cityid = "wuhan";

DynamicJsonDocument docWeather(1000);
DynamicJsonDocument docAir(1000);
DynamicJsonDocument docWeaHour(1000);
DynamicJsonDocument docWeaDay(1000);

char *location;
const char *cstr_now_weather;
const char *cstr_tem;
const char *cstr_hum;
const char *cstr_aqi;

/// @brief 连接wifi
void Wifi_Connect()
{
    WiFi.begin("Yogurt", "qwertyuiop");
    while (WiFi.status() != WL_CONNECTED)
    {
        vTaskDelay(pdMS_TO_TICKS(300));
        Serial.print(".");
    }
}

/// @brief  获取当地时间
void get_local_time()
{
    // time
    timeClient.update();
    time_hour = timeClient.getHours();
    time_minute = timeClient.getMinutes();
    _time_hour = std::to_string(time_hour);
    if (time_minute < 10)
        _time_minute = "0" + std::to_string(time_minute);
    else
        _time_minute = std::to_string(time_minute);

    cstr_hour = _time_hour.c_str();
    cstr_minute = _time_minute.c_str();
    Serial.println(time_hour);

    // week
    int _week;
    _week = timeClient.getDay();
    cstr_week = week[_week - 1].c_str();

    // date
    time_t UNIX;
    int day, month;
    UNIX = timeClient.getEpochTime();
    struct tm *timeinfo;
    // 将UNIX时间戳转换为UTC时间
    timeinfo = gmtime(&UNIX);
    timeinfo->tm_hour -= 8; // 加8小时
    mktime(timeinfo);
    month = timeinfo->tm_mon + 1;
    day = timeinfo->tm_mday;
    date = std::to_string(month) + '-' + std::to_string(day);
    cstr_date = date.c_str();

    // 测试
    // Serial.println(month);
    // Serial.println(day);
}

/// @brief 获取心知天气
void get_xinzhi_weather()
{
    char temperature[5]; // 心知天气温度
    char humidity[5];    // 湿度
    char aqi[5];
    char now_weather[20];

    char hour1[6];
    char hour2[6];
    char hour3[6];
    char hour4[6];
    char wea_hour1[20];
    char wea_hour2[20];
    char wea_hour3[20];
    char wea_hour4[20];
    char wea_tem_hour1[4];
    char wea_tem_hour2[4];
    char wea_tem_hour3[4];
    char wea_tem_hour4[4];

    char wea_day0[20];
    char wea_day1[20];
    char wea_day2[20];
    char wea_day_tem_high0[5];
    char wea_day_tem_low0[5];
    char wea_day_tem0[10];
    char wea_day_tem_high1[5];
    char wea_day_tem_low1[5];
    char wea_day_tem1[10];
    char wea_day_tem_high2[5];
    char wea_day_tem_low2[5];
    char wea_day_tem2[10];

    String weatherUrl = "https://api.seniverse.com/v3/weather/now.json?key=";
    weatherUrl += apikey;
    weatherUrl += "&location=";
    weatherUrl += cityid;
    weatherUrl += "&language=en&unit=c";

    String airUrl = "https://api.seniverse.com/v3/air/now.json?key=";
    airUrl += apikey;
    airUrl += "&location=";
    airUrl += cityid;
    airUrl += "&language=en&scope=city";

    String weaHourUrl = "https://api.seniverse.com/v3/weather/hourly.json?key=";
    weaHourUrl += apikey;
    weaHourUrl += "&location=";
    weaHourUrl += cityid;
    weaHourUrl += "&language=en&unit=c&start=";
    weaHourUrl += time_hour + 1;
    weaHourUrl += "&hours=";
    weaHourUrl += time_hour + 4;

    String weaDayUrl = "https://api.seniverse.com/v3/weather/daily.json?key=";
    weaDayUrl += apikey;
    weaDayUrl += "&location=";
    weaDayUrl += cityid;
    weaDayUrl += "&language=en&unit=c&start=-1&days=3";

    HTTPClient http;
    http.begin(weatherUrl); // HTTP begin
    int httpCode = http.GET();

    if (httpCode > 0)
    {
        if (httpCode == HTTP_CODE_OK) // 收到正确的内容
        {
            String resBuff = http.getString();
            // Serial.println(resBuff);
            deserializeJson(docWeather, resBuff); // 开始使用Json解析

            strcpy(temperature, docWeather["results"][0]["now"]["temperature"]);
            cstr_tem = temperature;

            strcpy(humidity, docWeather["results"][0]["now"]["humidity"]);
            strcat(humidity, "%");
            cstr_hum = humidity;

            strcpy(now_weather, docWeather["results"][0]["now"]["text"]);
            cstr_now_weather = now_weather;
            // 测试
            // Serial.printf("Temperature: %s\r\n", temperature);
        }
    }
    else
    {
        Serial.printf("HTTP Get Error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();

    http.begin(airUrl);
    int http2Code = http.GET();
    if (http2Code > 0)
    {
        String resBuff2 = http.getString();
        // Serial.println(resBuff2);
        deserializeJson(docAir, resBuff2); // 开始使用Json解析

        strcpy(aqi, docAir["results"][0]["air"]["city"]["aqi"]);
        cstr_aqi = aqi;
        // 测试
        // Serial.printf("AQI:%s",aqi);
    }
    else
    {
        Serial.printf("HTTP Get Error: %s\n", http.errorToString(http2Code).c_str());
    }
    http.end();

    http.begin(weaHourUrl);
    int http3Code = http.GET();
    if (http3Code > 0)
    {
        String resBuff3 = http.getString();
        // Serial.println(resBuff3);
        deserializeJson(docWeaHour, resBuff3); // 开始使用Json解析

        strcpy(wea_hour1, docWeaHour["results"][0]["hourly"][0]["text"]);
        strcpy(wea_hour2, docWeaHour["results"][0]["hourly"][1]["text"]);
        strcpy(wea_hour3, docWeaHour["results"][0]["hourly"][2]["text"]);
        strcpy(wea_hour4, docWeaHour["results"][0]["hourly"][3]["text"]);
        cstr_wea_hour1 = wea_hour1;
        cstr_wea_hour2 = wea_hour2;
        cstr_wea_hour3 = wea_hour3;
        cstr_wea_hour4 = wea_hour3;

        strcpy(wea_tem_hour1, docWeaHour["results"][0]["hourly"][0]["temperature"]);
        cstr_wea_tem_hour1 = wea_tem_hour1;
        strcpy(wea_tem_hour2, docWeaHour["results"][0]["hourly"][1]["temperature"]);
        cstr_wea_tem_hour2 = wea_tem_hour2;
        strcpy(wea_tem_hour3, docWeaHour["results"][0]["hourly"][2]["temperature"]);
        cstr_wea_tem_hour3 = wea_tem_hour3;
        strcpy(wea_tem_hour4, docWeaHour["results"][0]["hourly"][3]["temperature"]);
        cstr_wea_tem_hour4 = wea_tem_hour4;

        std::sprintf(hour1, "%02d:00", time_hour + 1);
        std::sprintf(hour2, "%02d:00", time_hour + 2);
        std::sprintf(hour3, "%02d:00", time_hour + 3);
        std::sprintf(hour4, "%02d:00", time_hour + 4);
        cstr_hour1 = hour1;
        cstr_hour2 = hour2;
        cstr_hour3 = hour3;
        cstr_hour4 = hour4;
    }
    else
    {
        Serial.printf("HTTP Get Error: %s\n", http.errorToString(http3Code).c_str());
    }
    http.end();

    // http.begin(weaDayUrl);
    // int http4Code = http.GET();
    // if (http4Code > 0)
    // {
    //     String resBuff4 = http.getString();
    //     Serial.println(resBuff4);
    //     deserializeJson(docWeaDay, resBuff4); // 开始使用Json解析

    //     /// TODO
    //     /// 有bug 内存泄漏
    //     // strcpy(wea_day0, docWeaDay["results"][0]["daily"][0]["text_day"]);
    //     // strcpy(wea_day1, docWeaDay["results"][0]["daily"][1]["text_day"]);
    //     // strcpy(wea_day2, docWeaDay["results"][0]["daily"][2]["text_day"]);
    //     // cstr_wea_day0 = wea_day0;
    //     // cstr_wea_day1 = wea_day1;
    //     // cstr_wea_day2 = wea_day2;

    //     // strcpy(wea_day_tem_high0, docWeaDay["results"][0]["daily"][0]["high"]);
    //     // strcpy(wea_day_tem_low0, docWeaDay["results"][0]["daily"][0]["low"]);
    //     // sprintf(wea_day_tem0, "%s/%s", wea_day_tem_high0, wea_day_tem_low0);
    //     // cstr_wea_day_tem0 = wea_day_tem0;
    //     // strcpy(wea_day_tem_high1, docWeaDay["results"][0]["daily"][1]["high"]);
    //     // strcpy(wea_day_tem_low1, docWeaDay["results"][0]["daily"][1]["low"]);
    //     // sprintf(wea_day_tem1, "%s/%s", wea_day_tem_high1, wea_day_tem_low1);
    //     // cstr_wea_day_tem1 = wea_day_tem1;
    //     // strcpy(wea_day_tem_high2, docWeaDay["results"][0]["daily"][2]["high"]);
    //     // strcpy(wea_day_tem_low2, docWeaDay["results"][0]["daily"][2]["low"]);
    //     // sprintf(wea_day_tem2, "%s/%s", wea_day_tem_high2, wea_day_tem_low2);
    //     // cstr_wea_day_tem2 = wea_day_tem2;
    // }
    // else
    // {
    //     Serial.printf("HTTP Get Error: %s\n", http.errorToString(http4Code).c_str());
    // }
    // http.end();
}

/**
 * @brief wifi进程
 * 
 * @param pvParameters 
 */
void Task_Wifi(void *pvParameters)
{
    (void)pvParameters;
    Wifi_Connect();
    timeClient.begin();

    for (;;)
    {
        get_local_time();
        get_xinzhi_weather();
        //  delay 30 seconds
        vTaskDelay(pdMS_TO_TICKS(30000)); // 每隔 30 秒更新一次时间
    }
}