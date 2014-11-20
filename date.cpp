#include <stdio.h>
#include <string.h>

class Date 
{
private:
    int d;
    int m;
    int y;
public:
    Date(); 
    Date(int a, int b, int c);
    int day();
    int month();
    int year();
    void cmonth();
    void cdow();
    int operator<(Date d);
    int get_days();
    int operator-(Date d);
};

Date::Date() 
{
    d = 1;
    m = 1;
    y = 1900;
}
Date::Date(int a, int b, int c) 
{
    d = a;
    m = b;
    y = c;
}
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
void Date::cdow()
{
    char day[7][15] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };
    int nd = get_days() % 7;
    printf("Day=%s\n", day[nd]);
}
void Date::cmonth() 
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
    printf("Month=%s\n", mth[m - 1]);
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
int Date::get_days() 
{
    int nm[13] = {
        0,
        31, 28, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31
    };
    Date d1;
    int i = 0;
    if(d1.y != y) {
        i += (y - d1.y) * 365;
        i += (y - 1900) / 4;
    }
    if(d1.m != m) {
        int j = 0;
        for(j = 1; j < m; j++) {
            i += nm[j];
        }

    }
    if(d1.d != d) {
        i += (d - d1.d);
    }
    return i;
}
int Date::operator-(Date d) {
    return (*this).get_days() - d.get_days();
}
int main(int argc, char *argv[]) 
{
    int m1;
    int d1;
    int y1;
    printf("Enter Day:\n");
    scanf("%d", &d1);
    if(d1 == 0) {
        return 0;
    }
    printf("Enter Month:\n");
    scanf("%d", &m1);
    printf("Enter Year:\n");
    scanf("%d", &y1);
    Date d2(d1, m1, y1);

    int m;
    int d;
    int y;
    printf("Enter Day:\n");
    scanf("%d", &d);
    if(d == 0) {
        return 0;
    }
    printf("Enter Month:\n");
    scanf("%d", &m);
    printf("Enter Year:\n");
    scanf("%d", &y);
    Date d3(d, m, y);
    printf("Number of days: %d\n", d2 - d3);
    main(argc, argv);
    return 0;
}

    
