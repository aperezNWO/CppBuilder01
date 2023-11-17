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

          	//
	template <class T> int SaveVectorToFile(vector<T> array, const char* fileName)
	{
		// Open the file for appending
		std::ofstream outputFile;
		outputFile.open(fileName, std::ios::app);

		if (!outputFile.is_open()) {
			std::cerr << "Error opening file for appending." << std::endl;
			return 1;
		}

		// Write some content to the file
		for (auto _Item = array.begin(); _Item != array.end(); ++_Item)
		{
			//
			stringstream  ss;
			//
			ss << *_Item;
			//
			string Item     = ss.str();
			// Write some content to the file
			outputFile << Item << "\n";
		}
		// Close the file
		outputFile.close();

		return 0;
	};

