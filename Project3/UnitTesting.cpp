#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <Sudoku.cpp>

//
int _tmain(int argc, _TCHAR* argv[])
{
	//
	const static int   N = 9;
	int                K = 20;
	int grid[N][N];

	//
	SudokuGenerator* sudokuGenerator = new SudokuGenerator(N, K);
	sudokuGenerator->Run();

		for (int i = 0; i < N; i++)
		{
			//
			for (int j = 0; j < N; j++) {
				   grid[i][j] = sudokuGenerator->mat[i][j];
			}
		};
		
	// Wait for the user to press Enter
	std::cout << "Press Enter to continue...";
	std::cin.get();

	SudokuSolver* sudokuSolver = new SudokuSolver();
	sudokuSolver->Solve(grid);

	// Wait for the user to press Enter
	std::cout << "Press Enter to continue...";
	std::cin.get();

	//
	return (0);
};
