#include<stdio.h>
#include<stdlib.h>
struct node* searchNode(int );
void addNode(struct node* );
struct node* makeNode(int );
void displayList();
void fillList();
void deleteNode(struct node* );
void searchAndDeleteNode();
void reverseList();
void clearList();
void addNodeToEnd(struct node* );

struct node{
    int data;
    struct node* next;
};

struct node* start = NULL;

void searchAndDeleteNode(){
    int x;
    printf("Enter node to be deleted's data ");
    scanf("%d",&x);
    deleteNode(searchNode(x));
}

void deleteNode(struct node* n){
    struct node* t;
    t = start;
    while( t && t->next != n ){
        t = t->next;
    }
    if( start == n && start != NULL ){
        start = start->next;
    }else if( t == NULL || n == NULL){
        printf("Node not present in the list\n");
    }else{
        t->next = n->next;
    }
    free(n);
}

struct node* makeNode(int x){
    struct node* t;
    t = (struct node* ) malloc (sizeof(struct node));
    t->data = x;
    t->next = NULL;
    return t;
}

void addNode(struct node* n){
    n->next = start;
    start = n;
}

struct node* searchNode(int x){
    struct node* n = start;
    while( n ){
        if( n->data == x){
            break;
        }
        n = n->next;
    }
    return n;
}

void displayList(){
    struct node* t;
    printf("The list is \n");
    for( t = start; t; t = t->next){
        printf("%2d\t",t->data);
    }
    if( start == NULL ){
        printf("EMPTY");
    }
    putchar('\n');
}

void fillList(){
    printf("Input elements for the list\nInput -1 to stop\n");
    while(1){
        int input = 0;
        printf("? ");
        scanf("%d", &input);
        if( input == -1 ){
            break;
        }
        addNode( makeNode(input) );
    }
}

void reverseList(){
    if( start != NULL ){
        struct node *a,*b;
        a = start;
        b = a->next;
        while( b ){
            struct node *c;
            c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        start->next = NULL;
        start = a;
    }
}

void addNodeToEnd(struct node *last){
    struct node *t;
    for ( t = start; t->next ; t = t->next ){

    }
    last->next = t->next;
    t->next = last;
}

void clearList(){
    struct node *p;
    p = start;
    while(p){
        p = p->next;
        free(p->prev);
    }
    start = NULL;
    last = NULL;
}
