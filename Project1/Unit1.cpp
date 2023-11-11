//---------------------------------------------------------------------------
#include <vcl.h>
#include <string>
#pragma hdrstop

#include "Unit1.h"
#include <iostream>
#include <string>
#include "Dijkstra.h"
#include "SortBenchMark.h"

using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	 //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	  //
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	HINSTANCE CppMyDll;
	typedef char*(__stdcall * pfSum)(int, int, char*);
	pfSum Sum;

	if ((CppMyDll = LoadLibraryW(L"Algothtm.Library.dll")) == NULL) {
		ShowMessage(L"Cannot load DLL!");
		return;
	}
	if ((Sum = (pfSum)GetProcAddress(CppMyDll, "Run")) == NULL) {
		ShowMessage(L"Cannot find DLL function!");
		return;
	}  else
	{
	   //
	   int param_1   = 1;
	   int param_2   = 2;
	   char *param_3 = (char*)"OK";
	   //
	   char* result = Sum(param_1, param_2,param_3);
	   //
	   //lblSum->Caption = UnicodeString(result).c_str();
	   //
	   FreeLibrary(CppMyDll);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cmdGetRandomVertexClick(TObject *Sender)
{
	int p_vertexSize  = 9;
	int p_sourcePoint = 0;

	Dijkstra d;

	string result = d.GetRandomPoints(p_vertexSize,p_sourcePoint);

	//
	lblGetRandomVertex->Caption = result.c_str();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::cmdCallDLLClick(TObject *Sender)
{
	//
	HINSTANCE CppMyDll;
	typedef char*(__stdcall * pfGetRandomVertex)(int, int);
	pfGetRandomVertex fGetRandomVertex;

	//
	if ((CppMyDll = LoadLibraryW(L"Algothtm.Library.dll")) == NULL) {
		//
		ShowMessage(L"Cannot load DLL!");
		return;
	}
	if ((fGetRandomVertex = (pfGetRandomVertex)GetProcAddress(CppMyDll, "Dijkstra_GenerateRandomVertex_CPP")) == NULL) {
		//
		ShowMessage(L"Cannot find DLL function!");
		return;
	}
	else
	{
	   //
	   int p_vertexSize     = 9;
	   int p_sourcePoint    = 0;
	   //
	   char* result = fGetRandomVertex(p_vertexSize, p_sourcePoint);
	   //
	   lblGetRandomVertex->Caption = UnicodeString(result).c_str();
	   //
	   FreeLibrary(CppMyDll);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cmdSortBenchMarkClick(TObject *Sender)
{
	//
	HINSTANCE CppMyDll;
	typedef char*(__stdcall * pfGetSort)(int, char*);
	pfGetSort fGetSort;

	//
	if ((CppMyDll = LoadLibraryW(L"Algothtm.Library.dll")) == NULL) {
		//
		ShowMessage(L"Cannot load DLL!");
		return;
	}
	if ((fGetSort = (pfGetSort)GetProcAddress(CppMyDll, "SortBenchMark_GetSort")) == NULL) {
		//
		ShowMessage(L"Cannot find DLL function!");
		return;
	}
	else
	{
	   //
	   int   p_sortAlgorithm     = 1;
	   char* p_unsortedList      = (char*)"3|6|18|7|4|10|2|24|5|11|15|16|23|22|17|14|21|9|13|1|0|12|8|20|19";
	   //
	   char* result = fGetSort(p_sortAlgorithm, p_unsortedList);
	   //
	   lblSortBenchMark->Caption = UnicodeString(result).c_str();
	   //
	   FreeLibrary(CppMyDll);
	 }
};
//---------------------------------------------------------------------------

void __fastcall TForm1::cmdGetSortBenchMarkClick(TObject *Sender)
{
	   //
	   int   ARRAY_SIZE          = 25;
	   int   p_sortAlgorithm     = 1;
	   char* p_unsortedList      = (char*)"3|6|18|7|4|10|2|24|5|11|15|16|23|22|17|14|21|9|13|1|0|12|8|20|19";
	   int   p_sortAlgoritm      = 1;

	   //
	   std::unique_ptr<SortBenchMark> uniquePtr = std::make_unique<SortBenchMark>(
				  p_unsortedList
				, ARRAY_SIZE
	   );

	   //
	   string result = uniquePtr->GetSort(p_sortAlgoritm).c_str();

	   //
	   lblSortBenchMark->Caption = result.c_str();
}
//---------------------------------------------------------------------------



