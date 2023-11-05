//---------------------------------------------------------------------------
#include <vcl.h>
#include <string>
#pragma hdrstop

#include "Unit1.h"
#include <iostream>
#include <string>
#include "algorithm.h"

using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//extern "C" double __declspec(dllexport) __stdcall _setAlgorithm(unsigned long algorithmCode);

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   /* TODO (#3#): Iterative List */
   //IterativeList i;
   //i.Set(20);
   //Label1->Caption = UnicodeString(i.getTrace()).c_str();
   //Label1->Caption = UnicodeString( _setAlgorithm(1) ).c_str();

   /* TODO (#4#): Recursive List */
   //RecursiveList r;
   //r.Set(20);
   //Label2->Caption = UnicodeString(r.getTrace()).c_str();

   //Label2->Caption = UnicodeString( _setAlgorithm(2) ).c_str();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	// https://blogs.embarcadero.com/create-and-use-static-library-lib-and-dynamic-dlls-in-c-builder/

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


