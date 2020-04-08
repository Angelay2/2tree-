#pragma once
#include <stdio.h>
// ����βָ��ĵ�����ʵ�ֶ���

typedef char QDatatype;
// ������
typedef struct QNode{
	struct QNode* _next;
	QDatatype _data;
}QNode;

// �������
typedef struct Queue{
	// ͷβָ��
	QNode* _front;
	QNode* _rear;
	size_t _size;
}Queue;
// ����
// ��ʼ��
void queueInit(Queue* q);
// ��β����
void queuePush(Queue* q, QDatatype data);
// ��ͷɾ��
void queuePop(Queue* q);
// �õ���ͷԪ��
QDatatype queueFront(Queue* q);
// �õ���βԪ��
QDatatype queueBack(Queue* q);
// �п�
int queueEmpty(Queue* q);
// ������д�С
size_t queueSize(Queue* q);

void queueDestory(Queue* q);