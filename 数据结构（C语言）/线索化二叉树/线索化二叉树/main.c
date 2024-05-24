//
//  main.c
//  线索化二叉树
//
//  Created by 张旭洋 on 2023/2/9.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char element;
    struct TreeNode* right;
    struct TreeNode* left;
    int leftTag, rightTag;
    
    struct TreeNode* parent;  //指向双亲结点，用于后序线索化
}* Node;

Node createNode(char element);

void preOrderThread(Node root);
void preOrderWithThread(Node root);
void inOrderThread(Node root);
void inOrderWithThread(Node root);
void postOrderThread(Node root);
void postOrderWithThread(Node root);

int main(void) {
    Node a = createNode('A');
    Node b = createNode('B');
    Node c = createNode('C');
    Node d = createNode('D');
    Node e = createNode('E');
    
    //前ABDEC 中DBEAC 后DEBCA
    a->left = b;a->right = c;
    b->left = d;b->right = e;
}

Node createNode(char element) {
    Node node = malloc(sizeof(struct TreeNode));
    node->element = element;
    node->left = node->right = NULL;
    node->leftTag = node->rightTag = 0;
    return node;
}

Node prePre = NULL;
void preOrderThread(Node root) {
    if (!root) return;
    
    if (!root->left) {
        root->left = prePre;
        root->leftTag = 1;
    }
    if (prePre && !prePre->right) {
        prePre->right = root;
        prePre->rightTag = 1;
    }
    
    prePre = root;
    
    if (!root->leftTag) preOrderThread(root->left);
    if (!root->rightTag) preOrderThread(root->right);
}

void preOrderWithThread(Node root) {
    while (root) {
        printf("%c ", root->element);
        if (!root->leftTag) {
            root = root->left;
        } else {
            root = root->right;  //左边没被线索话的话，直接走右边，无论是线索还是孩子，都要往这边走了
        }
    }
}

Node preIn = NULL;
void inOrderThread(Node root) {
    if (!root) return;
    
    if (!root->leftTag) preOrderThread(root->left);
    
    if (!root->left) {
        root->left = preIn;
        root->leftTag = 1;
    }
    if (preIn && !preIn->right) {
        preIn->right = root;
        preIn->rightTag = 1;
    }
    
    preIn = root;
    
    if (!root->rightTag) preOrderThread(root->right);
}

void inOrderWithThread(Node root) {
    while (root) {
        while (root && !root->leftTag) {
            root = root->left;
        }
        
        printf("%c ", root->element);
        while (root && root->rightTag) {
            root = root->right;
            printf("%c ", root->element);
        }
        root = root->right;
    }
}

Node prePost = NULL;
void postOrderThread(Node root) {
    if (!root) return;
    
    if (!root->leftTag) {
        postOrderThread(root->left);
        if (root->left) root->left->parent = root;
    }
    if (!root->rightTag) {
        preOrderThread(root->right);
        if (root->right) root->right->parent = root;
    }
    
    if (!root->left) {
        root->left = prePost;
        root->leftTag = 1;
    }
    if (prePost && !prePost->right) {
        prePost->right = root;
        prePost->rightTag = 1;
    }
    
    prePost = root;
}

void postOrderWithThread(Node root) {
    while (root) {
        
    }
}
