#include "web_get.h"
#include "main.h"
#include <ctime>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.aliyun.com", 8 * 3600, 60000);

// time
int time_hour, time_minute;
std::string _time_hour, _time_minute;
const char *cstr_hour;
const char *cstr_minute;

// date
time_t UNIX;
int day, month;
std::string date;
const char *cstr_date;
std::string combinedDate;
const char *cstr_combinedDate;

// week
std::string week[7] = {"Mon", "Tue.", "Wed.", "Thu.", "Fri.", "Sat.", "Sun"};
int _week;
const char *cstr_week;

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

void Task_Wifi(void *pvParameters)
{
    (void)pvParameters;
    Wifi_Connect();
    timeClient.begin();

    for (;;)
    {

        timeClient.update();
        time_hour = timeClient.getHours();
        time_minute = timeClient.getMinutes();
        _time_hour = std::to_string(time_hour);
        _time_minute = std::to_string(time_minute);
        cstr_hour = _time_hour.c_str();
        cstr_minute = _time_minute.c_str();

        _week = timeClient.getDay();
        cstr_week = week[_week - 1].c_str();

        UNIX = timeClient.getEpochTime();
        struct tm *timeinfo;
        // 将UNIX时间戳转换为UTC时间
        timeinfo = gmtime(&UNIX);
        timeinfo->tm_hour += 8; // 加8小时
        mktime(timeinfo);
        month = timeinfo->tm_mon + 1;
        day = timeinfo->tm_mday - 1;
        date = std::to_string(month) + '-' + std::to_string(day);
        cstr_date = date.c_str();
        // struct tm *timeinfo;
        // timeinfo = gmtime(&timeClient.getEpochTime())
        // 测试
        Serial.println(month);
        Serial.println(day);
        // timeClient.getFormattedTime
        //  延时 30 秒
        vTaskDelay(pdMS_TO_TICKS(30000)); // 每隔 30 秒更新一次时间
    }
}