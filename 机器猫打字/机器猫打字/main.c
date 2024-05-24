//
//  main.c
//  机器猫打字
//
//  Created by 张旭洋 on 2023/2/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

int main(void) {
    printf("%d", strlen("abcd\0ed\0g"));
    return 0;
}

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = n;
    //**returnColumnSizes = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    int** matrix = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; ++i) {
        matrix[i] = malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    int loop = n / 2;  //循环圈数
    int startx = 0, starty = 0;  //每圈起始坐标
    int count = 1;  //所赋的值
    int mid = n / 2;  //若阶数为奇数，需给中间位置单独赋值
    int offset = 1;  //控制每行每列遍历次数
    while(loop--) {
        int i = startx;  //行数
        int j = starty;  //列数

        while(j < n - offset) matrix[startx][j++] = count++;
        while(i < n - offset) matrix[i++][j] = count++;
        while(j > startx) matrix[i][j--] = count++;
        while(i > starty) matrix[i--][j] = count++;

        startx++;
        starty++;
        offset++;
        }
        if(n % 2 != 0) matrix[mid][mid] = count;

        return matrix;
}
