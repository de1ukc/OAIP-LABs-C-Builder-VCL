//---------------------------------------------------------------------------

#ifndef CalcH
#define CalcH
#include <vcl.h>
#include "Form.h"
//---------------------------------------------------------------------------
class Calc
{
public:
	int rows;
	float **arr;
	Calc(){}
	Calc( int rows, TStringGrid *Grid )
	{
		this->rows = rows;
		arr = new float*[rows];
		   for (int i = 0; i < rows; i++)
		   {
			 arr[i] = new float[rows];
		   }

		   for (int i = 0; i < rows; i++)
		   {
				for (int j = 0; j < rows; j++)
				{
				  //arr[i][j] = StrToFloat(Grid->Cells[i+1][j+1]);
				  arr[i][j] = StrToFloat(Grid->Cells[i][j]);
				}
		   }
	}

	void deleting (float** arr, const int k)
	{
			for (int i = 0; i < k; i++)
			   {
				  delete[] arr[i];
			   }
				delete [] arr;
	}

	int determinant(float** arr, const int n)
	{
			if (n == 1)
				return arr[0][0];
			else if (n == 2)
				return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
			else {
				int determ = 0;
				for (int k = 0; k < n; k++)
				   {
					float** m = new float*[n-1];
						for (int i = 0; i < n - 1; i++)
						   {
								m[i] = new float[n - 1];
						   }

					for (int i = 1; i < n; i++)
					   {
							int t = 0;
							for (int j = 0; j < n; j++)
							   {
									if (j == k)
									continue;
									m[i-1][t] = arr[i][j];
									t++;
							   }
					   }
					determ += pow(-1, k + 2) * arr[0][k] * determinant(m, n - 1);
					deleting(m, n - 1);
				   }
				return determ;
			}
	}

	void transp(float** arr, int n, TStringGrid *Grid)
	{
		 for (int i = 0; i < n; i++)
			{ for (int j = 0; j < n; j++)
				 {
					//Grid->Cells[i+1][j+1]= arr[j][i];
					Grid->Cells[i][j]= arr[j][i];
				 }
			}
	}

	void obrmatrix(TStringGrid *Grid)
	{
		int determ = this->determinant(this->arr,this->rows);
		if (determ == 0)
		  {
			ShowMessage("�������� ������� �� ����������.");
		  }
		  else
		  {
			for (int i = 0; i < rows; i++)
			   {
					for (int j = 0; j < rows; j++)
					{
						//Grid->Cells[i+1][j+1] = ((arr[(j+1)%rows][(i+1)%rows] * arr[(j+2)%rows][(i+2)%rows]) - (arr[(j+1)%rows][(i+2)%rows] * arr[(j+2)%rows][(i+1)%rows]))/ determ;
						Grid->Cells[i][j] = ((arr[(j+1)%rows][(i+1)%rows] * arr[(j+2)%rows][(i+2)%rows]) - (arr[(j+1)%rows][(i+2)%rows] * arr[(j+2)%rows][(i+1)%rows]))/ determ;
					}
			   }
		  }
	}

	void plus (float** arr,float** arr2 , int rows,TStringGrid *Grid)
	{

		for (int i = 0; i < rows; i++)
		   {
				for (int j = 0; j < rows; j++)
				   {
					  arr[i][j] += arr2[i][j];
				   }

		   }
		for (int i = 0; i < rows; i++)
		  {
			  for (int j = 0; j < rows; j++)
				 {
					//Grid->Cells[i+1][j+1]= arr[i][j];
					  Grid->Cells[i][j]= arr[i][j];
				 }
		  }
	}

	void minus (float** arr, float** arr2 , int rows,TStringGrid *Grid)
	{
		for (int i = 0; i < rows; i++)
		   { for (int j = 0; j < rows; j++)
				{
					arr[i][j] -= arr2[i][j];
				}

		   }
	   for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < rows; j++)
				   {
					   //Grid->Cells[i+1][j+1]= arr[i][j];
					   Grid->Cells[i][j]= arr[i][j];
				   }
			}
	}

	void myltyply(float** arr, float** arr2 , int rows,TStringGrid *Grid)
	{
		float **arr3 = new float*[rows];
		for (int i = 0; i < rows; i++)
		   {
			 arr3[i] = new float[rows];
		   }

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < rows; j++)
			   {
				  arr3[i][j] = 0;
				  for (int z = 0; z < rows; z++)
					 {
						arr3[i][j] = arr3[i][j] + arr[i][z] * arr2[z][j];
					 }
			   }

			for (int i = 0; i < rows; i++)
			   {
				  for (int j = 0; j < rows; j++)
					 {
						//Grid->Cells[i+1][j+1]= arr3[i][j];
                        Grid->Cells[i][j]= arr3[i][j];
					 }

			   }
			for (int i = 0; i < rows; i++)
			   {
				delete[] arr3[i];
			   }
			delete[] arr3;
		}

	~Calc(){
		for (int i = 0; i < rows; i++)
			{
				delete[] arr[i];
			}
			delete[] arr;
		}

	};

#endif