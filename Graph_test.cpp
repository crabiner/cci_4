/*
 * Graph_test.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: chen
 */

#include "Graph.h"

using namespace std;

void graphTest()
{
	Graph graph(8);
	graph.createGraph();

	graph.toString();
	graph.dfs(0);
	graph.bfs(0);

	graph.dfs(5);
	graph.bfs(5);
}

