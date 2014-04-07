//Josh Bacon
//CPSC 223 Algorith and Abstract Data Structures
//10/1/2012
//File: Maze.cpp

#include "Maze.h"
#include <iostream>
#include <iomanip>
using namespace std;

Maze::Maze(int mazecols, int mazerows)
{
	if(mazecols > 0 && mazecols <= MAXSIZE) 
	{
		if(mazerows > 0 && mazerows <= MAXSIZE)
		{
			mazeRows = mazerows;
			mazeCols = mazecols;
			for(int i = 0; i < mazerows; i++)
				for(int j = 0; j < mazecols; j++)
					maze[j][i] = '0'; // no walls yet
		}
	}
	else
	{
		cout << "Error: Specified rows and cols exceeds limits!" << endl;
	}
}

Maze::~Maze()
{
	mazeRows = 0;
	mazeCols = 0;
}

bool Maze::isValidMove(int col, int row)
{
	if(maze[col - 1][row - 1] == '1' || maze[col - 1][row - 1] == 'X' || col <= 0 || col > mazeCols || row <= 0 || row > mazeRows)
		return false;
	else
		return true;
}

void Maze::placePath(int col, int row)
{
	maze[col - 1][row - 1] = 'X';
}

void Maze::removePath(int col, int row)
{
	maze[col - 1][row - 1] = '0';
}

bool Maze::isMazeSolved()
{
	if(maze[mazeCols - 1][mazeRows - 1] == 'X')
		return true;
	else
		return false;
}

void Maze::placeWall(int col, int row)
{
	maze[col - 1][row - 1] = '1';
}

bool Maze::isValidWall(int col, int row)
{
	if((row > 0 && row <= mazeRows) && (col > 0 && col <= mazeCols))
		return true;
	else {
		cout << "(" << col << "," << row << ") Is not a valid position for Wall placement" << endl;
		return false;
	}
}

void Maze::PrintMaze()
{
		for(int i = 0; i < mazeRows; i++) {
			for(int j = 0; j < mazeCols; j++) {
				if(maze[j][i] == '0')
					cout << "0 ";
				else if(maze[j][i] == '1')
					cout << "1 ";
				else if(maze[j][i] == 'X')
					cout << "X ";
			}
			cout << endl;
		}
		cout << endl;
}

void Maze::PrintSolCoord()
{
	for(int j = 0; j < mazeCols; j++) {
		for(int i = 0; i < mazeRows; i++) {
				if(maze[j][i] == 'X')
					cout << "(" << j << "," << i << ") ";
		}
		cout << endl;
	}
	cout << endl;

}