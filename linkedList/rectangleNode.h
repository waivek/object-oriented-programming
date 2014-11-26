class rectangleNode:public Node
{
private:
    int l;
    int b;

public:
    rectangleNode();
    ~rectangleNode();
    int area();
    void display();
};
rectangleNode::rectangleNode() 
{
    printf("Making a rectangle node\n");
    l = 8;
    b = 5;
}
rectangleNode::~rectangleNode()
{
    printf("Destroying the rectangle node\n");
}
int rectangleNode::area() 
{
    return l * b;
}
void rectangleNode::display() 
{
    printf("Length is %d\n", l);
    printf("Breadth is %d\n", b);

}
