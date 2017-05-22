
#include <stdio.h>
#include <iostream>
#include <vector>
//#include <amrsolver.h>

void bilinear_interpolate(double *x,double *y,double **value,double *xnew,double *ynew,double **res,int i,int j ,int k ,int l) ;

namespace amrsolver {

void bilinear_interpolate(double *x,double *y,double **value,double *xnew,double *ynew,double **res,int i,int j , int k , int l) {

	double a0,a1,b0,b1;
	double res1,res2;


	a0 =  (x[k+1]-xnew[i])/(x[k+1]-x[k]);
	a1 =  (xnew[i]-x[k+0])/(x[k+1]-x[k+0]);
	b0 =  (y[l+1]-ynew[j])/(y[l+1]-y[l+0]);
	b1 =  (ynew[j]-y[l+0])/(y[l+1]-y[l+0]);

	res1 = a0*value[k+0][l+0]+a1*value[k+1][l];
	res2 = a0*value[k][l+1]+a1*value[k+1][l+1];

	res[i][j] = b0*res1+b1*res2;

}


}
