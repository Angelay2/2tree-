#pragma once
#include <stdlib.h>
#include "common.h"

// 二叉树结点
typedef struct BinaryTree{
	Node* _root;
}BinaryTree;

Node* createTree(Datatype* array, int* pi);
// 遍历的非递归
// 前中后序, 层序非递归
void preOrderNor(Node* root);

void preOrder(Node* root);

void inOrderNor(Node* root);

void inOrder(Node* root);

void postOrderNor(Node* root);

void inOrder(Node* root);

void leverOrder(Node* root);
// 判断一个数=树是不是完全二叉树
int isCompleteTree(Node* root);