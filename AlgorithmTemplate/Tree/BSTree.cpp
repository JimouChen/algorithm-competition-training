#include <bits/stdc++.h>

using namespace std;

typedef char ElemType;

//二叉树节点
typedef struct BTNode {
    ElemType data;
    struct BTNode *leftChild, *rightChild;
} BTNode, *BiTree;


/**二叉搜索树的查找,递归实现*/
BiTree SearchBST(BiTree root, ElemType key) {
    if (!root || root->data == key)return root;
    else if (key < root->data)
        return SearchBST(root->leftChild, key);
    else
        return SearchBST(root->rightChild, key);
}

//插入，递归实现
bool insertNode(BiTree t, ElemType key) {
    if (!t) {
        t = (BTNode *) malloc(sizeof(BTNode));
        t->data = key;
        t->rightChild = t->leftChild = NULL;
        return true;
    } else if (key == t->data)//如果是等于根节点的值没那就不插入
        return false;
    else if (key < t->data)
        return insertNode(t->leftChild, key);
    else
        return insertNode(t->rightChild, key);
}

//创建二叉排序树,n可以直接取str的长度
void createBST(BiTree &t, ElemType str[], int n) {
    int i = 0;
    while (i < n) {
        insertNode(t, str[i]);
        i++;
    }
}