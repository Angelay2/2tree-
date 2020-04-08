#include "stack.h"

// ջ(���޵����Ա�)�Ͷ���
// ���еĽṹ�ײ��޷������ֽṹ(һ���������Ľṹ, һ���ǲ������Ľṹ)
// 1. ջ: һ����������Ա�, ��ֵֻ�����ڹ̶���һ�˽��в����ɾ��Ԫ�ز���, 
// �������ݲ����ɾ��������һ�˳�Ϊջ��, ��һ�˳�Ϊջ��. ջ�е�����Ԫ�����غ���ȳ���ԭ��
// ѹջ; ջ�Ĳ������������ջ/ѹջ/��ջ, ��������ջ��
// ��ջ: ջ��ɾ������������ջ, ������Ҳ��ջ��.
// ջ�ױ�ʾ��һ��Ԫ�طŵ�λ�� ջ����ʾ���һ��Ԫ�طŵ�λ��

// ջ��ʵ��: ջ��ʵ��һ�����ʹ�������������, ��Զ�������Ľṹʵ�ָ���һЩ, ��Ϊ������β�ϲ�������
// �Ĵ��۱Ƚ�С,
// ������˳�����β���Ӧջ����ջ, βɾ��Ӧջ�ĳ�ջ
// �õ�������ͷ���Ӧջ����ջ    ͷɾ��Ӧջ�ĳ�ջ 
// ���߶�Ӧջ�Ĳ�������O(1),  ����������������ܶ����������, ����ѡ��˳���
// ջ��ʵ��һ�����Ӽ򵥵�˳���


// ջ�ĳ�ʼ��
// �൱�ڿ�һ��n�Ĵ�С�ռ�
// ������n�Ĵ�С�Ĵ������Ŀռ�(�������ɵ�Ԫ�ظ��� * Ԫ�����ʹ�С(����ռ���ֽ�))
// �ٽ�Ԫ�ظ�������Ϊ0, �������������Դ��n��Ԫ��(��������Ҫ������Ԫ�صĿռ�)
// ֱ�����Ѿ�����õ�ָ��ָ��ÿ�ռ�
// ����Ϊ�ṹ��ָ�붨���ջ��Ԫ�ظ���n ֱ���ö����ջst���Է�����ṹ���ڲ������Ԫ��
void stackInit(Stack* st, size_t n){
	st->_array = (SDatatype*)malloc(sizeof(SDatatype) * n);
	st->_size = 0;
	st->_capacity = n;// ��ǰ�ܴ�Ŷ���Ԫ�� 
}

// ��ջ
// �ȵ�����Ԫ�ص����и���������һ�� ��֤���������� Ҫ���� ������st->_arrayָ��������Ŀռ�(���¿ռ�)
// ���ݼ�����ռ�(Ϊ�������ɵ�Ԫ�ظ����������ʹ�С)�Լ����ӿ������ɵ�Ԫ�ظ���(��ֱ�ӵİ취����2)
// ����ռ��轫֮ǰ����Ŀռ��ʼ��, ��_arrayָ������������¿ռ�(��СΪ2*ԭʼ����) 
// ������ռ��ٸ�������
void stackPush(Stack* st, SDatatype data){
	// �������
	if (st->_size == st->_capacity){
		// ���ӿռ������, Ԫ�ظ�������
		st->_array = (SDatatype*)realloc(st->_array, sizeof(SDatatype) * 2 * st->_capacity);
		st->_capacity *= 2; 
	}
	// �ٽ���β�� ��Ԫ�ظ���+1, �±�Ϊsize-1��Ϊԭʼ���һ��Ԫ�� �µ�Ԫ��Ӧ������±�Ϊsize��λ��
	// ���Ը������� ����data���������±�Ϊsize��Ԫ��;
	st->_array[st->_size++] = data;
}

// ��ջ ջ��Ϊ�� ֱ�Ӽ�С��������
void stackPop(Stack* st){
	if (st->_size > 0){
		--st->_size;
	}
}

// ��ȡջ��Ԫ��(�����һ�������Ԫ��)
SDatatype stackTop(Stack* st){
	return st->_array[st->_size - 1];
}

// ��ȡջ��Ԫ�ظ���
size_t stackSize(Stack* st){
	return st->_size;
}

// ջ�Ƿ�Ϊ��
int stackEmpty(Stack* st){
	if (st->_size == 0)
		return 1;
	return 0;
}

// ���ܴ�ӡջ, Ҫ�����ջ�ռ��Ԫ��, ֻ��ʹ��pop�Ĳ���
// ��ӡ���ƻ�ջ���ص�, �����ӡ�Ļ�,˳����Ͳ��ܱ�֤����ȳ��Ĺ�����, ����������˳����,
// ջ������(�ѿռ仹��ϵͳ)
void stackDestory(Stack* st){
	// ������黹���� �Ǿ��ͷ�����
	if (st->_array){
		free(st->_array);
		// �ռ仹�������. ���� ������Ϊ0;
		st->_size = st->_capacity = 0;
	}
}