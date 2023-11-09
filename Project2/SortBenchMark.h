///////////////////////////////////////////////////////////////////////////
// ALGORITHM.LIBRARY.DLL
///////////////////////////////////////////////////////////////////////////

#ifndef SortBenchMark_H // include guard
#define SortBenchMark_H
#endif

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#pragma hdrstop
#pragma argsused

class SortBenchMark
{
	public  :
	   SortBenchMark(char* p_randomValues, int p_arraySize);
	   ~SortBenchMark();
	   string	GetSort(int p_sortAlgoritm ,char* p_unsortedList);
	   void     BubbleSort();
	   void     QuickSort();
	   void     Quick_Sort(vector<int> arr, int left, int right);
	   int      Partition(vector<int> arr, int left, int right);
	public  :
	   vector<int> arreglo;
	   vector<string> sortSteps;
	   char* randomValues;
	   int   arraySize;
};
