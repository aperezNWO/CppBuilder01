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
#include <algorithm>

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
       void           SaveStep(int arr[]);
	   string	      GetSort(int p_sortAlgoritm);
	   void           QuickSort();
	   int            partition(int arr[],int low,int high);
	   void           quickSort(int arr[],int low,int high);
	   void           BubbleSort();
	public  :
	   vector<int>      arreglo;
	   vector<string>   arreglo_str;
	   vector<string>   sortSteps;
	   char* randomValues;
	   int   arraySize;
};
