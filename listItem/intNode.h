class intNode:public Node
{
private:
    int data;

public:
    intNode();
    ~intNode();
    int operator>(intNode);
    int operator<(intNode);
    int getItem();
    void setItem(int);
    void display();
};
intNode::intNode() 
{
    printf("Making a int node\n");
    data = 0;
}
intNode::~intNode()
{
    printf("Destroying the int node\n");
}
int intNode::operator>(intNode n)
{
    return data > n.data;
}

int intNode::operator<(intNode n)
{
    return data < n.data;
}

int intNode::getItem()
{
    return data;
}

void intNode::setItem(int x)
{
    data = x;
}

void intNode::display()
{
    printf("%d\n", data);
}
