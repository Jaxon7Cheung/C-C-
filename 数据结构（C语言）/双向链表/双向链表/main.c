//
//  main.c
//  双向链表
//
//  Created by 张旭洋 on 2022/12/29.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int element;
    struct ListNode * next;
    struct ListNode * prev;
};
typedef struct ListNode * Node;

void initNode(Node head);
_Bool insertNode(Node head,int element,int index);
_Bool deleteNode(Node head,int index);
int sizeNode(Node head);
int findNode(Node head,int index);
int getNode(Node head,int element);

int main(void) {
    struct ListNode head;
    initNode(&head);
    for (int i = 1; i <= 5; ++i)
        insertNode(&head, i * 100, i);
    deleteNode(&head, 4);
    insertNode(&head, 666, 4);
    
    Node node = &head;
    do {
        node = node->next;
        printf("%d->",node->element);
    } while(node->next != NULL);
    printf("\n");
    do {
        printf("%d->",node->element);
        node = node->prev;
    } while(node->prev != NULL);
}

void initNode(Node head) {
    head->next = head->prev = NULL;
}

_Bool insertNode(Node head,int element,int index) {
    if(index < 1) return 0;
    while(--index) {
        head = head->next;
        if(head == NULL) return 0;
    }
    
    Node node = malloc(sizeof(struct ListNode));
    node->element = element;
    if(head->next) {
        node->next = head->next;
        head->next->prev = node;
    } else {
        node->next = NULL;
    }
    head->next = node;
    node->prev = head;
    return 1;
}

_Bool deleteNode(Node head,int index) {
    if(index < 1) return 0;
    while (--index) {
        head = head->next;
        if(head == NULL) return 0;
    }
    if(head->next == NULL) return 0;
    
    Node tmp = head->next;
    if(head->next->next) {
        head->next->next->prev = head;
        head->next = head->next->next;
    } else {
        head->next = NULL;
    }
    free(tmp);
    return 1;
}


