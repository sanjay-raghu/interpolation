#include<iostream>
#include"get_A_matrix.h"
namespace get_A_matrix
{
void get_A_matrix(double **value, double**a ,int k,int l)
{
  int num;
  double F[4][4],temp[4][4];
  double A[4][4]={(1,0,-3,2),(0,0,3,-2),(0,1,-2,1),(0,0,-1,1)};
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

        temp[i][j]=temp[j][i]+A[m][j]*F[i][m];

      }
//     std::cout << temp[j][i] << ' ';
    }
//   std::cout << " " << '\n';
  }

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

//std::cin >> num;



}
}
