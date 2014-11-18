#include <stdio.h>

class Date 
{
private:
    int d;
    int m;
    int y;
public:
    Date() {
        d = 1;
        m = 1;
        y = 1900;
    }
    Date(int a, int b, int c) {
        d = a;
        m = b;
        y = c;
    }
    int day();
    int month();
    int year();
    char *cmonth();
    char *cdow();
    int operator<(Date d);
};

int Date::day() 
{
    return d;
}
int Date::month() 
{
    return m;
}
int Date::year() 
{
    printf("The Year is %d\n", y);
    return y;
}
char *Date::cmonth() 
{
    char mth[12][15] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    char *tmp = mth[m - 1];
    // return mth[m - 1];
    return tmp;
}
int Date::operator<(Date d1)
{
    int v;
    if(y < d1.y) {
        v = 1;
    } else if(y > d1.y) {
        v = 0;
    } else {
        if(m < d1.m) {
            v = 1;
        } else if(m > d1.m) {
            v = 0;
        } else {
            if(d < d1.d) {
                v = 1;
            } else if(d > d1.d) {
                v = 0;
            } else {
                v = 0;
            }
        }
    }
    return v;
}
int main(int argc, char *argv[]) 
{
    Date d1(03, 05, 2014);
    printf("Date is %d/%d/%d\n", d1.day(), d1.month(), d1.year());
    printf("Month is %s\n", d1.cmonth());
    Date d2(04, 05, 2014);
    printf("Date is %d/%d/%d\n", d2.day(), d2.month(), d2.year());
    printf("Month is %s\n", d2.cmonth());
    printf("Is first date < second date: Ans: %d\n", d1 < d2);
    return 0;
}

    
