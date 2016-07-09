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
	void inOrderTreeTraversal(TreeNode * node);
	void preOrderTreeTraversal(TreeNode * node);
	TreeNode * m_pRoot;
	TreeNode * ReturnMinimalHeightBinarySearchTree(int sortedArray[], int start, int end);

public:
	BinaryTree(){};
	~BinaryTree(){
			delete this->m_pRoot;
	};
	void createTree1();
	void printInOrder();
	void printPreOrder();
	void sortedArrayToMinimalHeightBinarySearchTree();
};

#endif /* BINARYTREE_H_ */
