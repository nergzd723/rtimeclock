#include "librtimeclock.h"
#include <stdio.h>

int main(void){
    rtime_t *tie = gettime();
    printf("%d\n", tie->dayofmonth);
    printf("%d\n", tie->month);
    printf("%d\n", tie->day_in_week);
    printf("%d\n", tie->daybycount);
}