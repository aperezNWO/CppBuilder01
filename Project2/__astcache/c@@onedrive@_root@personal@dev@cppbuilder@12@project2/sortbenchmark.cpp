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
				  //string separator = "■";
		          string separator = "~";
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
		//Quick_Sort(arreglo, 0, this->arraySize - 1);

		//----------------------------------------------------
		// CONFIGURAR VALORES INICIALES
		//-----------------------------------------------------
		//
		int* _arreglo     = new int[this->arraySize];
		//
		for (int i = 0; i < this->arraySize; i++) {
			  _arreglo[i] = arreglo[i];
		}

		//----------------------------------------------------
		// INGRESAR A RECURSION
		//-----------------------------------------------------
		quickSort(_arreglo,0 , this->arraySize - 1);

		//----------------------------------------------------
		// IMPRIMIR VALOR FINAL
		//-----------------------------------------------------
		//
		string tempValues = "";
		//
		for (int index = 0; index < this->arraySize; index++)
		{
		  //
		  stringstream  ss;
		  //
		  string separator = (index == 0) ? "" : "<br/>";
		  ss << separator << _arreglo[index];
		  //
		  string _tempValues  = ss.str();
		  //
		  tempValues          += _tempValues;
		}
		//
		this->sortSteps.push_back(tempValues);
	}
	//
	int SortBenchMark::partition(int arr[],int low,int high)
	{
	  //choose the pivot
	  int pivot=arr[high];
	  //Index of smaller element and Indicate
	  //the right position of pivot found so far
	  int i=(low-1);
	  //
	  for(int j=low;j<=high;j++)
	  {
		  //If current element is smaller than the pivot
		  if(arr[j]<pivot)
		  {
			//Increment index of smaller element
			i++;
			std::swap(arr[i],arr[j]);

				//----------------------------------------------------
				// IMPRIMIR PASO INTERMEDIO
				//-----------------------------------------------------
				//
				string tempValues = "";
				for (int index = 0; index < this->arraySize; index++)
				{
				  //
				  stringstream  ss;
				  //
				  string separator = (index == 0) ? "" : "<br/>";
				  ss << separator << arr[index];
				  //
				  string _tempValues  = ss.str();
				  //
				  tempValues          += _tempValues;
				}
				//
				this->sortSteps.push_back(tempValues);
		  }
	  }
	  //
	  std::swap(arr[i+1],arr[high]);
	  //
	  return (i+1);
	}
	// The Quicksort function Implement
	void SortBenchMark::quickSort(int arr[],int low,int high)
	{
	  // when low is less than high
	  if(low<high)
	  {
		// pi is the partition return index of pivot

		int pi=partition(arr,low,high);

		//Recursion Call
		//smaller element than pivot goes left and
		//higher element goes right
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	  }
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
		   for (int sort = 0; sort < this->arraySize - 1; sort++)
		   {
			   //
			   if (arreglo[sort] > arreglo[sort + 1])
			   {
				   //
				   temp              = arreglo[sort + 1];
				   arreglo[sort + 1] = arreglo[sort];
				   arreglo[sort]     = temp;

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

