/*
 * Graph.h
 *
 *  Created on: Jul 4, 2016
 *      Author: chen
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
#include <vector>
#include <list>

namespace std {
class Node {
public:
	list<int> adjacentList;
	bool visited;
};

class Graph {
	Node * m_nodes ;
	vector<list<int> >  nodes;
	int num_of_vertices;

	void dfsUtil(int vertice, bool visited[]);
public:
	Graph(int N); //num_of_vertices
	virtual ~Graph();
	void addEdge(int nodeId, int adjacentNodeId);
	void createGraph();
	void toString();
	void dfs(int startVertice);
	void bfs(int startVertice);
};

} /* namespace std */

#endif /* GRAPH_H_ */
