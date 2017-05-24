#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include "interpolate.h"
#include "memory_allocation.h"
#include "write_file.h"
using namespace std;

namespace interpolate {

//...........................bilinear_interpolate........................................
void bilinear_interpolate(double **x,double **y,double **value,double **xnew,double **ynew,double **res,int pnx,int pny,int cnx,int cny ,int i ,int j)  {

	double a0,a1,b0,b1;
	double res1,res2;
	int k,l;
	k=int(i*(pnx-1)/(cnx-1));
	l=int(j*(pny-1)/(cny-1));



	a0 =  (x[k+1][l]-xnew[i][j])/(x[k+1][l]-x[k][l]);
	a1 =  (xnew[i][j]-x[k+0][l])/(x[k+1][l]-x[k+0][l]);
	b0 =  (y[k][l+1]-ynew[i][j])/(y[k][l+1]-y[k][l+0]);
	b1 =  (ynew[i][j]-y[k][l+0])/(y[k][l+1]-y[k][l+0]);

	res1 = a0*value[k+0][l+0]+a1*value[k+1][l];
	res2 = a0*value[k][l+1]+a1*value[k+1][l+1];

	res[i][j] = b0*res1+b1*res2;

};

//..............................bicubic_interpolate.............................

void bicubic_interpolate(double** px ,double** py ,double** pvalue,double** cx,double** cy,double** cvalue,int pnx,int pny, int cnx, int cny, int i ,int j)  {
	double **A ;
	double newx,newy;
	int k,l;

	k=int(i*(pnx-1)/(cnx-1));
	l=int(j*(pny-1)/(cny-1));

	A=new double*[4];
	memory_allocation::memory_allocation_2d(A,4,4);

	std::cout << "starting calculation for A" << '\n';
	get_A_matrix(pvalue,A,k,l);
	std::cout << "A done" << '\n';
	//write_file("a.txt")



	newx = (cx[i][j]-px[k][l])/(px[k+1][l]-px[k][l]);
	newy = (cy[i][j]-py[k][l])/(py[k][l+1]-py[k][l]);

	std::cout << "interpolating" << '\n';
	get_cvalue(newx,newy,A,cvalue,i,j);
	std::cout << "interpolation done" << '\n';




};

//.........................get_A_matrix.........................................


void get_A_matrix(double **value, double**a ,int k,int l)
{
  double **F,**temp;
  double A[4][4]={{1,0,-3,2},{0,0,3,-2},{0,1,-2,1},{0,0,-1,1}};

	std::fstream file;
	file.open("A_matrix.txt",ios::out);

	if(!file.is_open())
	{
		std::cout << "error opening" << "A_matrix.txt" << "file" << std::endl;
	}

	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		{
			file << A[i][j] << " " ;

		}
		file << endl;

	}
	file.close();

	F=new double*[4];
	memory_allocation::memory_allocation_2d(F,4,4);
	temp=new double*[4];
	memory_allocation::memory_allocation_2d(temp,4,4);
 // double **a;


  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      a[i][j]=0;
      temp[i][j]=0;
    }
  }



std::cout << "line 1" << '\n';

  F[0][0]=value[k][l];
  F[1][0]=value[k][l+1];
  F[0][1]=value[k+1][l];
  F[1][1]=value[k+1][l+1];

  std::cout << "line 2" << '\n';

  F[2][0]= .5 * (value[k][l+1]-value[k][l-1]);
  F[3][0]= .5 * (value[k][l+2]-value[k][l]);
  F[2][1]= .5 * (value[k+1][l+1]-value[k+1][l-1]);
  F[3][1]= .5 * (value[k+1][l+2]-value[k+1][l]);

  std::cout << "line 3" << '\n';

  F[0][2]= .5 * (value[k+1][l]-value[k-1][l]);
  F[1][2]= .5 * (value[k+1][l+1]-value[k-1][l+1]);
  F[0][3]= .5 * (value[k+2][l]-value[k][l]);
  F[1][3]= .5 * (value[k+2][l+1]-value[k][l+1]);

std::cout << "line 4" << '\n';
  F[2][2]= .25 * (value[k+1][l+1]-value[k+1][l-1]-value[k-1][l+1]+value[k-1][l-1]);
  F[3][2]= .25 * (value[k+1][l+2]-value[k+1][l]-value[k-1][l+2]+value[k-1][l]);
  F[2][3]= .25 * (value[k+2][l+1]-value[k+2][l-1]-value[k][l+1]+value[k][l-1]);
  F[3][3]= .25 * (value[k+2][l+2]-value[k+2][l]-value[k][l+2]+value[k][l]);

	write_file::write_file("f_matrix.txt",F,4,4);

/*for(int i=0;i<4;i++)
{
  for(int j=0;j<4;j++)
  {
    std::cout << F[j][i] << ' ';
  }
    std::cout << " " << '\n';
}

std::cin >> num;
*/
  for(int j=0;j<4;j++)
  {
    for(int i=0;i<4;i++)
    {
      for(int m=0;m<4;m++)
      {

        temp[i][j]=temp[i][j]+A[m][j]*F[i][m];

      }
//     std::cout << temp[j][i] << ' ';
    }
//   std::cout << " " << '\n';
  }
	write_file::write_file("temp_matrix.txt",temp,4,4);


//  std::cin >> num;

  for(int j=0;j<4;j++)
  {
    for(int i=0;i<4;i++)
    {
      for(int m=0;m<4;m++)
      {

        a[i][j]=a[i][j]+temp[m][j]*A[m][i];


      }
//    std::cout << a[j][i] << ' ';
    }
//std::cout << " " << '\n';
  }
	write_file::write_file("a_matrix.txt",a,4,4);

//std::cin >> num;



};
//............................get_cvalue..........................................

void get_cvalue(double Tnewx,double Tnewy,double**a,double** cvalue,int index_x,int index_y)
{

// void bicubic_interpolate(double *x,double *y,double **value,double xnew,double ynew,double *res)

//   double a0,a1,b0,b1;
//   double res1,res2;

double temp[4],sum ;
double X[4] ,Y[4] ;
//temp=new double[4];
// double Tnewx,Tnewy;

//    Tnewx = (xnew-x[0])/(x[3]-x[0]);
//    Tnewy = (ynew-y[0])/(y[3]-y[0]);

for(int i=0;i<4;i++)
{
	X[i]=pow(Tnewx,i);
	Y[i]=pow(Tnewy,i);
}



for(int i=0; i < 4; i++)
{
	double sum=0;
	for(int j = 0;j < 4;j++)
	{
		sum=sum+X[j]*a[i][j];
	}
	temp[i]=sum;
}
std::cout << "intializng cvalue to 0" << '\n';
cvalue[index_x][index_y]=0;

for(int i=0;i<4;i++)
{
	cvalue[index_x][index_y]=cvalue[index_x][index_y]+temp[i]*Y[i];

}

// a0 =  (x[1]-xnew)/(x[1]-x[0]);
// a1 =  (xnew-x[0])/(x[1]-x[0]);
// b0 =  (y[1]-ynew)/(y[1]-y[0]);
// b1 =  (ynew-y[0])/(y[1]-y[0]);

// res1 = a0*value[0]+a1*value[2];
// res2 = a0*value[1]+a1*value[3];

// res[0] = b0*res1+b1*res2;

}



}
