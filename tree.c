#include <math.h>
#include <stdlib.h>
#include "tree.h"


Node* createNode(int data){
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->visited = 0;
    n->fg = n->fd = NULL;
    return n;
}

int getData(Node* n){
    if(n) return n->data;
    return -1;
}

void setFG(Node* n, Node* fG){
    n->fg = fG;
}
void setFD(Node* n, Node* fD){
    n->fd = fD;
}

Node* getFG(Node* n){
    if(!n) return NULL;
    return n->fg;
}
Node* getFD(Node* n){
    if(!n) return NULL;
    return n->fd;
}

int isFile(Node* n){
    if(!n) return 0;
    if(n->fg || n->fd) return 0;
    return 1;
}

int size(Node* n){
    if(!n) return 0;
    if(isFile(n)) return 1;
    return 1+size(n->fg)+size(n->fd);
}

int maxDepth(Node *node)
{
   if (node==NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->fg);
       int rDepth = maxDepth(node->fd);

       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}

int height(Node* n){
    if(!n) return 0;
    if(isFile(n)) return 1;
    int a,b;
    return 1+((a=height(n->fg))>(b=height(n->fd))?a:b);
}

void prePrint(Node* n){
    if(n){
        printf("\t%d", n->data);
        prePrint(n->fg);
        prePrint(n->fd);
    }
}

void inPrint(Node* n){
    if(n){
        inPrint(n->fg);
        printf("\t%d", n->data);
        inPrint(n->fd);
    }
}

void postPrint(Node* n){
    if(n){
        postPrint(n->fg);
        postPrint(n->fd);
        printf("\t%d", n->data);
    }
}


//===================================
void push(Queue** q, Node* e){
    if(*q == NULL){
        (*q) = malloc(sizeof(Queue));
        (*q)->data = e;
        (*q)->next = NULL;
    }
    else{
        Queue *e1 = malloc(sizeof(Queue));
        e1->data = e;
        e1->next = *q;
        *q = e1;
    }
}

Node* pop(Queue** q){
    if(*q != NULL){
        Node *tmp = (*q)->data;
        Queue *tp = *q;
        *q = (*q)->next;
        free(tp);
        return tmp;
    }
    printf("\npop error, queue is NULL");
    return NULL;
}

void push1(Queue** q, Node* e){
    if(*q == NULL){
        (*q) = malloc(sizeof(Queue));
        (*q)->data = e;
        (*q)->next = NULL;
    }
    else{
        Queue* temp = *q;
        while(temp->next) temp=temp->next;
        Queue *e1 = malloc(sizeof(Queue));
        e1->data = e;
        e1->next = NULL;
        temp->next = e1;
    }
}


//===================================

void prePrint1(Node *n){
	Queue *q = NULL;
	while(n){
		printf("\t%d", n->data);
		if(n->fd) push(&q, n->fd);
		n=n->fg;
		if(n==NULL && q) n = pop(&q);
	}
}


int visited(Node** tab, int size, Node* n){
    if(!*tab) return 0;
    int i;
    for(i=0; i<size; i++)
        if(tab[i] == n) return 1;
    return 0;
}

void inPrint1(Node* n){
    Queue* q = NULL;
    while(1){
		if(n){
            push(&q, n);
            n = n->fg;
		}else{
            if(!q) break;
            n=pop(&q);
            printf("\t%d", n->data);
            n=n->fd;
		}
    }
}

void postPrint1(Node* n){
    Queue* q = NULL;
    while(n){
        if(!(n->visited))
            push(&q, n);
		if(n->fd && !n->fd->visited)
            push(&q, n->fd);
		n=n->fg;
		if(n==NULL && q){
            n = pop(&q);
            if((!n->fg || n->fg->visited) && (!n->fd || n->fd->visited)){
                printf("\t%d", n->data);
                n->visited = 1;
            }
		}
    }
}

void BFS(Node* n){
    Queue* q = NULL;

    if(n) push1(&q, n);
    else return;
    while(q){
        n=pop(&q);
        if(n->fg) push1(&q, n->fg);
        if(n->fd) push1(&q, n->fd);
        printf("\t%d", n->data);
    }
}
//======================================================================

void rotG(Node **n){
    Node* tmp=(*n)->fd;
    (*n)->fd = tmp->fg;
    Node *e = (Node*) malloc(sizeof(Node));
    *e = **n;
    tmp->fg = e;
    free(*n);
    *n=tmp;
}

void rotD(Node **n){
    Node* tmp=(*n)->fg;
    (*n)->fg = tmp->fd;
    Node *e = (Node*) malloc(sizeof(Node));
    *e = **n;
    tmp->fd = e;
    free(*n);
    *n=tmp;
}

void dblRotGD(Node **n){
    rotG(&((*n)->fg));
    rotD(n);
}
void dblRotDG(Node **n){
    rotD(&((*n)->fd));
    rotG(n);
}

//=================================================================

void calcHeight(Node *n){
    int d,g;
    d=g=0;
    if(!n) return;
    if(n->fd) d=height(n->fd);
    if(n->fg) g=height(n->fg);
    n->height = d-g;
}




//Equilibrium
void equil(Node** n){
    calcHeight(*n);
    if((*n)->height == 2){
        calcHeight((*n)->fd);
        if((*n)->fd->height == 1) rotG(n);
        if((*n)->fd->height == -1) dblRotDG(n);
    }else if((*n)->height == -2){
        calcHeight((*n)->fg);
        if((*n)->fg->height == -1) rotD(n);
        if((*n)->fg->height == 1) dblRotGD(n);
    }else return;
}

void equilAll(Node** n){
    if(!(*n)) return;
    if((*n)->fd) equilAll(&((*n)->fd));
    if((*n)->fg) equilAll(&((*n)->fg));
    equil(n);
}


void insert(Node** n, int data){
    Node* tmp=*n, **tmp1;

    if(!tmp){
         *n = createNode(data);
         return;
    }

    while(1){
        if(data == tmp->data) return;
        if(data > tmp->data)
            if(tmp->fd)
                tmp = tmp->fd;
            else break;
        else
            if(tmp->fg)
                tmp = tmp->fg;
            else break;
    }

    tmp1 = data > tmp->data ? &(tmp->fd) : &(tmp->fg);
    tmp = *tmp1;
    *tmp1 = createNode(data);
    tmp1 = (*tmp1)->data > data ? &((*tmp1)->fd) : &((*tmp1)->fg);
    *tmp1 = tmp;

    equilAll(n);
}
