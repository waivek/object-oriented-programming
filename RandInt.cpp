#include <iostream.h>
#include <stdio.h>

class randomInt {
private:
    const int RANDMAX = 10;
    int val;
    int min;
    int max;
public:
    randomInt() {
        max = 
        val = rand() % (RANDMAX + 1);
    }
    randomInt(int min, int max) {
        val = rand % (max - min) + min;
    }
    int getValue();
}
int randomInt::getValue() {
    return val;
}



