#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <Sudoku.cpp>

//
int _tmain(int argc, _TCHAR* argv[])
{
	//
	int N                   = 9;
	int K                   = 20;
	SudokuGenerator* sudoku = new SudokuGenerator(N, K);
	sudoku->Run();

	// Wait for the user to press Enter
	std::cout << "Press Enter to continue...";
	std::cin.get();

	SudokuSolver* sudokuSolver = new SudokuSolver();
	sudokuSolver->Run();

	// Wait for the user to press Enter
	std::cout << "Press Enter to continue...";
	std::cin.get();

	//
	return (0);
};
