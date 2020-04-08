#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "common.h"
// ˳���ʵ��ջ
typedef Node* SDatatype;

typedef struct Stack{
	SDatatype* _array; // ����̬����
	size_t _size;// Ԫ�ظ���
	size_t _capacity;// ����
}Stack;


void stackInit(Stack* st, size_t n);

void stackPush(Stack* st, SDatatype data);

void stackPop(Stack* st);

SDatatype stackTop(Stack* st);

size_t stackSize(Stack* st);

int stackEmpty(Stack* st);

void stackDestory(Stack* st);
