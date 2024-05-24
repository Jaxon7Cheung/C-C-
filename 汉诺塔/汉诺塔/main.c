//
//  main.c
//  汉诺塔
//
//  Created by 张旭洋 on 2022/12/6.
//

#include <stdio.h>

void move(char start, char end, int n){   //用于打印移动操作到控制台，start是起始柱子，end是结束柱子，n是第n个圆盘
    printf("第%d个圆盘：%c --> %c\n", n, start, end);
}

void hanoi(char a, char b, char c, int n){  //刚进来的时候，B作为中间柱子，C作为目标柱子，要移动A上的n个圆盘到C去
    if(n == 1) {
        move(a, c, n);   //无论a,b,c如何变换，通过递归，最后都会变成一个n = 1的问题，直接移动就完事了
    } else{
        hanoi(a, c ,b, n - 1);  //首要目标是先把上面n-1个圆盘全部放到B去，这里就变换一下，让B作为目标柱子，C作为中间
        move(a, c, n);   //现在A上只剩下一个最大的圆盘了，接着把A最下方的一个圆盘移到C去
        hanoi(b, a, c, n - 1);   //最后需要把B上的全部搬到C上去，这里就可以以C为目标柱子，A为中间柱子
    }
}

int main(void) {
    hanoi('A','B','C',4);
}
