////
////  main.m
////  OC Superior
////
////  Created by 张旭洋 on 2024/3/14.
////
//
//#import <Foundation/Foundation.h>
//
////int (^blockName) (int);
//
////int main(int argc, const char * argv[]) {
//////    @autoreleasepool {
//////        id array = [[NSMutableArray alloc] init];
//////        
//////        void (^blockName) (void) = ^{
//////            id object = [[NSObject alloc] init];
//////            [array addObject: object];
//////        };
//////        
//////        blockName();
//////    }
////    
////    const char* text = "hello";
////    
////    void (^blockName) (void) = ^{
////        printf("%c\n", text[2]);
////    };
////    
////    blockName();  //l
////    
////    return 0;
////}
//
//int main(void) {
//    
////    void (^blockName) (void) = ^{
////        printf("Block\n");
////    };
////    blockName();
//    
//    
//    
//    
//    
//    return 0;
//}

#include <stdio.h>
#include <string.h>
//#include <ctype.h>

_Bool isUpper(char letter) {
    return ((letter >= 'A') && (letter <= 'Z')) ? 1 : 0;
}

_Bool isLower(char letter) {
    return ((letter >= 'a') && (letter <= 'z')) ? 1 : 0;
}

_Bool isNumber(char letter) {
    return ((letter >= '0') && (letter <= '9')) ? 1 : 0;
}

char toUpper(char letter) {
    return letter - ('a' - 'A');
}

char toLower(char letter) {
    return letter + ('a' - 'A');
}



int main(void) {
//    int x, y;
//    scanf("%d", &x);
////    getchar();
//    char a[500][500];
//    for (int i = 0; i < x; ++i) {
//        gets(a[i]);
////        getchar();
//    }
//    for (int i = 0; i < x; ++i) {
//        puts(a[i]);
//    }
//    return 0;
    
//    char str[6010] = {0};
//    printf("%c", str[4]);
    
    char str[6000];
    gets(str);
    int fast = strlen(str) - 1;
    int slow = strlen(str) - 1;
    
    while (fast > 0) {
        while (fast > 0 && str[fast] != ' ') {
            fast--;
        }
        
        if (isUpper(str[fast + 1]) || isLower(str[fast + 1])) {
            
            if (fast > 0) {
                if (isUpper(str[fast + 1])) {
                    for (int i = fast + 1; i <= slow; i++) {
                        str[i] = toLower(str[i]);
                        printf("%c", str[i]);
                    }
                } else {
                    for (int i = fast + 1; i <= slow; ++i) {
                        str[i] = toUpper(str[i]);
                        printf("%c", str[i]);
                    }
                }
            } else {
                if (isUpper(str[fast])) {
                    for (int i = 0; i <= slow; ++i) {
                        str[i] = toLower(str[i]);
                        printf("%c", str[i]);
                    }
                } else {
                    for (int i = 0; i <= slow; ++i) {
                        str[i] = toUpper(str[i]);
                        printf("%c", str[i]);
                    }
                }
            }
            
//            if (!fast) {
//                if (isUpper(str[fast])) {
//                    for (int i = 0; i < slow; ++i) {
//                        str[i] = toLower(str[i]);
//                        printf("%c", str[i]);
//                    }
//                } else {
//                    for (int i = 0; i < slow; ++i) {
//                        str[i] = toUpper(str[i]);
//                        printf("%c", str[i]);
//                    }
//                }
//            }
            
        } else {
            if (fast > 0) {
                for (int i = slow; i > fast; --i) {
                    printf("%c", str[i]);
                }
            } else {
                for (int i = slow; i >= fast; --i) {
                    printf("%c", str[i]);
                }
            }
        }
        
        if (fast > 0) {
            printf(" ");
        }
        fast--;
        slow = fast;
    }
    
    return 0;
    
}

