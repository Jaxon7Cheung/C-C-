//
//  main.c
//  二叉树的遍历(链式结构)
//
//  Created by 张旭洋 on 2023/2/7.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char element;
    struct TreeNode* right;
    struct TreeNode* left;
    int flag;  //用于判断是否遍历了右子树
}* Node;

typedef struct Stack {
    Node element;
    struct Stack* next;
}* SNode;

typedef struct QueueNode {
    Node element;
    struct QueueNode* next;
}* QNode;

typedef struct Queue {
    QNode rear,front;
} * LinkedQueue;

void preOrder(Node root);  //前序遍历(递归)
void crepreOrder(Node root);  //前序遍历(非递归)
void inOrder(Node root);  //中序遍历(递归)
void creinOrder(Node root);  //中序遍历(非递归)
void postOrder(Node root);  //后序遍历(递归)
void crepostOrder(Node root); //后序遍历(非递归)
void levelOrder(Node root);  //层序遍历
Node peekStack(SNode head);
void initStack(SNode head);
_Bool pushStack(SNode head,Node element);
Node popStack(SNode head);
_Bool isEmpty(SNode head);
_Bool initQueue(LinkedQueue queue);
_Bool offerQueue(LinkedQueue queue,Node element);
Node pollQueue(LinkedQueue queue);
_Bool qisEmpty(LinkedQueue queue);



int main(void) {
    Node a = malloc(sizeof(struct TreeNode));a->element = 'A';
    Node b = malloc(sizeof(struct TreeNode));b->element = 'B';
    Node c = malloc(sizeof(struct TreeNode));c->element = 'C';
    Node d = malloc(sizeof(struct TreeNode));d->element = 'D';
    Node e = malloc(sizeof(struct TreeNode));e->element = 'E';
    a->left = b;a->right = c;
    b->left = d;b->right = e;
    c->left = c->right = NULL;
    d->left = d->right = NULL;
    e->left = e->right = NULL;
    crepreOrder(a);printf("\n");
    creinOrder(a);printf("\n");
    crepostOrder(a);printf("\n");
    levelOrder(a);printf("\n");
}

void preOrder(Node root) {
    if(root == NULL) return;
    printf("%c ",root->element);
    preOrder(root->left);
    preOrder(root->right);
}

void preOrderByStack(Node root) {
    struct Stack stack;
    initStack(&stack);
    while (root || !isEmpty(&stack)) {
        while (root) {
            pushStack(&stack, root);
            printf("%d", root->element);
            root = root->left;
        }
        root = popStack(&stack);
        root = root->right;
    }
}

void crepreOrder(Node root) {
    struct Stack head;
    initStack(&head);
    while(root || !isEmpty(&head)) {
        while(root) {
            printf("%c ",root->element);
            pushStack(&head, root);
            root = root->left;
        }
        root = popStack(&head);
        root = root->right;
    }
}

void inOrder(Node root) {
    if(root == NULL) return;
    inOrder(root->left);
    printf("%c ",root->element);
    inOrder(root->right);
}

void inOrderByStack(Node root) {
    struct Stack stack;
    initStack(&stack);
    while (root || !isEmpty(&stack)) {
        while (root) {
            pushStack(&stack, root);
            root = root->left;
        }
        root = popStack(&stack);
        printf("%d", root->element);
        root = root->right;
    }
    
}

void creinOrder(Node root) {
    struct Stack head;
    initStack(&head);
    while(root || !isEmpty(&head)) {
        while(root) {
            pushStack(&head,root);
            root = root->left;
        }
        root = popStack(&head);
        printf("%c ",root->element);
        root = root->right;
    }
}

void postOrder(Node root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ",root->element);
}

void postOrderByStack(Node root) {
    struct Stack stack;
    initStack(&stack);
    while (root || !isEmpty(&stack)) {
        while (root) {
            pushStack(&stack, root);
            root->flag = 0;
            root = root->left;
        }
        
        root = peekStack(&stack);
        if (!root->flag) {
            root->flag = 1;
            root = root->right;
        } else {
            printf("%d", root->element);
            popStack(&stack);
            root = NULL;
        }
    }
}

void crepostOrder(Node root) {
    struct Stack head;
    initStack(&head);
    while (root || !isEmpty(&head)) {
        while (root) {
            pushStack(&head, root);
            root->flag = 0;
            root = root->left;
        }
        root = peekStack(&head);
        if (root->flag == 0) {
            root->flag = 1;
            root = root->right;
        } else {
            printf("%c ",root->element);
            popStack(&head);
            root = NULL;
        }
    }
}

void levelOrderByQueue(Node root) {
    struct Queue queue;
    initQueue(&queue);
    offerQueue(&queue, root);
    while (!qisEmpty(&queue)) {
        Node node = pollQueue(&queue);
        printf("%d", node->element);
        if (node->left) offerQueue(&queue, root->left);
        if (node->right) offerQueue(&queue, root->right);
    }
}
























void levelOrder(Node root) {
    struct Queue queue;
    initQueue(&queue);
    offerQueue(&queue, root);
    while(!qisEmpty(&queue)) {
        Node node = pollQueue(&queue);
        printf("%c ",node->element);
        if(node->left) offerQueue(&queue, node->left);
        if(node->right) offerQueue(&queue, node->right);
    }
}

//----------------栈-------------------
Node peekStack(SNode head) {
    return head->next->element;
}

void initStack(SNode head) {
    head->next = NULL;
}

_Bool pushStack(SNode head,Node element) {
    SNode node = malloc(sizeof(struct Stack));
    if(node == NULL) return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

Node popStack(SNode head) {
    SNode top = head->next;
    head->next = head->next->next;
    Node e = top->element;
    free(top);
    return e;
}

_Bool isEmpty(SNode head) {
    return head->next == NULL;
}
//-------------------------------------

//----------------队列------------------
_Bool initQueue(LinkedQueue queue) {
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    node->next = NULL;
    queue->front = queue->rear = node;
    return 1;
}

_Bool offerQueue(LinkedQueue queue,Node element) {
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

Node pollQueue(LinkedQueue queue) {
    Node e = queue->front->next->element;
    QNode tmp = queue->front->next;
    queue->front->next = queue->front->next->next;
    if(queue->rear == tmp) queue->rear = queue->front;
    free(tmp);
    return e;
}

_Bool qisEmpty(LinkedQueue queue) {
    return queue->front == queue->rear;
}
//-------------------------------------


