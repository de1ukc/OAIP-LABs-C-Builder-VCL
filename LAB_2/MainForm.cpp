//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "KrankenHause.h"
TForm1 *Form1;
doctors * a = new doctors[4];
talon * b = new talon [100];
static int counter=0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
comb->DoubleBuffered = true;
comb->AutoComplete = true;
//Adding items to the combo box
comb->AddItem("Therapist",NULL);
comb->AddItem("Neurologist",NULL);
comb->AddItem("Optometrist",NULL);
//Setting the default value
//comb->ItemIndex = 1;
comb2->DoubleBuffered = true;
comb2->AutoComplete = true;
//Adding items to the combo box
comb2->AddItem("1",NULL);
comb2->AddItem("2",NULL);
comb2->AddItem("3",NULL);
comb2->AddItem("4",NULL);
//Setting the default value
//comb2->ItemIndex = 0;
comb3->DoubleBuffered = true;
comb3->AutoComplete = true;
//Adding items to the combo box

}
//---------------------------------------------------------------------------
void __fastcall TForm1::DateTimePicker1CloseUp(TObject *Sender)
{
TStringList * ts2 = new TStringList();
 //Memo2->Lines->Add(dt+0.25/24);
 for (int i = 0; i <= 7; i++) {
 int day=(DateTimePicker1->Date.DayOfWeek()+5+i )%7;
 if(day != 5 && day != 6){
 ts2->Add(FormatDateTime("dd.mm.yyyy", DateTimePicker1->Date+i));
 for (int j = 0; j < 3; j++) {
 TDateTime dt =DateTimePicker1->DateTime.FormatString(a[j].priem_fr);
 ts2->Add(a[j].specialisation);
 for (int k = 0; k < 4; k++) {
 ts2->Add("Talon No. " + (String)(k+1));
 ts2->Add(dt+0.25/24*k);
 ts2->Add(dt+0.25/24*(k+1));
 ts2->Add("\n");	 
 }
 }
 }
 }
 comb3->Clear();
 for (int i = 0; i <= 7; i++)
{
 int day=(DateTimePicker1->Date.DayOfWeek()+5+i )%7;
 if(day != 5 && day != 6){
comb3->AddItem(FormatDateTime("dd.mm.yyyy", DateTimePicker1->Date+i),NULL);
}
 }
 Memo2->Lines=ts2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{ if (FileOpenDialog1->Execute()) {

TFileStream * tfile = new TFileStream(FileOpenDialog1->FileName, fmOpenReadWrite);
//TFileStream * tfile = new TFileStream("D:/New_embarcadero(projects)/SEM_2/LABS/LAB_2/Doctors.txt", fmOpenReadWrite);
 TStringList * ts = new TStringList();
 TStringList * ts1 = new TStringList();
 ts->LoadFromStream(tfile);
 a->Zapis(ts,(ts->Count)/9, a);
 a->vivod(ts1,(ts->Count)/9, a);
 Memo1->Lines = ts1;
 //TDateTime dt = DateTimePicker1->DateTime.FormatString(a[0].priem_fr);
 //Memo2->Lines->Add(dt+0.25/24);
 tfile->Free();
 Memo2->Clear();
 Memo3->Clear();
 Memo4->Clear();
 delete ts;
 delete ts1;
}
else{}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{ bool k=0;
if(counter==0)
{
b[counter].Data = comb3->Text;
b[counter].nomer_talona = comb2->Text;
b[counter].name = LabeledEdit1->Text;
TDateTime dt = DateTimePicker1->DateTime.FormatString(a[comb->ItemIndex].priem_fr);
b[counter].time = dt+0.25/24*StrToInt(b[counter].nomer_talona);
b[counter].doctor = comb->Text;
ShowMessage (b[counter].Data +" " + b[counter].nomer_talona +" "+ b[counter].name +" " + b[counter].time +" "+ b[counter].doctor );
counter++;
}
else
{
b[counter].Data = comb3->Text;
b[counter].nomer_talona = comb2->Text;
b[counter].name = LabeledEdit1->Text;
TDateTime dt = DateTimePicker1->DateTime.FormatString(a[comb->ItemIndex].priem_fr);
b[counter].time = dt+0.25/24*StrToInt(b[counter].nomer_talona);
b[counter].nomer_kabineta=a[comb->ItemIndex].nomer_kabineta;
b[counter].doctor = comb->Text;
for(int i = 0; i < counter; i++)
if(b[counter].Data==b[i].Data&&b[counter].nomer_talona==b[i].nomer_talona&&b[counter].doctor==b[i].doctor)
{ShowMessage ("������ ����� ��� �������������, �������� , ����������, ������"); k=1;}

if(k==0){
ShowMessage (b[counter].Data +" " + b[counter].nomer_talona +" "+ b[counter].name +" " + b[counter].time +" "+ b[counter].doctor );
counter++;
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{  Memo3->Clear();
   for (int i = 0; i < counter; i++) {
		

 if (LabeledEdit2->Text == b[i].name) {
 Memo3->Lines->Add("Talon No." + (b[i].nomer_talona));
 Memo3->Lines->Add(b[i].name);
 Memo3->Lines->Add(b[i].Data);
 Memo3->Lines->Add(b[i].time);
 Memo3->Lines->Add(b[i].doctor);
 Memo3->Lines->Add("Kabinet No." +b[i].nomer_kabineta);
 Memo3->Lines->Add("\n");
  
 
	 
 }
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Memo4->Clear();
   for (int i = 0; i < counter; i++) {


 if (LabeledEdit3->Text == b[i].doctor) {
 Memo4->Lines->Add("Talon No." + (b[i].nomer_talona));
 Memo4->Lines->Add(b[i].name);
 Memo4->Lines->Add(b[i].Data);
 Memo4->Lines->Add(b[i].time);
 Memo4->Lines->Add("Kabinet No." +b[i].nomer_kabineta);
 Memo4->Lines->Add("\n");
  
 
	 
 }
}
	
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{   if (Memo1->Visible==false) {
	 Memo1->Visible=true;
	  Memo2->Visible=true;
	   Memo3->Visible=true;
		Memo4->Visible=true;

	}else{
Memo1->Visible=false;
Memo2->Visible=false;
Memo3->Visible=false;
Memo4->Visible=false;
		  }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
 if (FileOpenDialog1->Execute()) {

TFileStream * tfile = new TFileStream(FileOpenDialog1->FileName, fmOpenReadWrite);
//TFileStream * tfile = new TFileStream("D:/New_embarcadero(projects)/SEM_2/LABS/LAB_2/Doctors.txt", fmOpenReadWrite);
 TStringList * ts = new TStringList();
 TStringList * ts1 = new TStringList();
 ts->LoadFromStream(tfile);
 a->Zapis(ts,(ts->Count)/9, a);
 a->vivod(ts1,(ts->Count)/9, a);
 Memo1->Lines = ts1;
 //TDateTime dt = DateTimePicker1->DateTime.FormatString(a[0].priem_fr);
 //Memo2->Lines->Add(dt+0.25/24);
 tfile->Free();

 delete ts;
 delete ts1;
}
else{}

}
//---------------------------------------------------------------------------

