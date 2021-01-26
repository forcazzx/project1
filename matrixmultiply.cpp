//
// Created by zzx on 2019/10/25.
//
#include <chrono>
#include "matrixmultiply.h"
#include <stdio.h>

int num(void){
    return totalc;
}
void change(void){
    totalc=3;
    extern int totalb;
    std::cout<<totalb<<endl;
}

// get current local time stamp
int64_t getCurrentLocalTimeStamp()
{
    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
    return tmp.count();

    // return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void UTC2SOW(int year, int month, int day, int hour, int minute, double second, int *weekNo, double *secondOfweek)
{
/*****协调世界时转换为GPS的周秒表示*****///输入时间应为协调世界时，即当地时间-8，返回时间为GPS周和周秒
    int DayofYear = 0;
    int DayofMonth = 0;


    for (int i = 1980; i < year; i++)//从1980年到当前年的上一年经过的天数
    {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            DayofYear += 366;
        else
            DayofYear += 365;
    }
    for (int i = 1; i < month; i++)//从一月到当前月的上一月经历的天数
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i ==12)
            DayofMonth += 31;
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            DayofMonth += 30;
        else
        {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                DayofMonth += 29;
            else
                DayofMonth += 28;
        }
    }
    int Day;
    Day = DayofMonth + day + DayofYear-6;
    *weekNo = Day%7;
    *secondOfweek = Day % 7 * 86400 + hour * 3600 + minute * 60 + second+18;//18表示跳秒
}



