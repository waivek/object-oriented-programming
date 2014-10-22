#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class randomInt 
{
private:
    int val;
    int rmin;
    int rmax;
public:
    randomInt() 
    {
        srand(time(NULL));
        rmin = 0;
        rmax = 1;
        generate();
    }
    randomInt(int small, int big) 
    {
        srand(time(NULL));
        rmin = small;
        rmax = big;
        generate();
    }
    int value();
    void generate();
};
int randomInt::value() 
{
    return val;
}

void randomInt::generate() 
{
    val = rand() % (rmax - rmin + 1) + rmin;
}
/*
int main(int argc, char **argv) 
{
    system("clear");
    randomInt r(1, 6);
    randomInt r1(0, 10);
    char x = ' ';
    while(1) 
    {
        printf("%d %d\n", r.value(), r1.value());
        printf("? ");
        x = getchar();
        system("clear");
        if(x == '?') 
        {
            break;
        }
        r.generate();
        r1.generate();
    }
}
*/
