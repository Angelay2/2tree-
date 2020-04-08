#include "stack.h"
#include "common.h"
#include "BinaryTree.h"
#include "queue.h"


// �ǵݹ���� �൱��ջ����ջ�ͳ�ջ 
// 1. ���ʼ���ջ, ��ջ֮�������������
// 2. ���ظ���㼴��ջ �Ӷ����ʸ�����������

Node* createTree(Datatype* array, int* pi){
	// ���λ�õ��ַ�������'#' ��ȥ�������
	if (array[*pi] != '#'){
		// �ȴ�������� ������ռ� �ٴ�����
		Node* root = (Node*)malloc(sizeof(Node));
		root->_data = array[*pi]; // �ø������ݵ����ַ�

		//��λ������ƶ�һ��λ�� ������һ�����
		// ���������� ���Ӧ����createTree()����������صĽ��
		// ����������һϵ�е�����(bc,ֱ��c->left = '#'ʱ, return NULL)��, �ٽ�����һ���ݹ�
		// ���������ҽڵ� c�����ҽ�㶼Ϊ'#', ֤���������, ����c��� ֤��b��������������� ��������
		++(*pi);
		root->_left = createTree(array, pi);

		// ����ƶ�һ��λ��, ����������
		++(*pi);
		root->_right = createTree(array, pi);

		// ����֮�󷵻ظ�
		return root;
	}
	// ������ľ���һ��'#' ֱ�ӷ���NULL
	else
		return NULL;
}

// ǰ�����(�� �� ��)
// ������ʱ, ջ��=0, cur Ҳ����0
// ��ջ�ﵯ���Ľ����ζ�� �ý���Լ������������ѷ�����, ��Ҫ������������, 
// Ҫ������������ �ٽ��ҽڵ���ջ
// 1. ������ǰ��������·��
// 2. ���������ʵĽ���������

void preOrderNor(Node* root){
	Node* cur, *top;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	// ��ջ��һ��Ϊ��ʱ, ����ߵ�������������������,��ʱtop = root, ��ջ��, ջΪ��, Ȼ�����ջ��������������, ��cur��ΪNULL,����ѭ�� 
	// ��curΪNULL, ջҲΪ��ʱ, ������
	while (cur || stackEmpty(&st) != 1){
		// �ӵ�ǰ����λ��, һֱ����������ߵ�·��
		// curΪ��ʱ, ���·���ѷ�����, ȥ����丸���(������ջ) �����ҽڵ�,
		// ���ҽڵ㲻Ϊ��, ������Ϊ�µĸ���� ��ӡ ѹջ, ��ȥ����������ڵ�, ����ڵ�Ϊ��, ��ջ�����
		while (cur){
			// �ȴ�ӡ��ǰֵ(root)
			printf("%c ", cur->_data);
			// ѹջ��Ϊ�˺��ڳ�ջʱ�õ���������
			stackPush(&st, cur);
			cur = cur->_left;
		}
		// ��ǰ����Լ�������ڵ��ѷ�����,
		// ��ȡջ��Ԫ�� ������֮��ɾ����
		top = stackTop(&st);
		stackPop(&st);

		// ����������
		cur = top->_right;
	}
	printf("\n");
}

void preOrder(Node* root){
	if (root){
		printf("%c ", root->_data);
		preOrder(root->_left);
		preOrder(root->_right);
	}
}

// ��ǰ�����ѹջ, ���ܷ���, 
// ����߷�����(�ߵ�NULL)�� �ٴ�ӡ�����, ����������
void inOrderNor(Node* root){
	Node* cur, *top;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	while (cur || stackEmpty(&st) != 1){
		// �ӵ�ǰ����λ��, һֱ����������ߵ�·��
		while (cur){
			// �Ƚ���ǰ���ѹջ,����������
			stackPush(&st, cur);
			cur = cur->_left;
		}
		// ��ȡջ��Ԫ��
		top = stackTop(&st);
		stackPop(&st);
		// ��ӡ��ǰ���
		printf("%c", top->_data);
		// Ȼ���ٷ���������
		cur = cur->_right;
	}
}

//void postOrderNor(Node* root){
//	Node* cur, *top;
//	Stack st;
//	stackInit(&st, 10);
//	cur = root;
//	while (cur || stackEmpty(&st) != 1){
//		// �ӵ�ǰ����λ��, һֱ����������ߵ�·��
//		while (cur){
//
//		}
//	}
//}

// �Ƚ��ȳ� �ö��� 
// ֻҪ���Ӵ��� �Ϳ��Գ�ջ, �Ȱ����еĺ��ӱ������ 
// �õ�ǰ���������ӽڵ�, ���ϲ���δ������֮ǰ, �²����Ƿ��ʲ�����,
void leverOrder(Node* root){
	Queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (queueEmpty(&q) != 1){
		Node* cur = queueFront(&q);
		queuePop(&q);
		printf("%c ", cur->_data);
		if (cur->_left)
			queuePush(&q, cur->_left);
		if (cur->_right)
			queuePush(&q, cur->_right);
	}
}

// �ж�һ����=���ǲ�����ȫ������
// ÿһ��ı����������, �߲������
//ͨ���жϲ�����������зǿս��֮���Ƿ���ڿսڵ�NULL, ���ж�һ�����Ƿ�Ϊ��ȫ������
// ��û�� ��Ϊ��ȫ������ ���� ��Ϊ����ȫ������
int isCompleteTree(Node* root){
	Queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (queueEmpty(&q) != 1){
		Node* cur = queueFront(&q);
		queuePop(&q);
		// �����ǰ��ͷ���Ϊ��, ��ҪŶ����ʣ�����Ƕ���Ϊ�սڵ�
		if (cur == NULL)
			break;
		// ��������ڿ�, ���Һ������
		queuePush(&q, cur->_left);
		queuePush(&q, cur->_right);
	}
	while (queueEmpty(&q) != 1){
		Node* cur = queueFront(&q);
		queuePop(&q);
		// �����ǰ���Ϊ�ǿսڵ�(�ڿսڵ�֮������˷ǿս��) --> �������в�����
		if (cur)
			return 0;
	}
	// ����������涼û�з��� ˵������һ����ȫ������,
	return 1;
}