#include "stack.h"
#include "common.h"
#include "BinaryTree.h"
#include "queue.h"


// 非递归遍历 相当于栈的入栈和出栈 
// 1. 访问即入栈, 入栈之后访问其左子树
// 2. 返回父结点即出栈 从而访问父结点的右子树

Node* createTree(Datatype* array, int* pi){
	// 这个位置的字符不等于'#' 就去建立结点
	if (array[*pi] != '#'){
		// 先创建根结点 先申请空间 再传数据
		Node* root = (Node*)malloc(sizeof(Node));
		root->_data = array[*pi]; // 让根的数据等于字符

		//把位置向后移动一个位置 建立下一个结点
		// 建立左子树 左边应等于createTree()这个函数返回的结点
		// 创建完根左边一系列的左结点(bc,直到c->left = '#'时, return NULL)后, 再进入下一个递归
		// 进而创建右节点 c的左右结点都为'#', 证明创建完毕, 返回c结点 证明b的左子树创建完毕 到右子树
		++(*pi);
		// 第一个#即为最左边子树的左节点
		root->_left = createTree(array, pi);

		// 向后移动一个位置, 建立右子树
		// 第二个#即为最左边子树的右节点
		++(*pi);
		root->_right = createTree(array, pi);

		// 建好之后返回根
		return root;
	}
	// 如果给的就是一个'#' 直接返回NULL
	else
		return NULL;
}

// 前序遍历(根 左 右)
// 访问完时, 栈里=0, cur 也等于0
// 从栈里弹出的结点意味着 该结点以及他的左子树已访问完, 需要访问其右子树, 
// 要访问其右子树 再将右节点入栈
// 1. 遍历当前结点的最左路径
// 2. 遍历最后访问的结点的右子树
void preOrderNor(Node* root){
	Node* cur, *top;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	// 当栈第一次为空时, 根左边的所有子树都访问完了,此时top = root, 出栈后, 栈为空, 然后根据栈顶访问其右子树, 但cur不为NULL,继续循环 
	// 当cur为NULL, 栈也为空时, 访问完
	while (cur || stackEmpty(&st) != 1){
		// 从当前根的位置, 一直访问完最左边的路径
		// cur为空时, 左边路径已访问完, 去获得其父结点(父结点出栈) 访问右节点,
		// 若右节点不为空, 将其作为新的父结点 打印 压栈, 再去访问他的左节点, 若左节点为空, 出栈父结点
		while (cur){
			// 先打印当前值(root)
			printf("%c ", cur->_data);
			// 压栈是为了后期出栈时拿到其右子树
			stackPush(&st, cur);
			cur = cur->_left;
		}
		// 当前结点以及他的左节点已访问完,
		// 获取栈顶元素 访问完之后删除掉
		top = stackTop(&st);
		stackPop(&st);

		// 访问右子树
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

// 中序遍历 左-根-右
// 当前结点先压栈, 不能访问, 
// 让左边访问完(走到NULL)后 再打印根结点, 再右子树
void inOrderNor(Node* root){
	Node* cur, *top;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	while (cur || stackEmpty(&st) != 1){
		// 从当前根的位置, 一直访问完最左边的路径
		while (cur){
			// 先将当前结点压栈,访问左子树
			stackPush(&st, cur);
			cur = cur->_left;
		}
		// top获取栈顶元素
		top = stackTop(&st);
		stackPop(&st);
		// 再打印当前结点
		printf("%c ", top->_data);
		// 然后再访问右子树
		cur = top->_right;
	}
	printf("\n");
}

void inOrder(Node* root){
	if (root){
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}
}

// 后序遍历
// 1. 对应的叶子结点是可以直接访问的
// 2. 含有右子树的非叶子结点,不能直接出栈
//   a. 先访问完右子树
//   b. 才能出栈访问当前非叶子结点
// 如果判断右子树是否访问完毕(记录前一步结点位置)
//  设置标记指针, 标记上次访问的结点位置: prev
//  cur->right == prev; 可以访问cur, 即右子树已访问完

void postOrderNor(Node* root){
	Node* cur, *top, *prev;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	prev = NULL;
	while (cur || stackEmpty(&st) != 1){
		// 从当前根的位置, 一直访问完最左边的路径
		while (cur){
			stackPush(&st, cur);
			cur = cur->_left;
		}
		// 判断当前结点是否可以访问
		top = stackTop(&st);
		// 如果没有右子树 或者右子树已经访问完毕
		if (top->_right == NULL || top->_right == prev){
			// 可以访问当前节点
			printf("%c ", top->_data);
			stackPop(&st);
			prev = top;
		}
		// 当前栈顶元素还有右子树没有访问完, 先访问右子树
		else
			cur = top->_right;
	}
	printf("\n");
}

void postOrder(Node* root){
	if (root){
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}
// 层序遍历
// 先进先出 用队列 
// 只要孩子存在 就可以出栈, 等把所有的孩子遍历完后 
// 让当前结点带出孩子节点, 在上层结点未访问完之前, 下层结点是访问不到的,
// 先让首元素入队列 父出左右孩子进
void leverOrder(Node* root){
	//用队列的出队顺序模拟层序遍历的顺序
	Queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (queueEmpty(&q) != 1){ 
		// 获取队头元素
		Node* cur = queueFront(&q);
		queuePop(&q);
		printf("%c ", cur->_data);
		// 孩子入队
		if (cur->_left)
			queuePush(&q, cur->_left);
		if (cur->_right)
			queuePush(&q, cur->_right);
	}
}

// 判断一个数=树是不是完全二叉树
// 每一层的编号是连续的, 走层序遍历
//通过判断层序遍历序列中非空结点之间是否存在空节点NULL, 来判断一棵树是否为完全二叉树
// 若没有 则为完全二叉树 若有 则为非完全二叉树
int isCompleteTree(Node* root){
	Queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (queueEmpty(&q) != 1){
		Node* cur = queueFront(&q);
		queuePop(&q);
		// 如果当前队头结点为空, 需要哦按段剩余结点是都都为空节点
		if (cur == NULL)
			break;
		// 如果不等于空, 左右孩子入队
		queuePush(&q, cur->_left);
		queuePush(&q, cur->_right);
	}
	while (queueEmpty(&q) != 1){
		Node* cur = queueFront(&q);
		queuePop(&q);
		// 如果当前结点为非空节点(在空节点之间包含了非空结点) --> 结点的排列不连续
		if (cur)
			return 0;
	}
	// 如果走完上面都没有返回 说明就是一个完全二叉树,
	return 1;
}