///////////////////////////////////////////////////////////////////////////
// CLASS DIJKSTRA - METHOD IMPLEMENTATIONS
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// ALGORITHM.LIBRARY.DLL
// https://blogs.embarcadero.com/create-and-use-static-library-lib-and-dynamic-dlls-in-c-builder/
///////////////////////////////////////////////////////////////////////////

#include "Algorithm.h"
#include "Dijkstra.h"
#include "SortBenchMark.h"

	Algorithm::Algorithm()
	{
		 //
	}
	//
	Algorithm::~Algorithm()
	{

	}
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

	}
