//
//  main.c
//  旋转矩阵
//
//  Created by 张旭洋 on 2022/12/6.
//

#include<stdio.h>
#define n 4
int main()
{
    int a[n][n],b[n][n];
    int i,j;
    printf("输入矩阵a:\n");
    for(i=0;i<n;i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("旋转后的矩阵:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[j][i];
        }
    }
    for(i = 0;i<n;i++) {
        for(j = n-1;j>=0;j--) {
            if(j==n-1) printf("%d ",b[i][j]);
            else printf("%d ",b[i][j]);
        }
        printf("\n");
    }

}
