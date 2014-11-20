#include "Node.h"
#include "triangleNode.h"
#include "squareNode.h"
#include "rectangleNode.h"
#include "circularNode.h"
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
