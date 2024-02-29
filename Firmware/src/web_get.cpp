#include "web_get.h"
#include "main.h"
#include <ctime>
#include <ArduinoJson.h>
#include <HTTPClient.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.aliyun.com", 8 * 3600, 60000);

// time
std::string _time_hour, _time_minute;
const char *cstr_hour;
const char *cstr_minute;
// date
std::string date;
const char *cstr_date;
// week
std::string week[7] = {"Mon", "Tue.", "Wed.", "Thu.", "Fri.", "Sat.", "Sun"};
const char *cstr_week;

// 心知天气api
// String apikey = "SCip88i9pJcY90FZ0";
String apikey = "SzP5qUH8j8QEPdl7a";
String cityid = "wuhan";

DynamicJsonDocument docWeather(1000);
DynamicJsonDocument docAir(1000);

char *location;
char *weather;
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
    int time_hour = timeClient.getHours();
    int time_minute = timeClient.getMinutes();
    _time_hour = std::to_string(time_hour);
    if (time_minute < 10)
        _time_minute = "0" + std::to_string(time_minute);
    else
        _time_minute = std::to_string(time_minute);
    cstr_hour = _time_hour.c_str();
    cstr_minute = _time_minute.c_str();
    // Serial.println(time_minute);

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

    String weatherUrl = "https://api.seniverse.com/v3/weather/now.json?key=";
    weatherUrl += apikey;
    weatherUrl += "&location=";
    weatherUrl += cityid;
    weatherUrl += "&language=zh-Hans&unit=c";

    String airUrl = "https://api.seniverse.com/v3/air/now.json?key=";
    airUrl += apikey;
    airUrl += "&location=";
    airUrl += cityid;
    airUrl += "&language=zh-Hans&scope=city";

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
            strcat(temperature, "°");
            cstr_tem = temperature;

            strcpy(humidity, docWeather["results"][0]["now"]["humidity"]);
            strcat(humidity, "%");
            cstr_hum = humidity;

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
}

void Task_Wifi(void *pvParameters)
{
    (void)pvParameters;
    Wifi_Connect();
    timeClient.begin();

    for (;;)
    {
        get_local_time();
        get_xinzhi_weather();
        //  延时 30 秒
        vTaskDelay(pdMS_TO_TICKS(30000)); // 每隔 30 秒更新一次时间
    }
}