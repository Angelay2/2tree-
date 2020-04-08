#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

typedef char Datatype;
typedef struct TreeNode {

	Datatype _data;
	struct TreeNode* _left;
	struct TreeNode* _right;
}Node;
