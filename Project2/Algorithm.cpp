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
	vector<int> Algorithm::FisherYates(int count)
	{
	   //
	   //int* deck    = new int[count];
	   vector<int> deck;

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
		   int j              = dist(mt_1); /*rand.Next(count - i)*/;

		   //
		   //std::default_random_engine gen(std::chrono::system_clock::now().time_since_epoch().count());
		   //std::uniform_int_distribution<int> distribution(0, count - i);
		   //int j = distribution(gen);

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
