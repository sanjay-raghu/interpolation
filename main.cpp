#include <iostream>
#include "functions.h"
using namespace std;
void grid_gen(double,double,double,double,double,double,int,int,grid_point **);
void main(void)
{
  double x1,y1,x2,y2 ;
  double nx,ny ;
  grid_point **grid ;
  cout<<"please enter the values of (x1,y1) and (x2,y2) and nx ny\n";
  cin >> x1 >> y1 >> x2 >> y2 >> nx >> ny ;



//dynamic memory alocation to grid points
  grid = new grid_point*[nx+1] ;
  for(i=0;i<nx+1;i++)
  {
    grid[i]=new grid_point[ny+1];
  }

//genrating grid

  for(int i=0;i<nx;i++)
  {
    for(int j=0;j<ny;j++)
    {
      grid_gen(x1,y1,x2,y2,nx,ny,grid);
    }
  }


}

~   


