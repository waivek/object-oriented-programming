#include <string.h>
class stringNode:public Node
{
private:
    static const int stringItemSize = 100;
    char data[stringItemSize];

public:
    stringNode();
    ~stringNode();
    int operator>(stringNode);
    int operator<(stringNode);
    char* getItem();
    void setItem(char*);
    void display();
};
stringNode::stringNode() 
{
    printf("Making a string node\n");
    strcpy(data, "");
}
stringNode::~stringNode()
{
    printf("Destroying the string node\n");
}
int stringNode::operator>(stringNode n)
{
    return strcmp(data, n.data) > 0;
}

int stringNode::operator<(stringNode n)
{
    return strcmp(data, n.data) < 0;
}

char* stringNode::getItem()
{
    return data;
}

void stringNode::setItem(char* x)
{
    strcpy(data, x);
}
void stringNode::display() 
{
    puts(data);
}
