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
