#ifndef TREE_INCLUDED
#define TREE_INCLUDED

typedef struct node{
    int data;
    struct node* fg;
    struct node* fd;
    int height;
    int visited;
}Node;

typedef struct queue{
    Node* data;
    struct queue* next;
}Queue;


Node* createNode(int data);
int getData(Node* n);
void setFG(Node* n, Node* fG);
void setFD(Node* n, Node* fD);
Node* getFG(Node* n);
Node* getFD(Node* n);
int isFile(Node* n);
int size(Node* n);
int height(Node* n);
void prePrint(Node* n);
void inPrint(Node* n);


void rotG(Node **n);
void rotD(Node **n);
void dblRotGD(Node **n);
void dblRotDG(Node **n);
void insert(Node** n, int data);
void equilAll(Node** n);
void equil(Node** n);

void push(Queue** q, Node* e);
Node* pop(Queue** q);

void push1(Queue** q, Node* e);

#endif // TREE_INCLUDED
