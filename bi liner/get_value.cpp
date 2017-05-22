#include <iostream>
#include <math.h>
#include"get_value.h"
//#define PI 3.14
using namespace std;
namespace get_value {

void get_value(double *x,double *y,double **value,int nx,int ny)
{
  for(int i=0;i<nx;i++)
  {
    for(int j=0;j<ny;j++)
    {

    //  value[i][j] = sin(PI*x[i]*x[i])+cos(PI*y[j]*y[j]);
    value[i][j] = x[i]*x[i]+y[j]*y[j];
    //value[i][j]=10;

    }
  }

};

}
