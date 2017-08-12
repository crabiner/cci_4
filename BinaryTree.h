/*
 * BinaryTree.h
 *
 *  Created on: Jun 20, 2016
 *      Author: chen
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_


#include <iostream>
#include <string>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode():
		data(0),
		left(nullptr),
		right(nullptr)
	{
	}

	TreeNode(int data):left(nullptr),right(nullptr)
	{
		this->data = data;
	}

	TreeNode(int data, TreeNode * lNode, TreeNode * rNode)
	{
		this->data = data;
		this->left = lNode;
		this->right = rNode;
	}

};

class BinaryTree {
	TreeNode * m_pRoot;
	int numNodes;

	void inOrderTreeTraversal(TreeNode * node);
	void inOrderTreeTraversalToArray(TreeNode * node, int arr[], int &index);
	void preOrderTreeTraversal(TreeNode * node);
	TreeNode * ReturnMinimalHeightBSTRecursive(int sortedArray[], int start, int end);
	void sortedArrayToMinimalHeightBST(int arr[], int size);
	bool isBinarySearchTree(TreeNode * root, int low, int high);

public:
	BinaryTree():numNodes(0){};
	BinaryTree(int arr[], int size):numNodes(0){
		sortedArrayToMinimalHeightBST(arr, size);
	};
	~BinaryTree(){
			delete this->m_pRoot;
	};
	void createTree1();
	void printInOrder();
	void printPreOrder();
	void checkIfBST();
};

#endif /* BINARYTREE_H_ */
