#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> 
void fill_time (char * , int );
void fill_date (char * );
int input_format();
void clear_screen();

int main()
{
    char time[50], date[100]; 
    int format = input_format();
    while(1) {
       fill_time(time, format);
       fill_date(date);
       clear_screen();
         printf("Current Time: %s\n", time);
        printf("Current Date: %s\n", date);
        sleep(1);
    }
    return 0;
}

void clear_screen() {
#ifdef _WIN32
    system("cls"); 
#else
    system("clear");
#endif
}

int input_format() {
    int format;
    printf(" Choose the Time Format:\n");
    printf(" 1. 12-hour format\n");
    printf(" 2. 24-hour format\n");
    printf(" Make a choice (1 or 2): ");
    scanf("%d", &format);
    return format;
}
void fill_date (char* date) {
    time_t row_time;
    struct tm * current_time;
    time(&row_time);
    current_time = localtime(&row_time);
    strftime(date , 100, "%A, %B %d, %Y", current_time);
}
   
void fill_time (char* buffer, int format) {
    time_t row_time;
    struct tm * current_time;
    time(&row_time);
    current_time = localtime(&row_time);
    if (format == 1) {
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
    } else {
        strftime(buffer, 50, "%H:%M:%S", current_time);
    }
}