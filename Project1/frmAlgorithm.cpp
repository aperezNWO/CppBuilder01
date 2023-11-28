//---------------------------------------------------------------------------
#include <vcl.h>
#include <string>
#pragma hdrstop

#include "frmAlgorithm.h"
#include "Algorithm.h"
#include "Dijkstra.h"
#include "SortBenchMark.h"
#include "RegExManager.h"
#include "Sudoku.cpp"

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
	if ((fGetSort = (pfGetSort)GetProcAddress(CppMyDll, "SortBenchMark_GetSort_CPP")) == NULL) {
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
	   );

	   //
	   string result = uniquePtr->GetSort(p_sortAlgoritm).c_str();

	   //
	   lblSortBenchMark->Caption = result.c_str();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cmdRegExManagerClick(TObject *Sender)
{
	   //
	   std::unique_ptr<RegExManager> uniquePtr = std::make_unique<RegExManager>(
	   );
	   //
	   char *p_tagSearch      = (char*)"country";
	   char *p_textSearch     = (char*)"UK";
	   string result          = uniquePtr->RegExEval(p_tagSearch, p_textSearch);
	   vector<string> results = Algorithm::StringSplit(result.c_str(),"|");
	   //
	   this->lblRegExManager->Caption = results[0].c_str();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::cmdRegExManagerDLLClick(TObject *Sender)
{
	//
	HINSTANCE CppMyDll;
	typedef char*(__stdcall * pfRegExEval)(char* , char*);
	pfRegExEval fRegExEval;

	//
	if ((CppMyDll = LoadLibraryW(L"Algothtm.Library.dll")) == NULL) {
		//
		ShowMessage(L"Cannot load DLL!");
		return;
	}
	if ((fRegExEval = (pfRegExEval)GetProcAddress(CppMyDll, "RegExManager_RegExEval")) == NULL) {
		//
		ShowMessage(L"Cannot find DLL function!");
		return;
	}
	else
	{
	   //
	   char *p_tagSearch  = (char*)"country";
	   char *p_textSearch = (char*)"UK";
	   //
	   string result          = fRegExEval(p_tagSearch, p_textSearch);
	   vector<string> results = Algorithm::StringSplit(result.c_str(),"|");
	   //
	   this->lblRegExManager->Caption = results[0].c_str();
	   //
	   FreeLibrary(CppMyDll);
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cmdSudokuClick(TObject *Sender)
{
	//
	const static int   N = 9;
	int                K = 20;
	int grid[N][N];

	//
	SudokuGenerator* sudokuGenerator = new SudokuGenerator(N, K);
	sudokuGenerator->Run();

	//
	for (int i = 0; i < N; i++)
	{
		//
		for (int j = 0; j < N; j++) {
			   grid[i][j] = sudokuGenerator->mat[i][j];
		}

	};

	//
	SudokuSolver* sudokuSolver = new SudokuSolver();
	sudokuSolver->Solve(grid);

	//
	this->lblSudoku->Caption = "[Sudoku generated and solved]";
}

//---------------------------------------------------------------------------

void __fastcall TForm1::cmdSudokuGenerateClick(TObject *Sender)
{
	//
	const static int   N = 9;
	int                K = 20;

	//
	SudokuGenerator* sudokuGenerator = new SudokuGenerator(N, K);
	string           str_matrix      = sudokuGenerator->Run();
	const  char*     fileName        = "SudokuGenerated.txt";

	//
	FileManager* fileManager = new FileManager();
	//fileManager->DeleteFile(fileName);
	fileManager->SaveLineToFile(str_matrix, fileName);

	//
	this->lblSudoku->Caption = "[Sudoku generated]";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cmdSudokuSolveClick(TObject *Sender)
{
	//
	this->lblSudoku->Caption = "[Sudoku solved]";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cmdSudokuGenerateDLLClick(TObject *Sender)
{
	//
	HINSTANCE CppMyDll;
	typedef char*(__stdcall * pfSudokuGenerate)();
	pfSudokuGenerate fSudokuGenerate;

	//
	if ((CppMyDll = LoadLibraryW(L"Algothtm.Library.dll")) == NULL) {
		//
		ShowMessage(L"Cannot load DLL!");
		return;
	}
	if ((fSudokuGenerate = (pfSudokuGenerate)GetProcAddress(CppMyDll, "Sudoku_Generate_CPP")) == NULL) {
		//
		ShowMessage(L"Cannot find DLL function!");
		return;
	}
	else
	{
	   //
	   string str_matrix        = fSudokuGenerate();

	   //
	   const  char* fileName    = "SudokuGenerated_DLL.txt";
	   FileManager* fileManager = new FileManager();
	   fileManager->SaveLineToFile(str_matrix, fileName);

	   //
	   this->lblSudoku->Caption = "[Sudoku generated (DLL)]";

	   //
	   FreeLibrary(CppMyDll);
	 }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::cmdSudokuDLLSolveClick(TObject *Sender)
{
	//
	this->lblSudoku->Caption = "[Sudoku solved (DLL)]";

}
//---------------------------------------------------------------------------
