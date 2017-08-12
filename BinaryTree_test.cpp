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

	int arr[] = {1,2,3,4,5,6,7};
	BinaryTree bt_from_arr(arr, sizeof(arr)/sizeof(int));
	bt_from_arr.checkIfBST();

	int arr2[] = {1,2,3,40,5,6,7};
	BinaryTree bt_from_arr_2(arr2, sizeof(arr2)/sizeof(int));
	bt_from_arr_2.checkIfBST();

	int arr3[] = {1,2,3,5,4,6,7};
	BinaryTree bt_from_arr_3(arr3, sizeof(arr3)/sizeof(int));
	bt_from_arr_3.checkIfBST();
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
