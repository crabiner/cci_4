/*
 * Graph.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: chen
 */

#include "Graph.h"
#include <iostream>
#include <queue>

namespace std {

Graph::Graph(int N):nodes(N),
					num_of_vertices(N)
{
	// TODO Auto-generated constructor stub

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}


void Graph::addEdge(int nodeId, int adjacentNodeId)
{
	nodes[nodeId].push_back(adjacentNodeId);
}
// 	  0 - 1 - 2 - 3       9
// 		 /   /			 /
// 		4 - 5 - 6 - 7   8
void Graph::createGraph()
{
	addEdge(0, 1);
	addEdge(1, 0);	addEdge(1, 2);	addEdge(1, 4);
	addEdge(2, 1);	addEdge(2, 3);	addEdge(2, 5);
	addEdge(3, 2);
	addEdge(4, 1);	addEdge(4, 5);
	addEdge(5, 4);	addEdge(5, 2);	addEdge(5, 6);
	addEdge(6, 7);	addEdge(6, 5);
	addEdge(7, 6);
	addEdge(8, 9);
	addEdge(9, 8);
}

void Graph::toString()
{
	vector<list<int> >::iterator it;
	int node_count = 0;
	for ( it = nodes.begin(); it < nodes.end(); it++)
	{

		cout << "node "<< node_count << " adjacencies ";
		list<int> li = (*it);
		list<int>::iterator liIt;

		for (liIt = li.begin(); liIt != li.end(); liIt++)
		{
			cout << *liIt << " ";
		}
		cout << "\n";
		node_count++;
	}
}

//Recursive DFS
void Graph::dfsUtil(int vertice, bool visited[])
{
	cout << vertice<< " "  ;
	visited[vertice] = true;
	list<int> li = nodes[vertice];
	list<int>::iterator liIt;

	for (liIt = li.begin(); liIt != li.end(); liIt++)
	{
//		cout << " on "<< vertice << " checking " << *liIt ;
		if (visited[*liIt] == false)
			dfsUtil(*liIt, visited);
	}

}

void Graph::dfs(int startVertice)
{
	bool *visited = new bool[num_of_vertices];
	for (int i = 0; i< num_of_vertices ; i++)
		visited[i] = false;

	cout << " DFS from " <<startVertice << ":" ;
	dfsUtil(startVertice, visited);
	cout << " done " <<endl;
}


void Graph::bfs(int startVertice)
{
	bool *marked = new bool[num_of_vertices];
	for (int i = 0; i< num_of_vertices ; i++)
		marked[i] = false;

	queue<int> q;
	list<int>::iterator it;

	marked[startVertice] = true;
	q.push(startVertice);

	cout << " BFS from " <<startVertice << ":" ;

	while (!q.empty())
	{
		int v=q.front();
		q.pop();
		cout << v << " ";
		for (it = nodes[v].begin(); it != nodes[v].end(); it++)
		{
			if (marked[*it] == false)
			{
				marked[*it] = true;
				q.push(*it);
			}
		}
	}
	cout << " done " <<endl;
}

bool Graph::search(int start, int end)
{
	if (start == end)
		return true;

	bool visited[num_of_vertices];
	for (int i = 0; i < num_of_vertices; i++)
		visited[i] = false;

	//list as queue
	list<int> q;

	q.push_back(start);

	while (!q.empty())
	{
		int v = q.front();
		q.pop_front();

		cout << " "<<v;
		visited[v] = true;
		if (v == end)
			return true;

		for (auto &it: nodes[v])
		{
			if (visited[it] == false)
			{
				q.push_back(it);
			}
		}
	}

	return false;
}

} /* namespace std */
