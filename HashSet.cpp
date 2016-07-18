/*
 * HashSet.cpp
 *
 *  Created on: Jul 16, 2016
 *      Author: chen
 */

#include <string>
#include <sstream>
#include <iostream>
#include <unordered_set>

using namespace std;

//Diving Board: You are building a diving board by placing a bunch of planks of wood end-to-end.
//	There are two types of planks, one of length shorter and one of length longer. You must use
//	exactly K planks of wood. Write a method to generate all possible lengths for the diving board.

void recursiveBoardLength(int k, int total, int shorter, int longer, unordered_set<int> &planksSet)
{
	if (k == 0)
	{
//		cout << "insert "<< total <<endl;
		planksSet.insert(total);
		return;
	}
	recursiveBoardLength(k-1, total + shorter, shorter, longer, planksSet);
	recursiveBoardLength(k-1, total + longer, shorter, longer, planksSet);
}


void iterateAllBoardLengths()
{
	unordered_set<int> planksSet;
	recursiveBoardLength(3, 0, 5, 10 ,planksSet);

	unordered_set<int>::iterator it;
	for (it = planksSet.begin(); it != planksSet.end(); it++)
	{
		cout << *it <<endl;
	}

}
