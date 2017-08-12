/*
 * biDirSearch.h
 *
 *  Created on: Aug 11, 2017
 *      Author: chen
 */

#ifndef BIDIRSEARCH_H_
#define BIDIRSEARCH_H_

// C++ program for Bidirectional BFS search
// to check path between two vertices
#include <bits/stdc++.h>
using namespace std;

// class representing undirected graph
// using adjacency list
class Graph
{
    //number of nodes in graph
    int V;

    // Adjacency list
    list<int> *adj;
public:
    Graph(int V);
    int isIntersecting(bool *s_visited, bool *t_visited);
    void addEdge(int u, int v);
    void printPath(int *s_parent, int *t_parent, int s,
                             int t, int intersectNode);
    void BFS(list<int> *queue, bool *visited, int *parent);
    int biDirSearch(int s, int t);
    static int main();
};


#endif /* BIDIRSEARCH_H_ */
