//
//  main.c
//  栈练习（顺序表）
//
//  Created by 张旭洋 on 2023/1/4.
//

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int * array;
    int capacity;
    int top;
};
typedef struct Stack * ArrayStack;

_Bool initStack(ArrayStack stack);
_Bool pushStack(ArrayStack stack,int element);
_Bool isEmpty(ArrayStack stack);
int popStack(ArrayStack stack);
void printStack(ArrayStack stack);

int main(void) {
    struct Stack zhan;
    initStack(&zhan);
    for (int i = 0; i < 6; ++i) {
        pushStack(&zhan, i * 10);
    }
    printStack(&zhan);
    while (!isEmpty(&zhan)) printf("%d ", popStack(&zhan));
    printf("\n");
}

_Bool initStack(ArrayStack stack) {
    stack->array = malloc(sizeof(int) * 10);
    if(stack->array == NULL) return 0;
    stack->capacity = 10;
    stack->top = -1;
    return 1;
}

_Bool pushStack(ArrayStack stack,int element) {
    if(stack->top + 1 == stack->capacity) {
        int newCapacity = stack->capacity + (stack->capacity >> 1);
        int * newArray = realloc(stack->array, sizeof(int) * newCapacity);
        if(newArray == NULL) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->array[++stack->top] = element;
    return 1;
}

_Bool isEmpty(ArrayStack stack) {
    return stack->top == -1;
}

int popStack(ArrayStack stack) {
    return stack->array[stack->top--];
}

void printStack(ArrayStack stack) {
    printf("| ");
        for (int i = 0; i < stack->top + 1; ++i)
            printf("%d ", stack->array[i]);
    printf("\n");
}
