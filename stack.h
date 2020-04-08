#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "common.h"
// 顺序表实现栈
typedef Node* SDatatype;

typedef struct Stack{
	SDatatype* _array; // 给动态数组
	size_t _size;// 元素个数
	size_t _capacity;// 容量
}Stack;


void stackInit(Stack* st, size_t n);

void stackPush(Stack* st, SDatatype data);

void stackPop(Stack* st);

SDatatype stackTop(Stack* st);

size_t stackSize(Stack* st);

int stackEmpty(Stack* st);

void stackDestory(Stack* st);
