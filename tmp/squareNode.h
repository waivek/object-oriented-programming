// #include "Node.h"
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
