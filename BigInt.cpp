#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>

class BigInt {
private:
    static const int MAX_SIZE = 100;
    char *ptr;
    int positive;
public:
    BigInt(char * c) {
        ptr = (char *) malloc(MAX_SIZE); 
        memset(ptr, '0', MAX_SIZE);
        positive = 1;
        if(*c == '-') {
            positive = 0;
            c++;
        }
        ptr += MAX_SIZE - strlen(c) - 1;
        strcpy(ptr, c);
    }
    ~BigInt() {
        printf("Object is being deleted\n");
        ptr += strlen(ptr) + 1 - MAX_SIZE;
        free(ptr);
    }
    void display(); 
    int mod(int a, int b);
    void increment();
    void decrement();
};

void BigInt::display() 
{
    if(!positive) {
        putchar('-');
    }
    puts(ptr);
}
int BigInt::mod(int a, int b)
{
    int t = 0;
    t = a%b;
    return (t<0 ? t+b:t);
}
void BigInt::increment()
{
    char *tmp = ptr + strlen(ptr) - 1;
    while(1) {
        *tmp = mod(*tmp - '0' + 1, 10)  + '0';
        if(*tmp == '0') {
            tmp--;
        } else {
            break;
        }
    }
    if(tmp < ptr) {
        ptr = tmp;
    }
}
void BigInt::decrement()
{
    // printf("Decrement\n");
    char *tmp = ptr + strlen(ptr) - 1;
    while(1) {
        // printf("While Loop\ntmp = %c\n", *tmp);
        // int x = (*tmp - '0' - 1);
        // *tmp = (x < 0 ? x+10:x) + '0';
        *tmp = mod(*tmp -'0' - 1, 10) + '0';
        // printf("After modulo, tmp = %c\n", *tmp);
        if(*tmp == '9') {
            // printf("tmp == 9\n");
            tmp--;
        } else {
            break;
        }
    }
    if(*ptr == '0' /*&& *(ptr+1) != '\0'*/) {
        // printf("ptr++\n");
        if(*(ptr+1) != '\0') {
            ptr++;
        } else {
            positive = mod(positive, 1);
        }
    }
}
int main(int argc, char * argv[])
{
    char num[100] = "";
    printf("Enter Big Integer:");
    std::cin >> num;
    BigInt b = num;
    char x = ' ';
    for(x = ' '; x != '?'; printf("? "), x = getchar()) {
        if(x == ' ') continue;
        b.increment();
        // b.decrement();
        b.display();

    }
}
