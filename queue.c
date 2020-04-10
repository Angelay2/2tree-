#include "queue.h"
#include <stdlib.h>

// 2. 队列: 只允许在一端进行插入数据操作, 在另一端进行删除数据操作的特殊线性表, 队列具有先进先出的原则
// 入队列: 进行插入操作的一端称为队尾,      出队列: 进行删除操作的一端为队头
// 新的元素来 只能在队尾进行插入, 不能插队, 队尾进, 队头出,
// 而栈是后进先出, 而队列是后进后出,先进先出

// 队列(也是线性表)的实现: 
// 队列也可以以数组和链表的结构实现, 使用链表的结构实现更优一点, 
// 因为如果使用数组的结构, 出队列在数组头上出数据, 效率会比较低
// 队尾进相当于尾插, 队头出相当于头删,
// 顺序表: PushBack --> 队列: 入队 --> O(1)
// 顺序表: PopFront --> 队列: 出队 --> O(N)  从后往前覆盖, 这个没有办法改变
// 单链表: PushBack --> 队列: 入队 --> O(N)  这个可以通过加入一个尾指针(rear)来降低复杂度 --> O(1)
// 单链表: PopFront --> 队列: 出队 --> O(1)  
// 所以选择单链表来实现队列

// 初始化
void queueInit(Queue* q){
	// 空队列的头和尾应该都等于NULL,大小为0
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
// 队尾插入 入队
void queuePush(Queue* q, QDatatype data){
	// 需要先创建新结点
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
	// 尾插
	// 用两个指针来指向 在尾结点后面插入一个结点
	// 如果是空队列, 则插入后头和尾指针都指向这个结点
	if (q->_front == NULL){// 插入第一个结点时进入
		q->_front = q->_rear = node;
	}
	// 如果不是空队列, 原始rear的next指向node, node的next指向NULL
	else{
		q->_rear->_next = node;
		node->_next = NULL;
	}
	// 更新尾结点
	q->_rear = node;
	++q->_size;

}

// 删除队头 出队
// 判断队列不为空, 若不为空删除一个结点后还需判断队列此时是否为空 若为空 头和尾结点都指向NULL.
// 先把头结点的next保存起来 然后再删除头结点 让头结点更新为next
void queuePop(Queue* q){
	// 先判断空 
	if (q->_front != NULL){
		
		QNode* next = q->_front->_next;
		// 删除头结点
		free(q->_front);
		// 更新头结点
		q->_front = next;
		// 若队列中只有一个结点 删除后头结点指向next(NULL) 则需要更新队尾 也指向NULL
		if (q->_front == NULL)
			q->_rear = NULL;

		--q->_size;
	}
}
// 拿到队头元素
QDatatype queueFront(Queue* q){
	return q->_front->_data;
}
// 拿到队尾元素
QDatatype queueBack(Queue* q){
	return q->_rear->_data;
}
// 判空
int queueEmpty(Queue* q){
	// 可以判断队头 也可判断大小
	// if(q->_size == 0)
	if (q->_front == NULL)
		return 1;
	return 0;
}
// 输出队列大小
size_t queueSize(Queue* q){
	return q->_size;
}

void queueDestory(Queue* q){
	QNode* cur = q->_front;
	// 如果头部位空, 则拿到头的next 然后free头 再更新 再free 直删除最后一个结点
	while (cur){
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	// 删除最后一个结点后 需将头和尾都指向NULL
	q->_rear = q->_front = NULL;
	q->_size = 0;
}