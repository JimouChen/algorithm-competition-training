#include <bits/stdc++.h>

using namespace std;

typedef char ElemType;

//二叉树节点
typedef struct BTNode {
    ElemType data;
    struct BTNode *leftChild, *rightChild;
} BTNode, *BiTree;

//初始化
//void InitTree(BiTree &root) {
//    root = (BTNode *) malloc(sizeof(BTNode));
//    root->leftChild = NULL;
//    root->rightChild = NULL;
//}

//先序创建二叉树
void createTree(BiTree &t) {
    ElemType ch;
    cin >> ch;
    if (ch == '#') t = NULL;
    else {
        t = (BTNode *) malloc(sizeof(BTNode));
        t->data = ch;
        createTree(t->leftChild);
        createTree(t->rightChild);
    }
}

//先序遍历
void preOrder(BiTree t) {
    if (t) {
        cout << t->data << ' ';
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

//中序
void inOrder(BiTree t) {
    if (t) {
        inOrder(t->leftChild);
        cout << t->data << ' ';
        inOrder(t->rightChild);
    }
}

//后序
void postOrder(BiTree t) {
    if (t) {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        cout << t->data << ' ';
    }
}

int main() {
    BiTree tree;//AB##C##
    createTree(tree);
    preOrder(tree);
    inOrder(tree);
    postOrder(tree);
    return 0;
}