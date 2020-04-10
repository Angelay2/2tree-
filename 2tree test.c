#include "BinaryTree.h"

void test(){
	char str[] = { "abc##de#g##f###" };
	int i = 0;
	//Node* ret;
	Node* root = createTree(str, &i);
	/*preOrderNor(root);
	preOrder(root);*/

	/*inOrderNor(root);
	inOrder(root);*/
	
	postOrderNor(root);
	postOrder(root);

}

//void test3(){
//	char str[] = { "ABDG##H###CE#I##F##" };
//	char str2[] = { "ABDH##I##E##CF##G##" };
//
//}
int main(){

	test();
	system("pause");
	return 0;
}