//
//  main.c
//  链表练习
//
//  Created by 张旭洋 on 2022/11/24.
//


#include <stdio.h>  //链表
#include <stdlib.h>

struct NodeList {
    int element;
    struct NodeList * next;
};
typedef struct NodeList * Node;
void initNode(Node head);
_Bool insertNode(Node head,int element,int index);
_Bool deleteNode(Node head,int index);
int getNode(Node head,int index);
int findNode(Node head,int element);
int sizeNode(Node head);
void printNode(Node head);

int main(void) {
    struct NodeList biao;
    initNode(&biao);
    for (int i = 0; i < 5; ++i) {
        insertNode(&biao, i * 50, i + 1);
    }
    deleteNode(&biao,3);
    printNode(&biao);
    printf("%d\n",getNode(&biao, 3));
    printf("%d\n",sizeNode(&biao));
    printf("%d\n",findNode(&biao,150));
}

void initNode(Node head) {
    head->next = NULL;
}

_Bool insertNode(Node head,int element,int index) {
    if(index < 1) return 0;
    while(--index) {
        head = head->next;
        if(head == NULL) return 0;
    }

    Node node = malloc(sizeof(Node));
    if(node == NULL) return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

_Bool deleteNode(Node head,int index) {
    if(index < 1) return 0;
    while(--index) {
        head = head->next;
        if(head == NULL) return 0;
    }
    if(head->next == NULL) return 0;

    Node tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return 1;
}

int  getNode(Node head,int index) {
    if(index < 1) return 0;
    do {
           head = head->next;
           if(head == NULL) return 0;
       } while(--index); //找的就是结点
       return head->element;
}

int findNode(Node head,int element) {
    head = head->next;
    int i = 1;
    while(head) {
        if(head->element == element) return i;
        head = head->next;
        i++;
    }
    return -1;
}

int sizeNode(Node head) {
    int i = 0;
    while(head->next) {
        head = head->next;
        i++;
    }
    return i;
}

void printNode(Node head) {
    while(head->next) {
        head = head->next;
        printf("%d ",head->element);
    }
    printf("\n");
}
