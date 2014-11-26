#include <iostream>
#include <stdio.h>
class stackType {
private:
    static const int MAXSIZE = 8;
    int s[MAXSIZE];
    int top;
public:
    stackType() {
        top = -1;

        int i = 0;
        /*while(i < MAXSIZE) {
            s[i] = NULL;
        }*/
    }
    void push(int x);
    int pop();
    int isEmpty();
    int isFull();
    void initialize();
};
void stackType::push(int x) {
    top++;
    s[top] = x;
}
int stackType::pop() {
    int x = s[top];
    /*s[top] = NULL;*/
    top--;
    return x;
}
int stackType::isEmpty() {
    return top == -1;
}
int stackType::isFull() {
     return top == MAXSIZE - 1;
}
void stackType::initialize() {
    top = -1;
}
int main(int argc, char **argv) {
    stackType s;
    int x = 0;
    while(!s.isFull()) {
        printf("? ");
        std::cin >> x;
        s.push(x);
    }
    printf("Stackoverflow\n");
    printf("The stack is\n");
    while(!s.isEmpty()) {
        printf("%d\n", s.pop());
    }
    s.initialize();
}
