//
//  main.c
//  上学迟到
//
//  Created by 张旭洋 on 2022/11/25.
//

#include <stdio.h>

int main() {
    int v,s,t;
    scanf("%d %d",&s,&v);
    t = (s % v == 0)? s / v + 10 : s / v + 11;
    //t0 = (float)s / v + 10.0;
    if(t < 8 * 60) {
        t = 8 * 60 - t;
        //printf("%d:%d",(int)(t / 60),t % 60);
    } else if(t == 8 * 60) {
        printf("00:00");
        return 0;
    } else {
        t = 32 * 60/*简单地算出用时*/ - t;
        //printf("%d:%d",(int)((t-480) / 60),(t - 480) % 60);
        }
    printf("%02d:%02d",t / 60,t % 60);  //题目要求必须输出两位，做题时未审清题目
    }
