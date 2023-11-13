﻿///////////////////////////////////////////////////////////////////////////
// CLASS DIJKSTRA - METHOD IMPLEMENTATIONS
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// ALGORITHM.LIBRARY.DLL
// https://blogs.embarcadero.com/create-and-use-static-library-lib-and-dynamic-dlls-in-c-builder/
///////////////////////////////////////////////////////////////////////////

#include "Algorithm.h"
#include "Dijkstra.h"
#include "SortBenchMark.h"
#include "RegExManager.h"

	Algorithm::Algorithm()
	{
		 //
	}
	//
	Algorithm::~Algorithm()
	{
		//
	}
	//
	string Algorithm::HtmlEncode(const std::string& input)
	{
		//
		std::ostringstream encoded;
		//
		for (char c : input) {
			switch (c) {
				case '&': encoded << "&amp;";
					break;
				case '<': encoded << "&lt;";
					break;
				case '>': encoded << "&gt;";
					break;
				case '\"': encoded << "&quot;";
					break;
				case '\'': encoded << "&apos;";
					break;
				case '\n': encoded << "<br/>";
					break;
				case '\t': encoded << "&nbsp;";
					break;
				case '[': encoded << "<mark>";
					break;
				case ']': encoded << "</mark>";
					break;
				case '~': encoded << "&nbsp;";
					break;
				default: encoded << c;
			}
		}
		return encoded.str();
	}
	//
	int Algorithm::ReadConfigFile()
	{
		 // Open the configuration file
		std::ifstream configFile("Algorithm.ini");

		// Check if the file is opened successfully
		if (!configFile.is_open()) {
			std::cerr << "Error opening the configuration file." << std::endl;
			return 1;
		}

		// Read the file line by line
		std::string line;
		while (std::getline(configFile, line)) {
			// Skip empty lines or lines starting with '#' (comments)
			if (line.empty() || line[0] == '#') {
				continue;
			}

			// Split the line into key and value
			std::istringstream iss(line);
			std::string key, value;
			if (std::getline(iss, key, '=') && std::getline(iss, value))
			{
				// Trim leading and trailing whitespaces from key and value
				key.erase(0, key.find_first_not_of(" \t"));
				key.erase(key.find_last_not_of(" \t") + 1);
				value.erase(0, value.find_first_not_of(" \t"));
				value.erase(value.find_last_not_of(" \t") + 1);

				// Insert key-value pair into the map
				this->configMap[key] = value;
			}
		}

		// Close the configuration file
		configFile.close();

		//
		return 0;
	}
	//
	string Algorithm::StringTrim(const std::string& str)
	{
        //
		size_t start = str.find_first_not_of(" \t\n\r");   // Find the first non-whitespace character
		size_t end   = str.find_last_not_of(" \t\n\r");    // Find the last non-whitespace character
		//
		if (start == std::string::npos || end == std::string::npos) {
			// The string is empty or contains only whitespaces
			return "";
		}
		//
		return str.substr(start, end - start + 1);
	};
	//
	vector<string> Algorithm::StringSplit(const char* p_inputString, std::string p_delimiter)
	{
		//
		std::string s(p_inputString);
		//
		std::vector<std::string> outputArr;
		size_t pos = 0;
		std::string token;
		//
		while ((pos = s.find(p_delimiter)) != std::string::npos) {
			token = s.substr(0, pos);
			s.erase(0, pos + p_delimiter.length());
			outputArr.push_back(token);
		}
		outputArr.push_back(s);
		//
		return outputArr;
	};
	//
	int Algorithm::SaveToFile(string p_value, const char* filename)
	{
			// Open the file for appending
			std::ofstream outputFile;
			outputFile.open(filename, std::ios::app);

			if (!outputFile.is_open()) {
				std::cerr << "Error opening file for appending." << std::endl;
				return 1;
			}

			// Write some content to the file
			outputFile << p_value << "\n";

			// Close the file
			outputFile.close();

			//std::cout << "Content appended to the file." << std::endl;

			return 0;
	}
	//
	int Algorithm::SetFile_int(int* array, int arraySize, char* fileName)
	{
		// declaration of file pointer
		FILE* fp = NULL;
		// declaration of variable
		int x;
		// opening of file
		fopen_s(&fp, fileName, "w+");
		// checking of error
		if (!fp)
			return 1;
		// giving content
		for (int i = 0; i < arraySize; i++)
			fprintf(fp, "%d\n", array[i]);
		// closing of file
		fclose(fp);
		//
		return 0;
	}
	//
	int Algorithm::SetFile_char(char** array, int arraySize, char* fileName)
	{
		// declaration of file pointer
		FILE* fp = NULL;
		// opening of file
		fopen_s(&fp, fileName, "w+");
		// checking of error
		if (!fp)
			return 1;
		// giving content
		for (int i = 0; i < arraySize; i++)
			fprintf(fp, "%s\n", array[i]);
		// closing of file
		fclose(fp);
		//
		return 0;
	}
	//
	int Algorithm::DeleteFile(const char* filePath)
	{
		// Attempt to delete the file
		if (std::remove(filePath) != 0) {
			std::cerr << "Error deleting file: " << filePath << std::endl;
			return 1; // Return an error code
		}
		//
		std::cout << "File deleted successfully: " << filePath << std::endl;
		//
		return 0;
	}
	//
	vector<int> Algorithm::FisherYates(int count)
	{
	   //
	   vector<int> deck;

	   //
	   for (short i = 0; i < count; i++)
	   {
			deck.push_back(i);
	   }

	   //
	   for (short i = 0; i <= count - 2; i++)
	   {
		   // Create a random number generator engine
		   std::random_device rd_1;    // Seed the generator with a random value om a hardware device
		   this->mt_1               = std::mt19937(rd_1());
		   std::uniform_int_distribution<int> dist(0, count - i);
		   int j                    = dist(mt_1);

		   //
		   if (j > 0)
		   {
			   int curVal  = deck[i];
			   deck[i]     = deck[i + j];
			   deck[i + j] = curVal;
		   }
	   }
	   //
	   for (short i = count - 1; i >= 1; i--)
	   {
		   // Seed the generator with a random value om a hardware device
		   std::random_device rd_2;
		   this->mt_2         = std::mt19937(rd_2());
		   std::uniform_int_distribution<int> dist(0, i + 1);
		   int j              = dist(mt_2);

		   //
		   if (j != i)
		   {
			   int curVal = deck[i];
			   deck[i]    = deck[j];
			   deck[j]    = curVal;
		   }
	   }
	   //
	   return deck;
	}
	///////////////////////////////////////////////////////////////////////////
	// ENTRY POINTS
	///////////////////////////////////////////////////////////////////////////
	extern "C"
	{
		// DUJKSTRA
		DLL_EXPORT const char* Dijkstra_GenerateRandomVertex_CPP(int p_vertexSize, int p_sourcePoint)
		{
			//
			std::unique_ptr<Dijkstra> uniquePtr = std::make_unique<Dijkstra>();
			//
			return uniquePtr->GetRandomPoints(p_vertexSize, p_sourcePoint).c_str();
		};

		//"http://localhost:83/demos/_GetSort?p_sortAlgoritm=1&p_unsortedList=13|3|9|10|19|16|0|2|18|20|24|23|7|5|12|1|21|4|22|15|6|8|14|11|17" succeeded in 143 ms.
		// SORT BENCHMARK
		DLL_EXPORT const char* SortBenchMark_GetSort_CPP(int p_sortAlgoritm, char* p_unsortedList)
		{
			//
			int ARRAY_SIZE      = 25;
			//
			std::unique_ptr<SortBenchMark> uniquePtr = std::make_unique<SortBenchMark>(
					  p_unsortedList
					, ARRAY_SIZE
			);
			return uniquePtr->GetSort(p_sortAlgoritm).c_str();
		};
		// http://localhost:83/demos/_RegExEval?p_tagSearch=company&p_textSearch=bmg
        // REGULAR EXPRESSIONS
		DLL_EXPORT const char*  RegExManager_RegExEval(char* p_tagSearch, char* p_textSearch)
		{
			//
			std::unique_ptr<RegExManager> uniquePtr = std::make_unique<RegExManager>();
			//
			return uniquePtr->RegExEval(p_tagSearch, p_textSearch).c_str();
		}
	}
