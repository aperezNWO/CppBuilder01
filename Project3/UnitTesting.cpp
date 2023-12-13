#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <Sudoku.cpp>

//
int TestGame(string title, int option)
{
	//
	char cont='y';

	//
	do
	{
		//
		system("cls");
		std::cout << title << endl;

		//
		switch (option) {
			case 1:
				SudokuTest();
			break;
		default:
			;
		};

		//
		cout << endl << "Do you want to continue? (y/n) : ";
		cin  >> cont;

	} while (cont == 'y');


	//
	return (0);
}
//
int _tmain(int argc, _TCHAR* argv[])
{

	//
	int option = 0;
	//
	do {
		//
		system("cls");

		//
		cout<<"[UNIT TESTING] "   << endl;
		//
		cout << "Choose option :" << endl;
		cout << endl;
		cout << "1. Sudoku."      << endl;
		cout << "2. Tic Tac Toe." << endl;
		cout << "3. Hanoi."       << endl;
		cout << "4. Exit."        << endl;
		cout << "Enter Option : ";
		cin  >> option;

		//
		switch (option) {
			case 1:
				TestGame("[SUDOKU GAME TEST]",option);
			break;
		default:
			;
		};

	}   while(option != 4);

};
