
#include <stdio.h>
#include <iostream>
#include <vector>
#include "bilinear_interpolate.h"

namespace amrsolver {

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


}
