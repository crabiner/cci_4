/*
 * BinaryTree.cpp
 *
 *  Created on: Jun 20, 2016
 *      Author: chen
 */

#include "BinaryTree.h"
using namespace std;

void BinaryTree::inOrderTreeTraversal(TreeNode * node)
{
	if (node)
	{
		inOrderTreeTraversal(node->left);
		cout << " " << node->data <<" " <<endl ;
		inOrderTreeTraversal(node->right);
	}
};

void BinaryTree::preOrderTreeTraversal(TreeNode * node)
{
	if (node)
	{
		cout << " " << node->data <<" " <<endl ;
		preOrderTreeTraversal(node->left);
		preOrderTreeTraversal(node->right);
	}
};

void BinaryTree::createTree1()
{
	this->m_pRoot = new TreeNode(5, new TreeNode(3), new TreeNode (7));
};

void BinaryTree::printInOrder()
{
	inOrderTreeTraversal(this->m_pRoot);
}

void BinaryTree::printPreOrder()
{
	preOrderTreeTraversal(this->m_pRoot);
}

TreeNode * BinaryTree::ReturnMinimalHeightBST(int sortedArray[], int start, int end)
{
	TreeNode * result = new TreeNode;
	if (end < start)
		return nullptr;

	int middle = (start + end)/2;
	result->data = sortedArray[middle];
	result->left = ReturnMinimalHeightBinarySearchTree(sortedArray, start , middle - 1);
	result->right = ReturnMinimalHeightBinarySearchTree(sortedArray, middle + 1, end);

	return result;
}

void BinaryTree::sortedArrayToMinimalHeightBST()
{
	int sortedArray[] = {1,2,3,4,5,6,7};
	preOrderTreeTraversal(ReturnMinimalHeightBinarySearchTree(sortedArray, 0, sizeof(sortedArray)/sizeof(int)));
}

