#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "RandInt.cpp"

class Dice : randomInt
{
private:
    char f[5][5];
public:
    Dice() : randomInt(1, 6)
    {
        f[0][0] = '+';
        f[0][4] = '+';
        f[4][4] = '+';
        f[4][0] = '+';

        f[0][1] = '-';
        f[0][2] = '-';
        f[0][3] = '-';
        f[4][1] = '-';
        f[4][2] = '-';
        f[4][3] = '-';

        f[1][0] = '|';
        f[2][0] = '|';
        f[3][0] = '|';
        f[1][4] = '|';
        f[2][4] = '|';
        f[3][4] = '|';

    }
    void roll();
    void draw();
};
void Dice::roll() 
{
    generate();
}
void Dice::draw() 
{
    int x = value();
    int i = 0;
    int j = 0;
    printf("%d\n", x);
    for(i = 1; i < 4; i++) 
    {
        for(j = 1; j < 4; j++) 
        {
            f[i][j] = ' ';
        }
    }
    if(x >= 3) 
    {
        f[1][1] = '*';
        f[3][3] = '*';
    }
    if(x >= 4) 
    {
        f[1][3] = '*';
        f[3][1] = '*';
    }
    if(x%4 != 0 && x%2 == 0) 
    {
        f[2][1] = '*';
        f[2][3] = '*';
    }
    if(x%2 != 0) 
    {
        f[2][2] = '*';
    }

    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
            printf("%c", f[i][j]);
        }
        printf("\n");
    }
}
int main(int argc, char ** argv) 
{
    Dice d;
    char x = ' ';
    while(1) 
    {
        printf("? ");
        x = getchar();
        // system("cls")
        system("clear");
        if(x == '?') 
        {
            break;
        }
        d.roll();
        d.draw();
    }
}
