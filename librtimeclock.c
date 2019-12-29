#include <time.h>
#include "librtimeclock.h"
#include <stdlib.h>
#include <stdio.h>

rtime_t* gettime(void)
{
    time_t raw;
    struct tm* timeinfo;
    time(&raw);
    bool isLeap = false;
    timeinfo = localtime(&raw);
    unsigned real_day = timeinfo->tm_yday;
    unsigned real_year = timeinfo->tm_year;
    unsigned month = real_day / DAYS_IN_MONTH;
    unsigned dayinmonth = real_day - (month * DAYS_IN_MONTH);
    if (dayinmonth > 28){
        // New Years Eve
        dayinmonth = 1;
        month = 13;
        if(dayinmonth == 30){
            //leap day
            dayinmonth = 2;
            month = 13;
            isLeap = true;
        }
    }
    unsigned day_in_week = dayinmonth;
    while(day_in_week > 7) day_in_week -= 7;
    rtime_t *rtime = (rtime_t*)malloc(sizeof(rtime_t));
    rtime->dayofmonth = dayinmonth;
    rtime->daybycount = real_day;
    rtime->month = month;
    rtime->year = real_year+1900;
    rtime->isLeap = isLeap;
    rtime->day_in_week = day_in_week;
    printf("%d\n%d\n%d\n%d\n", real_day, real_year ,month, dayinmonth);
    return rtime;
}
