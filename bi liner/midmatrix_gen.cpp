#include<iostream>
#include"midmatrix_ge"
void midmatrix_gen(double**,double**);

midmatrix_get(double **value,double **mat)

{
  mat = new double *[4];
  for(int i=0;i<4;i++)
  {
    mat[i]=new double [4];

  }

  mat[0][0]=value[1][1];
  mat[0][1]=value[1][2];
  mat[1][0]=value[2][1];
  mat[1][1]=value[2][2];

  mat[0][2]= .5*(value[1][1]-value[1][0]);
  mat[0][3]= .5*(value[1][2]-value[1][1]);
  mat[1][2]= .5*(value[1][1]-value[0][1]);
  mat[1][3]= .5*(value[1][1]-value[0][1]);

  mat[0][3]= .5*(value[1][1]-value[0][1]);
  mat[0][3]= .5*(value[1][1]-value[0][1]);
  mat[0][3]= .5*(value[1][1]-value[0][1]);
  mat[0][3]= .5*(value[1][1]-value[0][1]);


}


