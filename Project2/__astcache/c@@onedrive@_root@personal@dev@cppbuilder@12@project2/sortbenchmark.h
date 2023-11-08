///////////////////////////////////////////////////////////////////////////
// ALGORITHM.LIBRARY.DLL
///////////////////////////////////////////////////////////////////////////

#ifndef SortBenchMark_H // include guard
#define SortBenchMark_H
#endif

#include <string>

using namespace std;

#pragma hdrstop
#pragma argsused

class SortBenchMark
{
	public  :
	   SortBenchMark();
	   ~SortBenchMark();
	   string	GetSort(int p_sortAlgoritm ,char* p_unsortedList);
};
