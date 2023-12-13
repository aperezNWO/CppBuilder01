#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <Sudoku.cpp>
#include <TicTacToe.cpp>
#include <Hanoi.cpp>

enum class Option
{
	Continue  = 0,
	Sudoku    = 1,
	TicTacToe = 2,
	Hanoi     = 3,
	Exit      = 4,
};

//
int TestGame(string title, Option option)
{
	//
	char cont='y';
	//
	do
	{
		//
		system("cls");
		std::cout << "["<< title << " GAME TEST] " << endl;

		//
		switch (option) {
			case Option::Sudoku:
				SudokuTest();
			break;
			case Option::TicTacToe:
				TicTacToeTest();
			break;
			case Option::Hanoi:
				HanoiTest();
            		break;
		default:
			;
		};

		//
		cout << endl << "Play "<< title << " Again ? " << " (y/n) : ";
		cin  >> cont;

	} while (cont == 'y');

	//
	return (0);
}
//
int _tmain(int argc, _TCHAR* argv[])
{

	//
	Option option     = Option::Continue;
	int  optionNumber = 0;

	//
	do {
		//
		system("cls");
		//
		cout<<"[UNIT TESTING] "   << endl;
		//
		cout << "Choose option :" << endl;
		cout << endl;
		//
		cout << "1. Sudoku."      << endl;
		cout << "2. Tic Tac Toe." << endl;
		cout << "3. Hanoi."       << endl;
		cout << "4. Exit."        << endl;
		cout << "Enter Option : ";
		cin  >> optionNumber;

		option = static_cast<Option>(optionNumber);

		//
		switch (option) {
			case Option::Sudoku:    // sudoku
				TestGame("SUDOKU"       , option);
			break;
			case Option::TicTacToe: // tictaktoe
				TestGame("TIC TAC TOE"  , option);
			break;
			case Option::Hanoi :    // hanoi
				TestGame("Hanoi Towers" , option);
            		break;
		default:
			;
		};

	}   while(option != Option::Exit);

};
