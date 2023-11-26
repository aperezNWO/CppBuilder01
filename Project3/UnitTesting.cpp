#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <Sudoku.cpp>

//
int _tmain(int argc, _TCHAR* argv[])
{
	//
	const static int   N = 9;
	int                K = 20;
	int grid[N][N];
	//
	char cont='y';

	//
	do {
		//
		system("cls");
		std::cout << "Generated Board : " << endl;

		//
		SudokuGenerator* sudokuGenerator = new SudokuGenerator(N, K);
		sudokuGenerator->Run();

		//
		for (int i = 0; i < N; i++)
		{
			//
			for (int j = 0; j < N; j++) {
				   grid[i][j] = sudokuGenerator->mat[i][j];
			}
		};

		//
		SudokuSolver* sudokuSolver = new SudokuSolver();
		sudokuSolver->Solve(grid);

		//
		cout << endl << "Do you want to quit? (y/n) : ";
		cin  >> cont;

	}   while(cont=='n');

	//
	return (0);
};
