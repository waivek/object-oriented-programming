#include <iostream>
#include <stdio.h>
#include <stdlib.h>
class Dice {
private:
    int val;
    char f[5][5];
public:
    Dice() {
        val = 1;

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
    int value();
    void roll();
    void draw();
};
int Dice::value() {
    return val;
}
void Dice::roll() {
    val = (rand() % 6) + 1;
}
void Dice::draw() {
    int x = value();
    int i = 0;
    int j = 0;
    for(i = 1; i < 4; i++) {
        for(j = 1; j < 4; j++) {
            f[i][j] = ' ';
        }
    }




    switch(x) {
    case 1:
        f[2][2] = '*';
        break;
    case 2:
        f[2][1] = '*';
        f[2][3] = '*';
        break;
    case 3:
        f[1][1] = '*';
        f[2][2] = '*';
        f[3][3] = '*';
        break;
    case 4:
        f[1][1] = '*';
        f[1][3] = '*';
        f[3][1] = '*';
        f[3][3] = '*';
        break;
    case 5:
        f[2][2] = '*';
        f[1][1] = '*';
        f[1][3] = '*';
        f[3][1] = '*';
        f[3][3] = '*';
        break;
    case 6:
        f[1][1] = '*';
        f[1][3] = '*';
        f[3][1] = '*';
        f[3][3] = '*';
        f[2][1] = '*';
        f[2][3] = '*';
        break;
    default:
        printf("Invalid Value. Value unchanged.\n");
    }
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%c", f[i][j]);
        }
        printf("\n");
    }
}
int main(int argc, char ** argv) {
    Dice d;
    char x = ' ';
    while(1) {
        printf("? ");
        x = getchar();
        system("cls");
        if(x == '?') {
            break;
        }
        d.roll();
        d.draw();
    }
}
