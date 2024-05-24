//
//  main.c
//  字符串匹配
//
//  Created by 张旭洋 on 2022/12/6.
//

#include <string.h>
#include <stdio.h>

int main(void) {
    char arr_1[64], arr_2[64];
    gets(arr_1);
    gets(arr_2);
    unsigned long len1 = strlen(arr_1), len2 = strlen(arr_2);
    _Bool flag = 1;
    for (int i = 0; i < len1; ++i) {
        flag = 1;
        for (int j = 0; j < len2; j ++) {
            if(arr_1[i + j] != arr_2[j]) {
                flag = 0;
                break;
            }
        }
        if(flag) break;
    }
    puts(flag ? "包含" : "不包含");
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//    char str1[64], str2[64];
//    gets(str1);
//    gets(str2);
//    unsigned long len1 = strlen(str1),len2 = strlen(str2);
//
//    _Bool flag = 1; //表示flag = 1正确
//    for (int i = 0; i < len1; ++i) {
//        flag = 1;
//        for (int j = 0; j < len2; ++j) {
//            if (str1[i + j] != str2[j]) {
//                flag = 0;
//                break;
//            }
//        }
//        if (!flag) break;
//    }
//    puts(flag ? "不包含" : "包含");
}
