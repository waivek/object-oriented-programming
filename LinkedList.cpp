#include <stdio.h>
class Node
{
private:
    Node *next;
public:
    Node();
    virtual ~Node();
    Node* getNext();
    void setNext(Node *n);
    virtual int area() = 0;
    virtual void display() = 0;
};
Node::Node() 
{
    printf("Making a Normal Node\n");
    next = NULL;
}
Node::~Node()
{
    printf("Destroying a Node\n");
}
Node* Node::getNext() 
{
    return next;
}
void Node::setNext(Node *n) 
{
    next = n;
}

class triangleNode:public Node
{
private:
    int height;
    int base;

public:
    triangleNode();
    ~triangleNode();
    int area();
    void display();
};
triangleNode::triangleNode() 
{
    printf("Making a triangle node\n");
    height = 10;
    base = 20;
}
triangleNode::~triangleNode()
{
    printf("Destroying the triangle node\n");
}
int triangleNode::area() 
{
    return height * base / 2;
}
void triangleNode::display() 
{
    printf("Height is %d\n", height);
    printf("Base is %d\n", base);
}
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
        // case 2:
        //     Node n = new squareNode();
        //     break;
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
    l.addNode();
    l.addNode();
    l.traverse();
    printf("The total area is %d\n", l.totalArea());
    return 0;
}
