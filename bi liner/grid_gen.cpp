#include <iostream>
#include "grid_gen.h"
namespace grid_gen {
  void grid_gen(double x1,double x2,double y1,double y2,int nx,int ny,double *x_cord,double *y_cord)
  {


    double  hx,hy;
    hx=(x2-x1)/(nx-1);
    hy=(y2-y1)/(ny-1);


    for(int a=0;a<nx;a++)
    {
      x_cord[a] = x1 + a*hx ;
      //std::cout << x_cord[a] << '\n';


    }
    for(int b=0;b< ny;b++)
    {

      y_cord[b] = y1 + b*hy ;

    }
  };

}
