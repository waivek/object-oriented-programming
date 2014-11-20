#include <stdio.h>
#include <string.h>

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
    int get_days();
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
char *Date::cdow()
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
    char *tmp = day[nd];
    printf("Day=%s\n", tmp);
    return tmp;
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
    printf("Month=%s\n", tmp);
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
int Date::get_days() 
{
    Date d1;
    int i = 0;
    while(d1 < *this) {
        i++;
        d1.d++;
        // printf("Date is %02d/%02d/%04d & i = %03d\n", d1.d, d1.m, d1.y, i);
        if(d1.m == 2) {
            int lyr = (d1.y % 4) == 0;
            if(d1.y % 100 == 0) {
                if(d1.y % 400 != 0) {
                    lyr = 0;
                }
            }
            if(lyr && d1.d > 29 || !lyr && d1.d > 28) {
                d1.m++;
                d1.d = 1;
            }
        } else if (
                (d1.m == 1) ||
                (d1.m == 3) ||
                (d1.m == 5) ||
                (d1.m == 7) ||
                (d1.m == 8) ||
                (d1.m == 10) ||
                (d1.m == 12) 
                ) {
            if(d1.d > 31) {
                d1.m = (d1.m+1) % 12;
                d1.d = 1;
                if(d1.m == 1) {
                    d1.y++;
                }
            }
        } else {
            // printf("30-Day Month Encountered\n");
            // printf("Date is %d/%d/%d\n", d1.d, d1.m, d1.y);
            // getchar();
            if(d1.d > 30) {
                d1.m++;
                d1.d = 1;
            }
        }
    }
    return i;
}
int main(int argc, char *argv[]) 
{
    // Date d1(03, 05, 2014);
    // printf("Date is %d/%d/%d\n", d1.day(), d1.month(), d1.year());
    // printf("Month is %s\n", d1.cmonth());
    // Date d2(04, 05, 2014);
    // printf("Date is %d/%d/%d\n", d2.day(), d2.month(), d2.year());
    // printf("Month is %s\n", d2.cmonth());
    // printf("Is first date < second date: Ans: %d\n", d1 < d2);
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
    printf("Number of days: %d\n", d3.get_days());
    d3.cdow();
    main(argc, argv);
    return 0;
}

    
