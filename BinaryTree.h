#pragma once
#include <stdlib.h>
#include "common.h"

// ���������
typedef struct BinaryTree{
	Node* _root;
}BinaryTree;

Node* createTree(Datatype* array, int* pi);
// �����ķǵݹ�
// ǰ�к���, ����ǵݹ�
void preOrderNor(Node* root);

void preOrder(Node* root);

void inOrderNor(Node* root);

void inOrder(Node* root);

void postOrderNor(Node* root);

void inOrder(Node* root);

void leverOrder(Node* root);
// �ж�һ����=���ǲ�����ȫ������
int isCompleteTree(Node* root);