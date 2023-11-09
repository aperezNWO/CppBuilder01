#include "SortBenchMark.h"

	//
	SortBenchMark::SortBenchMark(char* p_randomValues, int p_arraySize)
	{
		//
		this->randomValues   = p_randomValues;
		this->arraySize      = p_arraySize;
		//
		for (int i = 0; i < this->arraySize; i++) {
			this->arreglo[i] = 0;
		}
		/*
		//-----------------------------------------------------
        // INICIAR ARREGLO
        //-----------------------------------------------------
        string[] randomValuesArray = randomValues.Split('|');
        //
        for (int i = 0; i < arraySize; i++)
        {
            //
            string randomValue = randomValuesArray[i];
            //
            arreglo[i] = Convert.ToInt32(randomValue);
            //
		}
		*/
	};
	//
	SortBenchMark::~SortBenchMark()
	{
		 //
	};
	//
	string SortBenchMark::GetSort(int p_sortAlgorithm, char* p_unsortedList)
	{
		//
		string randomPoints = (char*)"■<br/>0<br/>6<br/>18<br/>7<br/>4<br/>10<br/>2<br/>24<br/>5<br/>11<br/>15<br/>16<br/>23<br/>22<br/>17<br/>14<br/>21<br/>9<br/>13<br/>1<br/>3<br/>12<br/>8<br/>20<br/>19<br/>";
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

		/*
			//
			string sortedList = string.Empty;
			//
			foreach (string sortStep in am.SortSteps)
			{
				sortedList += string.Format("■|{0}|", sortStep);
			}
			//
			string sortedListEncoded = HttpUtility.HtmlEncode(sortedList).Replace("|", "<br/>");
			//
			status = sortedListEncoded;

			//
			return status;
		*/
		return randomPoints;
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
					  string separator = (j == 0) ? "" : "|";
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
				  string separator = (j == 0) ? "" : "|";
				  ss << separator << arreglo[j];
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
