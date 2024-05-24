//
//  main.c
//  快速排序
//
//  Created by 张旭洋 on 2022/11/24.
//

#include <stdio.h>
#include <string.h>

void quick(int * arr,int left,int right) {
    if(left >= right) return;
    
    int l = left,r = right,standard = arr[left];
    while(l < r) {
        while(l < r && standard <= arr[r]) r--;
        arr[l] = arr[r];
        while(l < r && standard >= arr[l]) l++;
        arr[r] = arr[l];
    }
    arr[l] = standard;
    
    quick(arr, left, r - 1);
    quick(arr, r + 1, right);
}

void quickSort(int* arr,int left,int right) {
    if(left > right) return;
    int l,r,standard;
    l = left;
    r = right;
    standard = arr[left];
    
    while(l != r) {
        while(l < r && arr[r] >= standard) r--;
        while(l < r && arr[l] <= standard) l++;
        
        if(l < r) {
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
        }
    }
    arr[left] = arr[l];
    arr[l] = standard;
    
    quickSort(arr, left, l - 1);
    quickSort(arr, l + 1, right);
}

int main(void) {
    int str[8] = {7,9,6,4,2,3,8,8};
    quick(str,0,7);
    for (int i = 0; i < 8; ++i) {
        printf("%d ",str[i]);
    }
}
