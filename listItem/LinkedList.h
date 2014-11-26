#include "Node.h"
#include "intNode.h"
#include "floatNode.h"
#include "stringNode.h"
class LinkedList 
{
private:
    Node *start;
public:
    LinkedList();
    ~LinkedList();
    void addNode();
    void traverse();
    void sort();
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
