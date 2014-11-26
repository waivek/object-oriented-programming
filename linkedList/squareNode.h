class squareNode:public Node
{
private:
    int s;

public:
    squareNode();
    ~squareNode();
    int area();
    void display();
};
squareNode::squareNode() 
{
    printf("Making a square node\n");
    s = 5;
}
squareNode::~squareNode()
{
    printf("Destroying the square node\n");
}
int squareNode::area() 
{
    return s * s;
}
void squareNode::display() 
{
    printf("Side is %d\n", s);
}
