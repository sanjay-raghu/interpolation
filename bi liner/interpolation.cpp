#include <stdio.h>
#include <iostream>
#include <math.h>
#include "get_A_matrix.h"
//#include <amrsolver.h>
#include "interpolation.h"

namespace BCI {
    void bicubic_interpolate(double Tnewx,double Tnewy,double**a,double** cvalue,int index_x,int index_y)
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
