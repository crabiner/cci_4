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

void BinaryTree::inOrderTreeTraversalToArray(TreeNode * node, int arr[], int &index)
{
	if (node)
	{
		inOrderTreeTraversalToArray(node->left, arr, index);
		index++;
		arr[index] = node->data ;
		inOrderTreeTraversalToArray(node->right, arr, index);
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

TreeNode * BinaryTree::ReturnMinimalHeightBSTRecursive(int sortedArray[], int start, int end)
{
	TreeNode * result = new TreeNode;
	if (end < start)
		return nullptr;

	int middle = (start + end)/2;
	result->data = sortedArray[middle];
	result->left = ReturnMinimalHeightBSTRecursive(sortedArray, start , middle - 1);
	result->right = ReturnMinimalHeightBSTRecursive(sortedArray, middle + 1, end);

	return result;
}

void BinaryTree::sortedArrayToMinimalHeightBST(int sortedArray[], int size)
{
	m_pRoot = ReturnMinimalHeightBSTRecursive(sortedArray, 0, size-1);
	numNodes = size;
	inOrderTreeTraversal(m_pRoot);
}

bool BinaryTree::isBinarySearchTree(TreeNode * root, int low, int high) {
	if(root == NULL) {
		return true;
	}
	if(root->data <= low || root->data >= high) {
		return false;
	}
	return isBinarySearchTree(root->left, low, root->data) &&
		   isBinarySearchTree(root->right, root->data, high);
}

void BinaryTree::checkIfBST()
{
	if (isBinarySearchTree(m_pRoot, 0, 0xfffffff))
		cout << "is BST" <<endl;
	else
		cout << "is not BST" <<endl;
}

