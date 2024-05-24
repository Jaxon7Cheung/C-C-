//
//  main.c
//  队列练习（顺序表）
//
//  Created by 张旭洋 on 2023/1/4.
//

#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int * array;
    int capacity;
    int front,rear;
};
typedef struct Queue * ArrayQueue;

_Bool initQueue(ArrayQueue queue);
_Bool offerQueue(ArrayQueue queue,int element);
void printQueue(ArrayQueue queue);
_Bool isEmpty(ArrayQueue queue);
int pollQueue(ArrayQueue queue);

int main(void) {
    struct Queue queue;
    initQueue(&queue);
    for (int i = 0; i < 6; ++i) offerQueue(&queue, i * 100);
    printQueue(&queue);printf("\n");
    while (!isEmpty(&queue)) printf("%d ", pollQueue(&queue));
}

_Bool initQueue(ArrayQueue queue) {
    queue->array = malloc(sizeof(int) * 10);
    if(queue->array == NULL) return 0;
    queue->capacity = 10;
    queue->front = queue->rear = 0;
    return 1;
}

_Bool offerQueue(ArrayQueue queue,int element) {
    if((queue->rear + 1) % queue->capacity == queue->front) return 0;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;
    return 1;
}

_Bool isEmpty(ArrayQueue queue) {
    return queue->front == queue->rear;
}

int pollQueue(ArrayQueue queue) {
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}

void printQueue(ArrayQueue queue) {
    printf("<<<");
    int i = queue->front;
    do {
        i = (i + 1) % queue->capacity;
        printf("%d ",queue->array[i]);
    } while(i != queue->rear);
    printf("<<<");
}
