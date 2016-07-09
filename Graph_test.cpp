/*
 * Graph_test.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: chen
 */

#include "Graph.h"
#include <iostream>
using namespace std;

void graphTest()
{
	Graph graph(10);
	graph.createGraph();

	graph.toString();
	graph.dfs(0);
	graph.bfs(0);

	graph.dfs(5);
	graph.bfs(5);

	bool find1=graph.search(0, 5);
	bool find2=graph.search(0, 8);
	bool find3=graph.search(9, 8);
	cout <<" 1:"<< find1 <<" 2:" << find2 <<" 3:" << find3 << endl;
}

