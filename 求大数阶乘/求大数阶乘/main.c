//
//  main.c
//  求大数阶乘
//
//  Created by 张旭洋 on 2022/12/1.
//

#include <stdio.h>  //求大数阶乘
#include <string.h>

int main() {
    int n;
    scanf("%d",&n);
    int a[10000];
    a[0] = 1;
    int tmp = 0;
    int jw = 0;
    int ws = 1;
    for (int i = 1; i <= n ; ++i) {
        for (int j = 0; j < ws; ++j) {
            tmp = a[j] * i + jw;
            a[j] = tmp % 10;
            jw = tmp / 10;
        }
        while(jw != 0) {
            a[ws] = jw % 10;
            jw /= 10;
            ws++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        
    }
    for (int i = ws - 1; i >= 0; --i) {
        printf("%d",a[i]);
    }
}
