#include <stdio.h>
#include <stdlib.h>
#include "tree.c"


int main()
{
    /*
    Node* e = createNode(0);
    Node* e1 = createNode(1);
    Node* e2 = createNode(2);
    Node* e3 = createNode(3);
    Node* e4 = createNode(4);
    Node* e5 = createNode(5);
    Node* e10 = createNode(10);
    Node* e16 = createNode(16);

    setFD(e,e2);
    setFG(e,e1);
    setFG(e1,e3);
    setFD(e1,e4);
    setFD(e2,e5);
    setFD(e5,e10);
    setFD(e10,e16);
    */



    Node* e0 = NULL;
    int i=10000;
    while(i--){
        insert(&e0, (rand()*time(NULL))%100000000);
        printf("\n: %d", i);
    }

    /*insert(&e0, 7);
    insert(&e0, 2);
    insert(&e0, 3);
    insert(&e0, 9);
    insert(&e0, 11);
    insert(&e0, 5);
    insert(&e0, 10);
    insert(&e0, 39);
    insert(&e0, 100);
    insert(&e0, 101);
    insert(&e0, 102);
    insert(&e0, 103);
    insert(&e0, 107);
    insert(&e0, 108);*/

    /*
    printf("\npostfixe recursive :\n");
    postPrint(e0);
    printf("\npostfixe iteratif :\n");
    postPrint1(e0);

    printf("\ninfixe recursive :\n");
    inPrint(e0);
    printf("\ninfixe iteratif :\n");
    inPrint1(e0);
    /*
    printf("\nprefixe recursive :\n");
    prePrint(e0);
    printf("\nprefixe iteratif :\n");
    prePrint1(e0);

    printf("\nBFS : \n");
    BFS(e0);
    */

    printf("\n\n\n\n height : %d", height(e0));
    printf("\n\n\n\n size : %d", size(e0));
    printf("\n");

    //BFS(e0);

    /*
    printf("\nheight before : %d", height(e0));
    printf("\n");
    equilAll(&e0);
    printf("\n");
    postPrint(e0);
    printf("\n");
    inPrint(e0);
    printf("\n");
    printf("\nheight after : %d", height(e0));
    */
    return 0;
}
