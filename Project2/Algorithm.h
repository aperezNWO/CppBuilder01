///////////////////////////////////////////////////////////////////////////
// ALGORITHM.WINFORMS.DLL
///////////////////////////////////////////////////////////////////////////

#ifndef Algorithm_H // include guard
#define Algorithm_H
#endif

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <random>
#include <regex>
#include <cctype>
#include <map>

#define DLL_EXPORT __declspec(dllexport) __stdcall
#pragma once

//
using namespace std;

#pragma hdrstop
#pragma argsused

//

class Algorithm
{
	   public :
			//
			Algorithm();
			~Algorithm();
			//
			static string             HtmlEncode(const std::string& input);
			static string             StringTrim(const std::string& str);
			static vector<string>     StringSplit(const char* p_inputString, std::string p_delimiter);
			vector<int>               FisherYates(int count, vector<int> deck);
			int                       ReadConfigFile();
	   public :
		  //
		  map<string, string> configMap;
};



