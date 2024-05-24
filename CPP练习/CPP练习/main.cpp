//
//  main.cpp
//  CPP练习
//
//  Created by 张旭洋 on 2024/2/6.
//

//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//char toUpper(char letter) {
//    return letter - ('a' - 'A');
//}
//
//bool isUpper(char letter) {
//    return (letter >= 'A' && letter <= 'Z') ? 1 : 0;
//}
//
//typedef struct ListNode {
//    int val;
//    struct ListNode* next;
//    ListNode(int x) : val(x), next(nullptr) {}
//} ListNode;
//
//void insertNodeAtTail(ListNode* dummyNode, int val) {
//    ListNode* move = dummyNode;
//    while (move->next) {
//        move = move->next;
//    }
//    
//    ListNode* newNode = new ListNode(val);
//    move->next = newNode;
//}
//
//bool insertNode(ListNode* dummyNode, int index, int val) {
//    if (index <= 0) return false;
//    ListNode* move = dummyNode;
//    while (--index) {
//        move = move->next;
//        if (!move) return false;
//    }
//    ListNode* newNode = new ListNode(val);
//    newNode->next = move->next;
//    move->next = newNode;
//    return true;
//}
//
//void printList(ListNode* dummyNode) {
//    ListNode* move = dummyNode;
//    while (move->next) {
//        move = move->next;
//        cout << move->val;
//        if (move->next) {
//            cout << ' ';
//        } else {
//            cout << endl;
//        }
//    }
//}
//
//bool deleteNode(ListNode* dummyNode, int index) {
//    if (index < 1) return false;
//    ListNode* move = dummyNode;
//    while (--index) {
//        move = move->next;
//        if (!move) return false;
//    }
//    if (!move->next) return false;
//    ListNode* tmp = move->next;
//    move->next = move->next->next;
//    delete tmp;
//    return true;
//}
//
//int main(int argc, const char * argv[]) {
////    int a, b;
////    while (cin >> a >> b) {
////        cout << a + b << endl;
////    }
////    int n;
////    cin >> n;
////    getchar();
////
////
////    while (n--) {
////        string s;
////        getline(cin, s);
////        int fast = 0, slow = 0;
////        unsigned long len = s.size();
//////        printf("%ld\n", len);
////        while (fast < len) {
////            while (s[fast] != ' ' && fast < len) {
////                fast++;
//////                printf("fast1 = %d\n", fast);
////            }
////
////            char ch = s[slow];
////            if (isUpper(ch)) {
////                cout << ch;
////            } else {
////                cout << toUpper(ch);
////            }
////
////            if (fast == len) {
////                cout << endl;
////                break;
////            }
////
////            while (s[fast] == ' ' && fast < len) {
////                fast++;
//////                printf("fast2 = %d\n", fast);
////            }
////
////            slow = fast;
////        }
////
////    }
//    
////    int n;
////    cin >> n;
////    while (n--) {
////        string s;
////        getline(cin, s);
////
////        for (unsigned long i = 0; i < s.size() - 1; i += 2) {
////            swap(s[i], s[i + 1]);
////        }
////        cout << s << endl;
////
////    }
//    
////    int k;
////    cin >> k;
////    
////    ListNode* dummyNode = new ListNode(0);
////    int val;
////    while (k--) {
////        cin >> val;
////        insertNodeAtTail(dummyNode, val);
////    }
//////    printList(dummyNode);
////    
////    
////    int s;
////    cin >> s;
//////    while (s--) {
////    for (int i = 0; i < s; ++i) {
////        int index, val;
////        cin >> index >> val;
////        if (insertNode(dummyNode, index, val)) {
////            printList(dummyNode);
////        } else {
////            cout << "Insertion position is invalid." << endl;
////        }
////    }
////    
////    int indexForDelete, l;
////    cin >> l;
////    while (l--) {
////        cin >> indexForDelete;
////        if (deleteNode(dummyNode, indexForDelete)) {
////            printList(dummyNode);
////        } else {
////            cout << "Deletion position is invalid." << endl;
////        }
////        
////    }
//    
////    int n;
////    while (cin >> n && n--) {
////        string s;
////        cin >> s;
////        int hash[26] = {0};
////        for (unsigned long i = 0; i < s.size(); ++i) {
////            hash[s[i] - 97]++;
////        }
////        
////        int max = 0;
////        for (int i = 0; i < 26; ++i) {
////            if (hash[i] > max) {
////                max = hash[i];
////            }
////        }
////        cout << max << endl;
////    }
//    
////    int s;
////    cin >> s;
////    
////    while (s--) {
////        int n;
////        cin >> n;
////        map<int, int> mMap;
////        
////        while (n--) {
////            int k, d;
////            cin >> k >> d;
////            mMap[k] = d;
////        }
////        int k;
////        cin >> k;
////        int flag = 0;
////        for (const pair<int, int>& kv : mMap) {
////            if (kv.second == k) {
////                flag = 1;
////                cout << kv.first << endl;
////                break;
////            }
////        }
////        if (!flag) {
////            cout << "Can't open the door." << endl;
////        }
////    }
//    
//    
//    
//    return 0;
//}

#include <c++/v1/bits/stdc++.h>
//#define int long long
using namespace std;
using ll = long long;
//signed = signed int; signed main(void);

//确定N的大小
const int N = 1e5 + 9;

//开数组，全局数组自动初始化为0
//若是局部数组，用的是栈空间（2M～4M），且不会初始化
int a[N], prefix[N], diff[N];
bool category[N];
int ani[N];


bool isNumber(char ch) {
    return (ch >= '0' && ch <= '9') ? 1 : 0;
}

int main(void) {
//    //取消同步流？？？
//    static_cast<void>(ios::sync_with_stdio(0)), static_cast<void>(cin.tie(0)), cout.tie(0);
//    //注意不要使用cout << endl;改用cout << '\n';
//    //endl：换行后会强制刷新缓冲区
//    
#pragma mark P8772 [蓝桥杯 2022 省 A] 求和
//    int n;
//    cin >> n;
//    
//    for (int i = 1; i <= n; ++i) {
//        cin >> a[i];
//    }
//    
//    for (int i = 1; i <= n; ++i) {
//        prefix[i] = prefix[i - 1] + a[i];
//    }
//    
//    int ans = 0;
//    for (int i = 1; i < n; ++i) {
//        ans += a[i] * (prefix[n] - prefix[i]);
//    }
//        
//    cout << ans << 'n';
    
#pragma mark 8706 [蓝桥杯 2020 省 AB1] 解码
//    string s;
//    
//    cin >> s;
//    
//    int fast = 0, slow = 0;
//    unsigned long len = s.size();
//    while (fast < len) {
//        
//        while (!isNumber(s[fast]) && fast < len) fast++;
//        if (fast != len) {
//            while (slow <= fast - 1) cout << s[slow++];
//            slow--;
//            
//            int amount = s[fast] - '0';
//            while (--amount) cout << s[slow];
//            fast++;
//            slow = fast;
//        } else {
//            while (slow < fast) {
//                cout << s[slow++];
//            }
//        }
//    }
    
    
#pragma mark 鼠鼠我鸭
//    int T;
//    cin >> T;
//    
//    while (T--) {
//        int n;
//        cin >> n;
//        
//        
//        for (int i = 1; i <= n; ++i) cin >> category[i];
//        for (int i = 1; i <= n; ++i) cin >> ani[i];
//        
//        //计算prefix
//        int essential = 0;
//        for (int i = 1; i <= n; ++i) {
//            if (category[i]) {
//                essential += ani[i];
//                prefix[i] = prefix[i - 1] - ani[i];
//            } else {
//                prefix[i] = prefix[i - 1] + ani[i];
//            }
//        }
//        
//        int max = 0;
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= i - 1; ++j) {
//                int tmp = prefix[i] - prefix[j - 1];
//                if (max < tmp) max = tmp;
//            }
//        }
//        
//        if (max <= 0) {
//            cout << essential << '\n';
//        } else {
//            cout << essential + max << '\n';
//        }
//        /*
//         2
//         3
//         0 0 0
//         1 2 3
//         output: 6
//         4
//         0 1 0 0
//         2 5 6 5
//         output: 16
//         */
//    }
    
    
    
    
    
    
    
    return 0;
}
