#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"
#include "move.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void insertFirst(LinkedList* list, void* data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void* removeFirst(LinkedList* list) {
    if (list->head == NULL) {
        return NULL;
    }
    Node* nodeToRemove = list->head;
    void* data = nodeToRemove->data;
    list->head = nodeToRemove->next;
    free(nodeToRemove);
    return data;
}

void destroyLinkedList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

