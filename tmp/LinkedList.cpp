#include <stdio.h>
#include "Node.h"
#include "triangleNode.h"
#include "squareNode.h"
class LinkedList 
{
private:
    Node *start;
public:
    LinkedList();
    ~LinkedList();
    void addNode();
    void traverse();
    int totalArea();
};
LinkedList::LinkedList() 
{
    start = NULL;
}
LinkedList::~LinkedList() 
{
    printf("Deleting node by node\n");
    Node *t = start->getNext();
    while(start) {
        delete start;
        start = t;
        if(t) t = t->getNext();
    }
    printf("Destroying a LinkedList\n");
}
void LinkedList::addNode() 
{
    printf("Enter type of node:\n");
    printf("1) triangle\n");
    printf("2) square\n");
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
