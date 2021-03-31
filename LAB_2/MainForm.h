//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TMemo *Memo1;
	TMemo *Memo2;
	TDateTimePicker *DateTimePicker1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TMemo *Memo4;
	TComboBox *comb;
	TComboBox *comb2;
	TLabeledEdit *LabeledEdit1;
	TComboBox *comb3;
	TLabeledEdit *LabeledEdit2;
	TLabeledEdit *LabeledEdit3;
	TMemo *Memo3;
	TButton *Button4;
	TFileOpenDialog *FileOpenDialog1;
	TButton *Button5;
	void __fastcall DateTimePicker1CloseUp(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
