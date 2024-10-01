#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int data;
    struct node * next;
} node;

node * createList(int data) {
    node * newNode = (node *)malloc(sizeof(createNode));
    if (newNode == NULL) {
        printf("Error creating the list.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(node * head, int data) {
    node * newNode = createList(data);
    while(head->next != NULL) {
        head = head->next;
    }
    head->next = newNode;
}

void removeNode(node ** head, int data){
    node * temp = (*head);
    node * beforeTemp = temp;
    
    temp = temp->next;

    // check if head->data is the data to be deleted
    // if it is then set head to head->next then free temp
    if(beforeTemp->data == data){
        (*head) = (*head)->next;
        free(beforeTemp);
    }
    // loop through the list to find the data to be deleted
    while(temp != NULL){
        if(temp->data == data){
            // closes up the gap in the list
            beforeTemp->next = temp->next;
            free(temp);
            break;
        }
        beforeTemp = temp;
        temp = temp->next;
    }

}

void deleteList(node ** head) {
    node * temp = (*head);
    node * next;
    while(temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    (*head) = NULL;
}

void printList(node * head) {
    int i = 1;
    while(head->next != NULL) {
        printf("%d: %d", i,head->data);
        head = head->next;
    }
    
}
