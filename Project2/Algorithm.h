///////////////////////////////////////////////////////////////////////////
// ALGORITHM.WINFORMS.DLL
///////////////////////////////////////////////////////////////////////////

#ifndef Algorithm_H // include guard
#define Algorithm_H
#endif

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <memory>
#include <random>

#define DLL_EXPORT __declspec(dllexport) __stdcall
#pragma once

using namespace std;

#pragma hdrstop
#pragma argsused

class Algorithm
{
	   public:
			Algorithm();
			~Algorithm();
			vector<string> StringSplit(const char* p_inputString, std::string p_delimiter);
			int            SaveToFile(string p_value, const char* filename);
			int            SetFile_int(int* array, int arraySize, char* fileName);
			int            SetFile_char(char** array, int arraySize, char* fileName);
			vector<int>    FisherYates(int count);
	   public :
       	  //
		  std::mt19937       mt_1;
		  //
		  std::mt19937       mt_2;
};

