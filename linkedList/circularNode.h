class circularNode:public Node
{
private:
    int r;

public:
    circularNode();
    ~circularNode();
    int area();
    void display();
};
circularNode::circularNode() 
{
    printf("Making a circular node\n");
    r = 7;
}
circularNode::~circularNode()
{
    printf("Destroying the circular node\n");
}
int circularNode::area() 
{
    return int(r * r * 3.14);
}
void circularNode::display() 
{
    printf("Radius is %d\n", r);
}
