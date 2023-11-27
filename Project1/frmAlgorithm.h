//---------------------------------------------------------------------------

#ifndef frmAlgorithmH
#define frmAlgorithmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *lblGetRandomVertex;
	TButton *cmdGetRandomVertex;
	TButton *cmdCallDLL;
	TButton *cmdSortBenchMark;
	TLabel *lblSortBenchMark;
	TButton *cmdGetSortBenchMark;
	TLabel *lblRegExManager;
	TButton *cmdRegExManagerDLL;
	TButton *cmdRegExManager;
	TLabel *lblSudoku;
	TButton *cmdSudokuGenerateDLL;
	TButton *cmdSudoku;
	TButton *cmdSudokuGenerate;
	TButton *cmdSudokuSolve;
	TButton *cmdSudokuDLLSolve;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cmdGetRandomVertexClick(TObject *Sender);
	void __fastcall cmdCallDLLClick(TObject *Sender);
	void __fastcall cmdSortBenchMarkClick(TObject *Sender);
	void __fastcall cmdGetSortBenchMarkClick(TObject *Sender);
	void __fastcall cmdRegExManagerClick(TObject *Sender);
	void __fastcall cmdRegExManagerDLLClick(TObject *Sender);
	void __fastcall cmdSudokuClick(TObject *Sender);
	void __fastcall cmdSudokuGenerateDLLClick(TObject *Sender);
	void __fastcall cmdSudokuGenerateClick(TObject *Sender);
	void __fastcall cmdSudokuSolveClick(TObject *Sender);
	void __fastcall cmdSudokuDLLSolveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
