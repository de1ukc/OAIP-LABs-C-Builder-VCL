#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;





int _tmain(int argc, _TCHAR* argv[])
{   system ("chcp 1251>nul") ;

  int a[10];
  cout<<"� ������� 10 ��������� "<<endl;
  cout<<"������� �������� ������� : ";

  for(int i = 0 ; i < 10 ; i++)
   {
	 cin>>a[i];}
	 cout<<"��������������� �������� ������� : "<<endl;

  for(int i = 0 ; i < 10 ; i++)
  {
   int f=0;
	for(int j = 0 ; j < 10 ; j++)
	 if(a[i] == a[j]) f++;
	 if( f == 1) cout<<a[i]<<"\n";
  }


 getch(); return 0;
}












