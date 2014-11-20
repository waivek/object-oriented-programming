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
    virtual int area(){};
    virtual void display() {};
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

// TRIANGLE NODE STARTS HERE
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

// SQUARE NODE STARTS HERE

class squareNode:public Node
{
private:
    int side;

public:
    squareNode();
    ~squareNode();
    int area();
    void display();
};
squareNode::squareNode() 
{
    printf("Making a square node\n");
    side = 5;
}
squareNode::~squareNode()
{
    printf("Destroying the square node\n");
}
int squareNode::area() 
{
    return side * side;
}
void squareNode::display() 
{
    printf("Side is %d\n", side);
}
// LINKED LIST STARTS HERE
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
            printf("Invalid case selected!\n");
            return ;
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
