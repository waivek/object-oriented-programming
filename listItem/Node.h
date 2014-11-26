
class Node
{
private:
    Node *next;
public:
    Node();
    virtual ~Node();
    Node* getNext();
    void setNext(Node *n);
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
