//
//  main.c
//  实现字符串函数
//
//  Created by 张旭洋 on 2022/12/6.
//

#include <stdio.h>  //实现字符串函数练习

int mystrlen(char *);
void mystrcpy(char *,char *);
void mystrcat(char *,char *);
int mystrcmp(char *,char *);

int main() {
    char str1[] = "awfesgd";
    char str2[] = "sdff";

    printf("%d\n",mystrlen(str1));

    mystrcpy(str1,str2);
    printf("%s\n",str1);

    mystrcat(str1,str2);
    printf("%s\n",str1);

    printf("%d",mystrcmp(str1,str2));
}

int mystrlen(char arr[]) {
    int i = 0,j = 0;
    while(arr[i] != '\0') {
        j++;
        i++;
    }
    return j;
}

void mystrcpy(char arr1[],char arr2[]) {
    int i = 0,j = 0;
    while(arr2[j] != '\0') {
        arr1[i] = arr2[j];
        i++;
        j++;
    }
    arr1[i] = '\0';
}

void mystrcat(char arr1[],char arr2[]) {
    int i = 0,j = 0;
    while(arr1[i] != '\0') i++;
    while(arr2[j] != '\0') {
        arr1[i] = arr2[j];
        i++;
        j++;
    }
    arr1[i] = '\0';
}

int mystrcmp(char arr1[],char arr2[]) {
    int i = 0,j = 0;
    while(arr1[i] == arr2[j] && arr1[i] != '\0') {
        i++;
        j++;
    }
    if(arr1[i] > arr2[j]) {
        return 1;
    } else if(arr1[i] < arr2[j]) {
        return -1;
    } else return 0;
}
