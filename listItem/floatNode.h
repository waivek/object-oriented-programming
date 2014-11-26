class floatNode:public Node
{
private:
    float data;

public:
    floatNode();
    ~floatNode();
    int operator>(floatNode);
    int operator<(floatNode);
    float getItem();
    void setItem(float);
    void display();
};
floatNode::floatNode() 
{
    printf("Making a float node\n");
    data = 0.0;
}
floatNode::~floatNode()
{
    printf("Destroying the float node\n");
}
int floatNode::operator>(floatNode n)
{
    return data > n.data;
}

int floatNode::operator<(floatNode n)
{
    return data < n.data;
}

float floatNode::getItem()
{
    return data;
}

void floatNode::setItem(float x)
{
    data = x;
}
void floatNode::display()
{
    printf("%0.2f\n", data);
}

