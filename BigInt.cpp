#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
using std::max;
int get_max_len(char *, char *);
char* complement(char* , int );
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
    // Line::Line(const Line &obj)
// {
//     cout << "Copy constructor allocating ptr." << endl;
//     ptr = new int;
//    *ptr = *obj.ptr; // copy the value
// }
    BigInt(const BigInt &obj) {
        ptr = (char *) malloc(MAX_SIZE); 
        memset(ptr, '0', MAX_SIZE);
        ptr += MAX_SIZE - strlen(obj.ptr) -1;
        strcpy(ptr, obj.ptr);
    }
    
    // BigInt& operator=(const BigInt& obj)
    // {
    //     ptr = (char *) malloc(MAX_SIZE); 
    //     memset(ptr, '0', MAX_SIZE);
    //     ptr += MAX_SIZE - strlen(obj.ptr) -1;
    //     strcpy(ptr, obj.ptr);
    //     return *this;
    // }
    ~BigInt() {
        printf("BigInt: %s is being deleted\n", ptr);
        ptr += strlen(ptr) + 1 - MAX_SIZE;
        free(ptr);
    }
    void display(); 
    int mod(int a, int b);
    void increment(int c);
    void decrement(int c);
    friend BigInt operator+(BigInt a, BigInt b);
    BigInt operator++();
    BigInt operator++(int);
    BigInt operator--();
    BigInt operator--(int);
    friend BigInt subtract(BigInt, BigInt);
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
void BigInt::increment(int c = 0)
{
    if(c == 0) {
        if(!positive) {
            decrement(1);
            if(*ptr == '0') {
                positive = 1;
            }
            return ;
        }
    }
    char *tmp = ptr + strlen(ptr);
    do {
        tmp--;
        *tmp = mod(*tmp - '0' + 1, 10) + '0';
    } while(*tmp == '0');

    if(tmp < ptr) {
        ptr = tmp;
    }
}
void BigInt::decrement(int c = 0)
{
    if(c == 0) {
        if(*ptr == '0') {
            positive = 0;
        }
        if(!positive) {
            increment(1);
            return;
        }
    }
    char *tmp = ptr + strlen(ptr);
    do {
        tmp--;
        *tmp = mod(*tmp -'0' - 1, 10) + '0';
    } while(*tmp == '9');

    if(*ptr == '0') {
        if(*(ptr+1) != '\0') {
            ptr++;
        }
    }
}
BigInt BigInt::operator++() 
{
    increment();
    return BigInt(ptr);
}
BigInt BigInt::operator++(int) 
{
    BigInt B = ptr;
    increment();
    return B;
}
BigInt BigInt::operator--() 
{
    decrement();
    return BigInt(ptr);
}
BigInt BigInt::operator--(int) 
{
    BigInt B = ptr;
    decrement();
    return B;
}
BigInt operator+(BigInt a, BigInt b) 
{
    int x = 0;
    char *c;
    c = (char *) malloc(a.MAX_SIZE);
    memset(c, '0', a.MAX_SIZE);
    c += a.MAX_SIZE  - 1;
    // printf("\nc+1=%c\n", *(c+1));
    *c = '\0';

    char *p = a.ptr + strlen(a.ptr) - 1;
    char *q = b.ptr + strlen(b.ptr) - 1;
    // printf("\nx=%d\n", x++);

    int carry = 0;

    while((p >= a.ptr || q >= b.ptr) || carry != 0)
    {
        // printf("\nx=%d\n", x++);
        c--;
        int sum = (*p - '0') + (*q - '0') + carry;
        carry = sum / 10;
        sum = sum % 10;

        // printf("\nx=%d\n", x++);
        // printf("\nc=%c\n", *c);
        *c = sum + '0';

        // printf("\nx=%d\n", x++);
        p--;
        q--;
    }
    BigInt d = c;
    c += strlen(c) + 1 - a.MAX_SIZE;
    free(c);

    return d;
}
int get_max_len(char *a, char *b) 
{
    return max(strlen(a), strlen(b));
}
char* complement(char* p, int d) 
{

    // VERY HACKY IF CONDITION, NEED TO RESTRUCTURE ENTIRE METHOD
    // MAYBE TRY A MODULO 10 WITH THE INITIAL TEN'S COMPLEMENT
    if(*p == '0' && strlen(p) == 1) {
        p = p - d;
        *p = *p + 1;
        return p;
    }
    p = p + strlen(p) - 1;
    while(*p == '0') {
        d--;
        p--;
    }
    *p = (10 + '0') - (*p - '0');
    p--;
    d--;
    while(d != 0) {
        *p = (9 + '0') - (*p - '0');
        p--;
        d--;
    }
    p = p - d + 1;
    return p;
}
BigInt subtract(BigInt x1, BigInt x2)
{
    int len  = get_max_len(x1.ptr, x2.ptr);
    // printf("Length = %d\n", len);
    x2.ptr = complement(x2.ptr, len);
    // printf("x2 complement is %s\n", x2.ptr);
    BigInt diff = x1 + x2;
    if(strlen(diff.ptr)  == len + 1) {
        *diff.ptr = '0';
        diff.ptr++;
        diff.positive = 1;
    } else {
        diff.ptr = complement(diff.ptr, len);
        diff.positive = 0;
    }
    return diff;
}
int main(int argc, char * argv[])
{
    char num[100] = "";
    char x = ' ';
    for(x = ' '; x != '?'; printf("? "), x = getchar()) {
        if(x == ' ') continue;
        printf("a:");
        std::cin >> num;
        BigInt a = num;
        printf("b:");
        std::cin >> num;
        BigInt b = num;
        // b++;
        // ++b;
        // BigInt c = a + b;
        // BigInt c = a - b;
        BigInt c = subtract(a, b);
        c.display();
        getchar();
    }
}
