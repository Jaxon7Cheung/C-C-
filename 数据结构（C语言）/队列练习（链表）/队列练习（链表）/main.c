//
//  main.c
//  队列练习（链表）
//
//  Created by 张旭洋 on 2023/1/4.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int element;
    struct ListNode * next;
};
typedef struct ListNode * Node;
struct Queue {
    Node front,rear;
};
typedef struct Queue * LinkedQueue;

_Bool initQueue(LinkedQueue queue);
_Bool offerQueue(LinkedQueue queue,int element);
int pollQueue(LinkedQueue queue);
_Bool isEmpty(LinkedQueue queue);
void printQueue(LinkedQueue queue);

int main(void) {
    struct Queue dui;
    initQueue(&dui);
    for (int i = 0; i < 6; ++i) offerQueue(&dui, i * 100);
    printQueue(&dui);printf("\n");
    while (!isEmpty(&dui)) printf("%d ", pollQueue(&dui));
}

_Bool  initQueue(LinkedQueue queue) {
    Node node = malloc(sizeof(struct ListNode));
    if(node == NULL) return 0;
    node->next = NULL;
    queue->front = queue->rear = node;
    return 1;
}

_Bool offerQueue(LinkedQueue queue,int element) {
    Node node = malloc(sizeof(struct ListNode));
    if(node == NULL) return 0;
    node->next = NULL;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

int pollQueue(LinkedQueue queue) {
    int e = queue->front->next->element;
    Node tmp = queue->front->next;
    queue->front->next = queue->front->next->next;
    if(tmp == queue->rear) queue->rear = queue->front;
    free(tmp);
    return e;
}

_Bool isEmpty(LinkedQueue queue) {
    return queue->front == queue->rear;
}

void printQueue(LinkedQueue queue) {
    printf("<<<");
    Node node = queue->front->next;
    while(1) {
        printf("%d ",node->element);
        if(node == queue->rear) {
            break;
        } else {
            node = node->next;
        }
    }
    printf("<<<");
}
