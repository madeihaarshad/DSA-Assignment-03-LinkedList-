#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

typedef struct Node* Nodeptr;

struct Node {
    int info;
    Nodeptr next;
    Nodeptr pre;
};

class LinkedList {
private:
    Nodeptr List;

    Nodeptr createNode(int x);

public:
    LinkedList();
    void traverse();
    Nodeptr find(int);
    void insertAtStart(int);
    int deleteAtStart();
    void insertAtEnd(int);
    int deleteAtEnd();
    void insertAfter(int);
    int deleteAfter(int);
    void insertBefore(int);
    int deleteNode(int);
};

#endif 
