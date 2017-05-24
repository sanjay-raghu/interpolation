#include <iostream>
#include <math.h>
#include "get_value.h"
#define PI 3.14
using namespace std;
namespace get_value {

void get_value(double **x,double **y,double **value,int nx,int ny)
{
  for(int i=0;i<nx;i++)
  {
    for(int j=0;j<ny;j++)
    {

    value[i][j] = 20*sin(.001*x[i][j]*x[i][j])+10*cos(.001*y[j][i]*y[j][j]);
    //value[i][j] = x[i][j]*x[i][j]+y[i][j]*y[i][j];
    //value[i][j]=10;
    ;

    }
  }


};

}
