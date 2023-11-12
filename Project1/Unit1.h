//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
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
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall cmdGetRandomVertexClick(TObject *Sender);
	void __fastcall cmdCallDLLClick(TObject *Sender);
	void __fastcall cmdSortBenchMarkClick(TObject *Sender);
	void __fastcall cmdGetSortBenchMarkClick(TObject *Sender);
	void __fastcall cmdRegExManagerClick(TObject *Sender);
	void __fastcall cmdRegExManagerDLLClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
