//Josh Bacon
//CPSC 223 Algorith and Abstract Data Structures
//10/1/2012
//File: Maze.h


//The maximum size specified for the number of rows or columns.
const int MAXSIZE = 20;

//Class Maze allows for using functions to solve a desired maze.
class Maze
{
public:
	//Creates a maze that is void of walls by the specified dimension.
	Maze(int mazecols, int mazerows);
	//Resets the maze Rows and Columns to 0.
	~Maze();
	//Looks at a potential coordinate in the maze and tells if it is a valid spot to create a path.
	bool isValidMove(int col, int row);
	//Places a 'X' at a spot in the maze that is looked at
	void placePath(int col, int row);
	//Removes a spot in the maze and replaces it with a '0' 
	void removePath(int cold, int row);
	//Determines whether or not the maze is solved, that is whether an 'X' is present at the exit of the maze.
	bool isMazeSolved();
	//Takes a desired coordinate in the maze and turns it into a wall, indicated by a '1'.
	void placeWall(int col, int row);
	//Determines whether the looked at coordinate is a potential spot for a wall to be placed (within boundaries).
	bool isValidWall(int col, int row);
	//Prints the maze in terms of 1's 0's and X's, 1's representing the walls, 0's representing open paths, and X's representing the taken path.
	void PrintMaze();
	//Prints all of the coordinates of the solution path, starting with the first step, and ending with the last, in order.
	void PrintSolCoord();
private:
	//The number of rows specified in the maze. (Horizontal)
	int mazeRows;
	//The number of Cols specified in the maze (Vertical)
	int mazeCols;
	//Array of chars representing the maze.
	char maze[MAXSIZE][MAXSIZE];
};