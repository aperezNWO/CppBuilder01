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
};

