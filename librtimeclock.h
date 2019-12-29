#include <stdint.h>
#include <stdbool.h>
#define DAYS_IN_WEEK 7
#define DAYS_IN_MONTH 28
#define MCOUNT 12
#define WEEK_IN_MONTH (DAYS_IN_MONTH/DAYS_IN_WEEK)
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12
#define NYE 13

typedef struct
{
    uint8_t dayofmonth;
    uint8_t daybycount;
    uint8_t month;
    uint16_t year;
    uint8_t day_in_week;
    bool isLeap;
} rtime_t;

rtime_t* gettime(void);
