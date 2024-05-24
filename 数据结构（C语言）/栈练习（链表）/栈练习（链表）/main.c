//
//  main.c
//  栈练习（链表）
//
//  Created by 张旭洋 on 2023/1/4.
//

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int element;
    struct Stack * next;
};
typedef struct Stack * Node;

void initStack(Node head);
_Bool pushStack(Node head,int element);
_Bool isEmpty(Node head);
int popStack(Node head);
void printStack(Node head);

int main(void) {
    struct Stack zhan;
    initStack(&zhan);
    for (int i = 0; i < 6; ++i)
        pushStack(&zhan, i * 100);
    printStack(&zhan);
    while (!isEmpty(&zhan)) printf("%d ", popStack(&zhan));
    printf("\n");
}

void initStack(Node head) {
    head->next = NULL;
}

_Bool pushStack(Node head,int element) {
    Node node = malloc(sizeof(struct Stack));
    if(node == NULL) return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

_Bool isEmpty(Node head) {
    return head->next == NULL;
}

int popStack(Node head) {
    Node top = head->next;
    head->next = head->next->next;
    int e = top->element;
    free(top);
    return e;
}

void printStack(Node head) {
    head = head->next;
    while(head) {
        printf("%d ",head->element);
        head = head->next;
    }
    printf("|\n");
    
}

