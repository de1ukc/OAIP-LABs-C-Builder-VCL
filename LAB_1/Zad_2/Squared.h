//---------------------------------------------------------------------------

#ifndef SquaredH
#define SquaredH
#include "Shape.h"
#include <vcl.h>
//---------------------------------------------------------------------------

class Squared : public shape {
public:
int x,y;
Squared(){}
Squared(int xcentr,int ycentr,int r1, int r2){
this->xcentr = xcentr;
this->ycentr = ycentr;
this->r1 = r1;
this->r2 = r2;

}
void perimetr(){
  float per = 4*r1+4*r2;
 ShowMessage("�������� �������� ����� " + FloatToStr(per));
}
void area(){
   float area = (2*r1)*(2*r2);
   ShowMessage("������� �������� ����� " + FloatToStr(area));
}
void centr () {

 ShowMessage("����� ���� ��������� � ����� (" + IntToStr(xcentr)+","+IntToStr(ycentr)+")");


}

void show(TCanvas *Canvas){
Canvas->Pen->Color=clBlack;
 Canvas->MoveTo(xcentr-r1,ycentr-r2);
 Canvas->LineTo(xcentr+r1,ycentr-r2);
 Canvas->LineTo(xcentr+r1,ycentr+r2);
 Canvas->LineTo(xcentr-r1,ycentr+r2);
 Canvas->LineTo(xcentr-r1,ycentr-r2);
}

void hide(TCanvas *Canvas){
Canvas->Pen->Color=clWhite;
 Canvas->MoveTo(xcentr-r1,ycentr-r2);
 Canvas->LineTo(xcentr+r1,ycentr-r2);
 Canvas->LineTo(xcentr+r1,ycentr+r2);
 Canvas->LineTo(xcentr-r1,ycentr+r2);
 Canvas->LineTo(xcentr-r1,ycentr-r2);

}

void show(TCanvas *Canvas, int a){
Canvas->Pen->Color=clBlack;
 Canvas->MoveTo(xcentr + (-1*r1)*cos(a*M_PI/180)-(-1*r2*sin(a*M_PI/180)),ycentr+(-1*r2)*cos(a*M_PI/180)+(-1*r1)*sin(a*M_PI/180));
Canvas->LineTo(xcentr + (1*r1)*cos(a*M_PI/180)-(-1*r2*sin(a*M_PI/180)),ycentr+(-1*r2)*cos(a*M_PI/180)+(1*r1)*sin(a*M_PI/180));
Canvas->LineTo(xcentr + (1*r1)*cos(a*M_PI/180)-(1*r2*sin(a*M_PI/180)),ycentr+(1*r2)*cos(a*M_PI/180)+(1*r1)*sin(a*M_PI/180));
Canvas->LineTo(xcentr + (-1*r1)*cos(a*M_PI/180)-(1*r2*sin(a*M_PI/180)),ycentr+(1*r2)*cos(a*M_PI/180)+(-1*r1)*sin(a*M_PI/180));
Canvas->LineTo(xcentr + (-1*r1)*cos(a*M_PI/180)-(-1*r2*sin(a*M_PI/180)),ycentr+(-1*r2)*cos(a*M_PI/180)+(-1*r1)*sin(a*M_PI/180));
}
 void hide(TCanvas *Canvas, int a){
Canvas->Pen->Color=clWhite;
Canvas->MoveTo(xcentr + (-1*r1)*cos(a*M_PI/180)-(-1*r2*sin(a*M_PI/180)),ycentr+(-1*r2)*cos(a*M_PI/180)+(-1*r1)*sin(a*M_PI/180));
Canvas->LineTo(xcentr + (1*r1)*cos(a*M_PI/180)-(-1*r2*sin(a*M_PI/180)),ycentr+(-1*r2)*cos(a*M_PI/180)+(1*r1)*sin(a*M_PI/180));
Canvas->LineTo(xcentr + (1*r1)*cos(a*M_PI/180)-(1*r2*sin(a*M_PI/180)),ycentr+(1*r2)*cos(a*M_PI/180)+(1*r1)*sin(a*M_PI/180));
Canvas->LineTo(xcentr + (-1*r1)*cos(a*M_PI/180)-(1*r2*sin(a*M_PI/180)),ycentr+(1*r2)*cos(a*M_PI/180)+(-1*r1)*sin(a*M_PI/180));
Canvas->LineTo(xcentr + (-1*r1)*cos(a*M_PI/180)-(-1*r2*sin(a*M_PI/180)),ycentr+(-1*r2)*cos(a*M_PI/180)+(-1*r1)*sin(a*M_PI/180));

}

void move(TCanvas *Canvas,int a,int xn,int yn){
hide(Canvas,a);
hide(Canvas,--a);
xcentr=xn; ycentr=yn;
show(Canvas,++a);
}
void perevorot(TCanvas *Canvas,int a){

hide(Canvas,--a);
show(Canvas,++a);

}

void uvelich(TCanvas *Canvas, int counter,int a) {

 hide(Canvas,a);
 hide(Canvas,--a);
 r1+=counter; r2+=counter;
 show(Canvas,++a);
}
};
#endif







/*
void show(TCanvas *Canvas){
Canvas->Pen->Color=clBlack;
 Canvas->MoveTo(xcentr-r1,ycentr-r2);
 Canvas->LineTo(xcentr+r1,ycentr-r2);
 Canvas->LineTo(xcentr+r1,ycentr+r2);
 Canvas->LineTo(xcentr-r1,ycentr+r2);
 Canvas->LineTo(xcentr-r1,ycentr-r2);
}*/
