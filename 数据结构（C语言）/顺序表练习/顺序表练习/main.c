//
//  main.c
//  顺序表练习
//
//  Created by 张旭洋 on 2022/12/28.
//

#include <stdio.h>
#include <stdlib.h>

struct List {
    int * array;
    int capacity;
    int size;
};
typedef struct List * ArrayList;

_Bool initList(ArrayList list);
void printList(ArrayList list);
_Bool insertList(ArrayList list,int element,int index);
_Bool deleteList(ArrayList list,int index);
int sizeList(ArrayList list);
int findList(ArrayList list,int index);
int getList(ArrayList list,int element);

int main() {
    struct List list;
    if(initList(&list)) {
        for (int i = 0; i < 21; i++)
            insertList(&list, i * 10, i);
        deleteList(&list, 3);
        printList(&list);
        printf("%d\n",sizeList(&list));
        printf("%d\n",findList(&list, 6));
        printf("%d\n",getList(&list, 60));
    } else {
        return 0;
    }
}

_Bool initList(ArrayList list) {
    list->array = malloc(sizeof(int) * 10);
    if(list->array == NULL) return 0;
    list->capacity = 10;
    list->size = 0;
    return 1;
}

void printList(ArrayList list) {
    for (int i = 0; i < list->size; ++i) {
        printf("%d ",list->array[i]);
    }
    printf("\n");
}

_Bool insertList(ArrayList list,int element,int index) {
    if(index < 1 || index > list->size + 1) {
        int newCapacity = list->capacity + (list->capacity >> 1);
        int * newArray = realloc(list->array, sizeof(int) * newCapacity);
        if(newArray == NULL) return 0;
        list->capacity = newCapacity;
        list->array = newArray;
        return 1;
    }
    for (int i = list->size; i > index - 1; i--)
        list->array[i] = list->array[i - 1];
    list->array[index - 1] = element;
    list->size++;
    return 1;
}

_Bool deleteList(ArrayList list,int index) {
    if(index < 1 || index > list->size) return 0;
    for (int i = index - 1; i < list->size - 1; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    return 1;
}

int sizeList(ArrayList list) {
    return list->size;
}

int findList(ArrayList list,int index) {
    if(index < 1 || index > list->size) return 0;
    return list->array[index - 1];
}

int getList(ArrayList list,int element) {
    for (int i = 0; i < list->size; ++i)
        if(list->array[i] == element) return i + 1;
    return -1;
}
