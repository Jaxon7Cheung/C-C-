//
//  main.c
//  二分法搜索
//
//  Created by 张旭洋 on 2022/11/24.
//

#include <stdio.h>

int binarySearch(int * nums,int target,int left,int right) {
    if(left > right) return -1;
    int mid = (left + right) / 2;
    if(nums[mid] == target) return mid;
    if(nums[mid] > target) {
        return binarySearch(nums/*本身就是指针，不用取地址*/,target,left,mid - 1);
    } else {
        return binarySearch(nums,target,mid + 1,right);
    }
}
int search(int * nums,int sumsSize,int target) {
        return binarySearch(nums,target,0,sumsSize - 1);
    }
