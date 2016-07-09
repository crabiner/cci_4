/*
 * BinaryTree_test.cpp
 *
 *  Created on: Jun 20, 2016
 *      Author: chen
 */

//#include <string>
using namespace std;

#include <iostream>
#include "BinaryTree.h"

void binaryTreeTest()
{
	BinaryTree bt;
	bt.createTree1();
	bt.printInOrder();
	std::cout <<  "printPreOrder ";
	bt.printPreOrder();
	std::cout <<  "sortedArrayToMinimalHeightBinarySearchTree " <<endl;
	bt.sortedArrayToMinimalHeightBinarySearchTree();
}
//
//
//#include <iostream>
//using namespace std;
//int main()
//{
//    cout << "Hello World" << endl;
//    return 0;
//}
