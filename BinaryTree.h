/*
 * BinaryTree.h
 *
 *  Created on: Jun 20, 2016
 *      Author: chen
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

using namespace std;
#include <iostream>
#include <string>

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
			delete this->root;
	};

	void createTree1()
	{
		this->root = new Node(5, new Node(3), new Node (7));
		inOrder(this->root);
	};

	void inOrder(Node * node)
	{
		if (node)
		{
			inOrder(node->left);
			std::cout << " " << node->data <<" " ;
			inOrder(node->right);
		}
	};
private:
	Node * root;
};

#endif /* BINARYTREE_H_ */
