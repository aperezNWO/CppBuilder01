//https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
// C++ recursive function to
// solve tower of hanoi puzzle
// This is code is contributed by rathbhupendra

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

class Hanoi
{
    //
	void towerOfHanoi(int n, char from_rod, char to_rod,
					char aux_rod)
	{
		if (n == 0) {
			return;
		}
		towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
		cout << "Move disk " << n << " from rod " << from_rod
			<< " to rod " << to_rod << endl;
		towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
	}
public :
	// Driver code
	int Run()
	{
		int N = 3;

		// A, B and C are names of rods
		towerOfHanoi(N, 'A', 'C', 'B');

		// Wait for the user to press Enter
		std::cout << "Press Enter to continue...";
		std::cin.get();

		return 0;
	};
};

void HanoiTest()
{
	//
	Hanoi* hanoi = new Hanoi();
	hanoi->Run();
}


