//
//  main.c
//  n个结点构造不同二叉树的种数
//
//  Created by 张旭洋 on 2023/3/13.
//

#include <stdio.h>
#include <stdlib.h>

//int main(int argc, const char * argv[]) {
////    int n;
////    scanf("%d", &n);
////
////    int dp[n + 1];
////    dp[0] = 1;
////    dp[1] = 1;
////    for (int i = 2; i <= n; ++i) {
////        dp[i] = 0;
////        for (int j = 0; j < i; ++j) {
////            dp[i] += dp[j] * dp[i - j - 1];
////        }
////    }
////
////    printf("%d", dp[n]);
//
//
//    return 0;
//}

#define MaxVertex 5

typedef char E;

typedef struct Node {   //结点和头结点分开定义，普通结点记录邻接顶点信息
    int nextVertex;
    struct Node * next;
} * Node;

struct HeadNode {   //头结点记录元素
    E element;
    struct Node * next;
};

typedef struct AdjacencyGraph {
    int vertexCount;   //顶点数
    int edgeCount;     //边数
    struct HeadNode vertex[MaxVertex];
} * Graph;

Graph create(void){   //创建时，我们可以指定图中初始有多少个结点
    Graph graph = malloc(sizeof(struct AdjacencyGraph));
    graph->vertexCount = graph->edgeCount = 0;
    return graph;   //头结点数组一开始可以不用管
}

void addVertex(Graph graph, E element){
    if(graph->vertexCount >= MaxVertex) return;   //跟之前一样
    graph->vertex[graph->vertexCount].element = element;   //添加新结点时，再来修改也行
    graph->vertex[graph->vertexCount].next = NULL;
      graph->vertexCount++;
}

void addEdge(Graph graph, int a, int b){
    Node node = graph->vertex[a].next;
    Node newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->nextVertex = b;
    if(!node) {    //如果头结点下一个都没有，那么直接连上去
        graph->vertex[a].next = newNode;
    } else {   //否则说明当前顶点已经连接了至少一个其他顶点了，有可能会出现已经连接过的情况，所以说要特别处理一下
        do {
            if(node->nextVertex == b) return;   //如果已经连接了对应的顶点，那么直接返回
            if(node->next) node = node->next;   //否则继续向后遍历
            else break;   //如果没有下一个了，那就找到最后一个结点了，直接结束
        } while (1);
        node->next = newNode;
    }
      graph->edgeCount++;   //边数计数+1
}

void printGraph(Graph graph){
    for (int i = 0; i < graph->vertexCount; ++i) {
        printf("%d | %c", i, graph->vertex[i].element);
        Node node = graph->vertex[i].next;
        while (node) {
            printf(" -> %d", node->nextVertex);
            node = node->next;
        }
        putchar('\n');
    }
}

int main(void){
    Graph graph = create();
    for (int c = 'A'; c <= 'D' ; ++c)
        addVertex(graph, (char) c);
    addEdge(graph, 0, 1);   //A -> B
    addEdge(graph, 1, 2);   //B -> C
    addEdge(graph, 2, 3);   //C -> D
    addEdge(graph, 3, 0);   //D -> A
    addEdge(graph, 2, 0);   //C -> A

    printGraph(graph);
}


































//int main(int argc, const char * argv[]) {
//    int n;
//    scanf("%d", &n);
//    int dp[n + 1]; // 0 1 |2 ... n|(0 + n)个结点
//    dp[0] = dp[1] = 1;
//    for(int i = 2; i <= n; ++i) {
//        dp[i] = 0;
//        for (int j = 0; j < i; ++j) {
//            dp[i] += dp[j] * dp[i - j - 1];
//        }
//    }
//    printf("%d\n",dp[n]);
//    return 0;
//}
