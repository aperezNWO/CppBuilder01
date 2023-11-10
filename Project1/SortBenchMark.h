///////////////////////////////////////////////////////////////////////////
// ALGORITHM.LIBRARY.DLL
///////////////////////////////////////////////////////////////////////////

#ifndef SortBenchMark_H // include guard
#define SortBenchMark_H
#endif

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#pragma hdrstop
#pragma argsused

class SortBenchMark
{
	public  :
	   SortBenchMark(char* p_randomValues, int p_arraySize);
	   ~SortBenchMark();
	   vector<string> StringSplit(const char* p_inputString, std::string p_delimiter);
       int            SaveToFile(string p_value);
	   string	      GetSort(int p_sortAlgoritm);
	   void           BubbleSort();
	   void           QuickSort();
	   void           Quick_Sort(vector<int> arr, int left, int right);
	   int            Partition(vector<int> arr, int left, int right);
	public  :
	   vector<int>      arreglo;
	   vector<string>   arreglo_str;
	   vector<string>   sortSteps;
	   char* randomValues;
	   int   arraySize;
};
