#include <stdio.h>
#include "LinkedList.h"

void LinkedList::addNode() 
{
    printf("Enter type of node:\n");
    printf("1) int\n");
    printf("2) float\n");
    printf("3) string\n");
    int o;
    scanf("%d", &o);
    Node *n;
    switch (o) {
        case 1:
            n = new intNode();
            break;
        case 2:
            n = new floatNode();
            break;
        case 3:
            n = new stringNode();
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

void LinkedList::sort()
{
    Node *p, *q, *pos;
    for(p = start; p->getNext(); p = p->getNext()) {
        pos = p;
        for(q = p->getNext(); q; q = q->getNext()) {
            if(q < p) {
                pos = q;
            }
        }
        q = p;
        p = pos;
        pos = q;
    }
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
    return 0;
}
