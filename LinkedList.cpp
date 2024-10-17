#include "LinkedList.h"

LinkedList::LinkedList() {
    List = nullptr;
}

Nodeptr LinkedList::createNode(int x) {
    Nodeptr newNode = new Node;
    newNode->info = x;
    newNode->next = nullptr;
    newNode->pre = nullptr;
    return newNode;
}

void LinkedList::insertAtStart(int x) {
    Nodeptr p = createNode(x);
    p->next = List;
    if (List != nullptr) {
        List->pre = p;
    }
    List = p;
    cout << "Inserted " << x << " at the start." << endl;
}

int LinkedList::deleteAtStart() {
    if (List == nullptr) return -999;

    Nodeptr p = List;
    List = List->next;
    if (List != nullptr) {
        List->pre = nullptr;
    }
    int x = p->info;
    delete p;
    cout << "Deleted " << x << " from the start." << endl;
    return x;
}

void LinkedList::traverse() {
    if (List == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Current List: ";
    for (Nodeptr p = List; p != nullptr; p = p->next) {
        cout << p->info << " ";
    }
    cout << endl;
}

void LinkedList::insertAtEnd(int x) {
    Nodeptr p = createNode(x);
    if (List == nullptr) {
        List = p;
    }
    else {
        Nodeptr q = List;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
        p->pre = q;
    }
    cout << "Inserted " << x << " at the end." << endl;
}

int LinkedList::deleteAtEnd() {
    if (List == nullptr) return -999;

    if (List->next == nullptr)
        return deleteAtStart();

    Nodeptr q = List;
    while (q->next != nullptr) {
        q = q->next;
    }

    int x = q->info;
    q->pre->next = nullptr;
    delete q;
    cout << "Deleted " << x << " from the end." << endl;
    return x;
}

Nodeptr LinkedList::find(int x) {
    for (Nodeptr p = List; p != nullptr; p = p->next) {
        if (p->info == x) {
            return p;
        }
    }
    return nullptr;
}

void LinkedList::insertAfter(int x) {
    Nodeptr p = find(x);
    if (p == nullptr) {
        cout << "Node with value " << x << " not found." << endl;
        return;
    }

    Nodeptr newNode = createNode(0);
    cout << "Enter value to insert after " << x << ": ";
    cin >> newNode->info;

    newNode->next = p->next;
    newNode->pre = p;
    p->next = newNode;
    if (newNode->next != nullptr) {
        newNode->next->pre = newNode;
    }
    cout << "Inserted " << newNode->info << " after " << x << "." << endl;
}

int LinkedList::deleteAfter(int x) {
    Nodeptr p = find(x);
    if (p == nullptr || p->next == nullptr) {
        cout << "No node to delete after " << x << endl;
        return -999;
    }

    Nodeptr delNode = p->next;
    int data = delNode->info;
    p->next = delNode->next;
    if (delNode->next != nullptr) {
        delNode->next->pre = p;
    }
    delete delNode;
    cout << "Deleted " << data << " after " << x << "." << endl;
    return data;
}

void LinkedList::insertBefore(int x) {
    Nodeptr p = find(x);
    if (p == nullptr) {
        cout << "Node with value " << x << " not found." << endl;
        return;
    }

    Nodeptr newNode = createNode(0);
    cout << "Enter value to insert before " << x << ": ";
    cin >> newNode->info;

    newNode->next = p;
    newNode->pre = p->pre;

    if (p->pre != nullptr) {
        p->pre->next = newNode;
    }
    else {
        List = newNode;
    }

    p->pre = newNode;
    cout << "Inserted " << newNode->info << " before " << x << "." << endl;
}

int LinkedList::deleteNode(int x) {
    Nodeptr p = find(x);
    if (p == nullptr) {
        cout << "Node with value " << x << " not found." << endl;
        return -999;
    }

    if (p->pre != nullptr) {
        p->pre->next = p->next;
    }
    else {
        List = p->next;
    }
    if (p->next != nullptr) {
        p->next->pre = p->pre;
    }

    int data = p->info;
    delete p;
    cout << "Deleted node with value " << data << "." << endl;
    return data;
}
