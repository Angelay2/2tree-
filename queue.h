#pragma once
#include <stdio.h>
// 带有尾指针的单链表实现队列

typedef char QDatatype;
// 定义结点
typedef struct QNode{
	struct QNode* _next;
	QDatatype _data;
}QNode;

// 定义队列
typedef struct Queue{
	// 头尾指针
	QNode* _front;
	QNode* _rear;
	size_t _size;
}Queue;
// 函数
// 初始化
void queueInit(Queue* q);
// 队尾插入
void queuePush(Queue* q, QDatatype data);
// 队头删除
void queuePop(Queue* q);
// 拿到队头元素
QDatatype queueFront(Queue* q);
// 拿到队尾元素
QDatatype queueBack(Queue* q);
// 判空
int queueEmpty(Queue* q);
// 输出队列大小
size_t queueSize(Queue* q);

void queueDestory(Queue* q);