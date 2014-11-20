#include <stdio.h>
#include "LinkedList.h"
void LinkedList::addNode() 
{
    printf("Enter type of node:\n");
    printf("1) triangle\n");
    printf("2) square\n");
    printf("3) rectangule\n");
    printf("4) circle\n");
    int o;
    scanf("%d", &o);
    Node *n;
    switch (o) {
        case 1:
            n = new triangleNode();
            break;
        case 2:
            n = new squareNode();
            break;
        case 3:
            n = new rectangleNode();
            break;
        case 4:
            n = new circularNode();
            break;
        default:
            printf("Invalid case selected!");
    }
    n->setNext(start);
    start = n;
}

void LinkedList::traverse() 
{
    Node *t;
    printf("The list is \n");
    for(t = start; t; t = t->getNext()) {
        t->display();
    }
    if( start == NULL) {
        printf("EMPTY\n");
    }
}

int LinkedList::totalArea() 
{
    Node *t;
    int a = 0;
    for(t = start; t; t = t->getNext()) {
        a += t->area();
    }
    return a;
}

int main(int argc, const char *argv[])
{
    LinkedList l;
    char x;
    for(x = ' '; x != '?'; printf("? "), x = getchar()) {
        l.addNode();
        getchar();
    }
    l.traverse();
    printf("The total area is %d\n", l.totalArea());
    return 0;
}
