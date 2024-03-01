#ifndef MOVE_H
#define MOVE_H

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

LinkedList* createLinkedList();

void insertFirst(LinkedList* list, void* data);

void* removeFirst(LinkedList* list);

void destroyLinkedList(LinkedList* list);

#endif
