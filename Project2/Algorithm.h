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
#include <regex>
#include <map>
#include <cctype>

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
			static int                SaveLineToFile(string p_value, const char* filename);
			template <typename U> int SaveVectorToFile(vector<U> array, const char* fileName);
			static int                DeleteFile(const char* filePath);
			//
			int            ReadConfigFile();
			vector<int>    FisherYates(int count);
	   public :
		  //
		  std::mt19937       mt_1;
		  //
		  std::mt19937       mt_2;
		  //
		  std::map<std::string, std::string> configMap;
};

