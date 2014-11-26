#include <iostream>
#include <stdio.h>

class StringType {
private:
    char s[1024];
public:
    StringType(char *x) {
        setString(x);
        //setString(x);
    }
    void setString(char *x);
    char* getString();
    int length();
    void append(char *x);
    int compare(char *x);
};
void StringType::setString(char *x) {
    //strcpy(s, x);
    int i = 0;
    while(i < 1024 && *x != '\0') {
        s[i] = *x;
        i++;
        x++;
    }
}
char* StringType::getString() {
    return s;
}
int StringType::length() {
    char *c = s;
    while(*c != '\0') {
        c++;
    }
    return c - s;
}
void StringType::append(char *x) {
    int i = this->length();
    
    do {
        s[i] = *x;
        //s[i] = 'a';
        i++;
        x++;
    } while(*x != '\0');
}
int StringType::compare(char *x) {
    int i = 0;
    while(s[i] != '\0' && *x != '\0') {
        if(s[i] != *x) {
            break;
        }
        i++;
        x++;
    }
    return s[i] - *x;
}
int main(int argc, char **argv) {
    char str[100] = "Book";
    StringType s3 = str;
    char str2[100] = "Books";
    printf("%d\n", s3.compare(str2));
    return 0;
}
