#include "SortBenchMark.h"


	//
	SortBenchMark::SortBenchMark(char* p_randomValues, int p_arraySize)
	{
		//
		this->randomValues   = p_randomValues;
		this->arraySize      = p_arraySize;

		//-----------------------------------------------------
		// INICIAR ARREGLO
		//-----------------------------------------------------
		this->arreglo_str = StringSplit(p_randomValues,"|");
		for (int i = 0; i < this->arraySize; i++) {
			//
			this->arreglo.push_back( std::stoi(this->arreglo_str[i] ) );
		}
	};
	//
	SortBenchMark::~SortBenchMark()
	{
		 //
	};
	//
	vector<string> SortBenchMark::StringSplit(const char* p_inputString, std::string p_delimiter)
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
	}
	//
	int SortBenchMark::SaveToFile(string p_value)
	{
		const char* filename = "SortBenchMark.txt";

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
	string SortBenchMark::GetSort(int p_sortAlgorithm)
	{
		//
		switch (p_sortAlgorithm)
		{
			case 1: // BUBBLE SORT
				this->BubbleSort();
				break;
			case 2: // QUICK SORT
				this->QuickSort();
				break;
		};

		//
		string sortedList = "";
		// Using iterators
		for (auto sortStep = this->sortSteps.begin(); sortStep != this->sortSteps.end(); ++sortStep) {
				  //std::cout << "Element: " << *it << std::endl;
				  stringstream  ss;
				  //
				  string separator = "■";
				  ss << separator << "<br/>" << *sortStep << "<br/>";
				  //
				  string _tempValues  = ss.str();
				  //
				  SaveToFile(_tempValues.c_str());
				  //
				  sortedList          += _tempValues;

		}

		//
		return sortedList;
	};
	//
	void SortBenchMark::QuickSort()
	{
	   Quick_Sort(arreglo, 0, this->arraySize - 1);
	}
	//
	void SortBenchMark::BubbleSort()
	{
		//
	   int temp = 0;
	   //
	   for (int write = 0; write < this->arraySize; write++)
	   {
		   //
		   for (int sort = 0; sort < this->arraySize; sort++)
		   {
			   //
			   if (arreglo[sort] > arreglo[sort + 1])
			   {
				   //
				   temp = arreglo[sort + 1];
				   arreglo[sort + 1] = arreglo[sort];
				   arreglo[sort] = temp;

				  //-----------------------------------------------------
				  // GUARDAR PASO DEL ARREGLO EN MATRIZ DE PASOS
				  //-----------------------------------------------------
				  //
				  string tempValues = "";
				  //
				  for (int j = 0; j < this->arraySize; j++)
				  {
					  //
					  stringstream  ss;
					  //
					  string separator = (j == 0)? "" : "<br/>";
					  ss << separator << arreglo[j];
					  //
					  string _tempValues  = ss.str();
					  //
					  tempValues          += _tempValues;
				  }
				  //
				  this->sortSteps.push_back(tempValues);
			   }
		   }
	   }
	}
	//
	void SortBenchMark::Quick_Sort(vector<int> arr, int left, int right)
	{
		 //
		 if (left < right)
		 {
			 //
			 int pivot = Partition(arr, left, right);
			 //
			 if (pivot > 1)
			 {
				 Quick_Sort(arr, left, pivot - 1);
			 }
			 if (pivot + 1 < right)
			 {
				 Quick_Sort(arr, pivot + 1, right);
			 }
		 }
	}
	//
	int SortBenchMark::Partition(vector<int> arr, int left, int right)
	{
	  //
	  int pivot = arr[left];
	  //
	  while (true)
	  {
		  while (arr[left] < pivot)
		  {
			  left++;
		  }

		  while (arr[right] > pivot)
		  {
			  right--;
		  }

		  if (left < right)
		  {
			  if (arr[left] == arr[right]) return right;

			  int temp   = arr[left];
			  arr[left]  = arr[right];
			  arr[right] = temp;

			  //-----------------------------------------------------
			  // GUARDAR PASO DEL ARREGLO EN MATRIZ DE PASOS
			  //-----------------------------------------------------
			  //
			  string tempValues = "";
			  //
			  for (int j = 0; j < this->arraySize; j++)
			  {
				  //
				  stringstream  ss;
				  //
				  string separator = (j== 0) ? "" : "<br/>";
				  ss << separator << arr[j];
				  //
				  string _tempValues  = ss.str();
				  //
				  tempValues          += _tempValues;
			  }
			  //
			  this->sortSteps.push_back(tempValues);
		  }
		  else
		  {
			  return right;
		  }
	  }
	}
