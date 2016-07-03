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

class Node{
public:
	int data;
	Node *left;
	Node *right;

	Node(int data):left(0),right(0)
	{
		this->data = data;
	}

	Node(int data, Node * lNode, Node * rNode)
	{
		this->data = data;
		this->left = lNode;
		this->right = rNode;
	}

};

class BinaryTree {
public:
	BinaryTree(){};
	~BinaryTree(){
			delete this->m_pRoot;
	};

	void createTree1()
	{
		this->m_pRoot = new Node(5, new Node(3), new Node (7));
	};

	void printInOrder()
	{
		inOrder(this->m_pRoot);
	}

	void printPreOrder()
	{
		preOrder(this->m_pRoot);
	}




private:
	void inOrder(Node * node)
	{
		if (node)
		{
			inOrder(node->left);
			std::cout << " " << node->data <<" " <<endl ;
			inOrder(node->right);
		}
	};

	void preOrder(Node * node)
	{
		if (node)
		{
			std::cout << " " << node->data <<" " <<endl ;
			inOrder(node->left);
			inOrder(node->right);
		}
	};
	Node * m_pRoot;
};

#endif /* BINARYTREE_H_ */
