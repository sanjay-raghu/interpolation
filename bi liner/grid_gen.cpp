#include <iostream>
#include "grid_gen.h"
namespace grid_gen {
  void grid_gen(double x1,double x2,double y1,double y2,int nx,int ny,double **x_cord,double **y_cord)
  {


    double  hx,hy;
    hx=(x2-x1)/(nx-1);
    hy=(y2-y1)/(ny-1);

    for (int i = 0; i < nx ; i++) {
      for(int j=0;j < ny; j++) {

        x_cord[i][j] = x1 + i*hx ;
        //std::cout << x_cord[a] << '\n';

      }
    }
    for (int i = 0; i < nx ; i++) {
      for(int j=0;j < ny; j++) {

        y_cord[i][j] = y1 + j*hy ;
        //std::cout << x_cord[a] << '\n';

      }
    }



  };

}
