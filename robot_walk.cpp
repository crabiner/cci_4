/*
 * robot_walk.cpp
 *
 *  Created on: Jul 18, 2016
 *      Author: chen
 */

#include <vector>
#include <iostream>

using namespace std;
typedef struct point
{
	int row;
	int column;
}point_t;

bool walkMaze(vector<vector <bool> > &maze, int row, int col, vector<point_t> &path);
vector<point_t> walkMaze(vector<vector <bool> > &maze);

void robotWalk()
{
	vector<vector <bool>> maze(3, vector<bool>(3));
	maze[0][0] = true;
	maze[0][1] = true;
	maze[0][2] = false;
	maze[1][0] = true;
	maze[1][1] = false;
	maze[1][2] = true;
	maze[2][0] = true;
	maze[2][1] = true;
	maze[2][2] = true;

	walkMaze(maze);
	cout << "done";
}

vector<point_t> walkMaze(vector<vector <bool> > &maze)
{
	if (maze.size() == 0) return vector<point>();
	vector<point_t> path;
	if (walkMaze(maze, maze.size() - 1, maze[0].size() - 1, path)) return path;
	return vector<point>();
}

bool walkMaze(vector<vector <bool> > &maze, int row, int col, vector<point_t> &path)
{
	if ((row < 0) || (col < 0) || (!(maze[row][col])))
		return false;

	bool isHome = ((row == 0) && (col == 0));

	if (isHome || walkMaze(maze, row -1, col, path) || walkMaze(maze, row , col -1, path))
	{
		point p;
		p.column = col;
		p.row = row;
		path.push_back(p);
		cout <<"row=" <<p.row << " col="<<p.column << endl;
		return true;
	}
	return false;
}



