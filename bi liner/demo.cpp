#include<iostream>
#include<cmath>
#include "engine.h"

void plotcvalue(double**,double ,double );

using namespace std

void plotcvalue(double **z,double a, double b){
  Engine *ep = engOpen(NULL);
  //double x[1000];
  //double y[1000];
 // double z[1000];

  //double t = 0;
 // const double dt = 0.001;
  int i,j;
 // double a,b;

  mxArray **z_array = mxCreateDoubleMatrix(a,b,mxREAL);
 // mxArray *a_array = mxCreateDoubleMatrix(   1,1,mxREAL);
 // mxArray *b_array = mxCreateDoubleMatrix(   1,1,mxREAL);

  double **pz = mxGetPr(z_array);
  //double *pa = mxGetPr(a_array);
  //double *pb = mxGetPr(b_array);

/*  for (i=0;i<1000;i++){
    x[i] = cos(2*M_PI*t);
    y[i] = sin(2*M_PI*t);
    t+=dt;
  }

  a = 1; 
  b = 0;
  for (j=0;j<100;j++){
    for(i=0;i<1000;i++){
      z[i] = a*x[i] + b*y[i];
      pz[i] = z[i];
    }
    pa[0] = a;
    pb[0] = b;
*/
    engPutVariable(ep,"z",z_array);
   // engPutVariable(ep,"a",a_array);
  //  engPutVariable(ep,"b",b_array);
    engEvalString(ep,"testPlot");
    
  //  a = a - 0.01;
  //  b = b + 0.01;
 // }
 
  engClose(ep);

  return 0;
}
