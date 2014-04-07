//Josh Bacon
//CPSC 223 Algorith and Abstract Data Structures
//10/1/2012
//File: Mazesolver.cpp

#include "Maze.h"
#include <stack>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Function gets coordinates of desired walls from a text file, and places them throughout the maze where specified.
void CreateMazeWalls(Maze& mazeSet);
//Function solves the maze, and alters the maze to contain the correct path to the exit.
void MazeSolver(Maze& mazeSet, stack<int>& stackCol, stack<int>& stackRow, int col, int row);
//Function gets the length of the solution in terms of steps (coordinates) taken, and returns it as an int.
int GetSolLength(stack<int> stackCol);

int main()
{
	int mazerows, mazecols;
	cout << "Maze Solver Program: Compose a list of coordinates for placement of maze Walls in a text document, in the form of a list." << endl;
	cout << "                     The Program will then ask to specify the number of cols and rows to the maze." << endl;
	cout << "                     **NOTE: Number of Cols or Rows can not exceed 20." << endl << endl;
	cout << "Enter number of rows to maze: -> ";
	cin >> mazerows;
	cout << "Enter number of columns to maze: -> ";
	cin >> mazecols;
	Maze mazeSet(mazecols, mazerows);
	CreateMazeWalls(mazeSet);
	mazeSet.PrintMaze();
	int row = 1;
	int col = 1;
	stack<int> stackCol;
	stack<int> stackRow;
	MazeSolver(mazeSet, stackCol, stackRow, col, row);
	if(mazeSet.isMazeSolved())
		cout << "Solution Length: -> " << GetSolLength(stackCol) << endl;
	else
		cout << "Maze impossible to solve with given walls" << endl;
	return(0);
}

void CreateMazeWalls(Maze& mazeSet)
{
	int row, col;
	ifstream inputFile;
	string inputFileName;
	cout << "Enter the file name: -> ";
	cin >> inputFileName;
	inputFile.open(inputFileName);
	while(!inputFile.eof()) {
		inputFile >> col;
		inputFile >> row;
		if(mazeSet.isValidWall(col, row))
			mazeSet.placeWall(col, row);
	}
}

void MazeSolver(Maze& mazeSet, stack<int>& stackCol, stack<int>& stackRow, int col, int row)
{
	if(mazeSet.isMazeSolved()){
		cout << "Maze Solved!" << endl;
		mazeSet.PrintMaze();
		mazeSet.PrintSolCoord();
	}
	else if(!mazeSet.isMazeSolved()) {
		if(mazeSet.isValidMove(col, row) && !mazeSet.isMazeSolved()) {
			mazeSet.placePath(col, row);
			stackCol.push(col);	
			stackRow.push(row);
			MazeSolver(mazeSet, stackCol, stackRow, col, row);
			if(!mazeSet.isMazeSolved()) {
				mazeSet.removePath(col,row);
				stackCol.pop();
				stackRow.pop();
			}
		}
		if(mazeSet.isValidMove(col + 1, row) && !mazeSet.isMazeSolved()) {
			mazeSet.placePath(col + 1, row);
			stackCol.push(col + 1);	
			stackRow.push(row);
			MazeSolver(mazeSet, stackCol, stackRow, col+1, row);
			if(!mazeSet.isMazeSolved()) {
				mazeSet.removePath(col+1,row);
				stackCol.pop();
				stackRow.pop();
			}
		}
		if(mazeSet.isValidMove(col, row + 1) && !mazeSet.isMazeSolved()) {
			mazeSet.placePath(col, row + 1);
			stackCol.push(col);
			stackRow.push(row+1);
			MazeSolver(mazeSet, stackCol, stackRow, col, row+1);
			if(!mazeSet.isMazeSolved()) {
				mazeSet.removePath(col,row+1);
				stackCol.pop();
				stackRow.pop();
			}
		}
		if(mazeSet.isValidMove(col - 1, row) && !mazeSet.isMazeSolved()) {
			mazeSet.placePath(col - 1, row);
			stackCol.push(col-1);
			stackRow.push(row);
			MazeSolver(mazeSet, stackCol, stackRow, col-1, row);
			if(!mazeSet.isMazeSolved()) {
				mazeSet.removePath(col-1,row);
				stackCol.pop();
				stackRow.pop();
			}
		}
		if(mazeSet.isValidMove(col, row - 1) && !mazeSet.isMazeSolved()) {
			mazeSet.placePath(col, row - 1);
			stackCol.push(col);
			stackRow.push(row-1);
			MazeSolver(mazeSet, stackCol, stackRow, col, row-1);
			if(!mazeSet.isMazeSolved()) {
				mazeSet.removePath(col,row-1);
				stackCol.pop();
				stackRow.pop();
			}
		}
	}
}

int GetSolLength(stack<int> stackCol)
{
	if(!stackCol.empty()){
		stackCol.pop();
		return (GetSolLength(stackCol) + 1);
	}
	else
		return 0;
}
