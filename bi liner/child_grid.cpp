#include <iostream>
#include"child_grid.h"
#include "grid_gen.h"
#include "get_A_matrix.h"
#include "interpolation.h"
#include "memory_allocation_2d.h"

namespace cg
{


  void child_grid(double** pvalue ,double** cvalue ,double *cx,double* cy,double*px,double* py,int pnx,int pny, int cnx, int cny, int i ,int j, int k, int l)
  {

    //  grid .................................................................................

    //grid_gen::grid_gen(wx[1],wx[2],wy[1],wy[2],cnx,cny,cx,cy,i,j);

    // pvalue by interpolation

    double **A ;
    double newx,newy;
    A=new double*[4];
    std::cout << "starting calculation for A" << '\n';
    MA2::memory_allocation_2d(A,4,4);


    get_A_matrix::get_A_matrix(pvalue,A,k,l);
      std::cout << "A done" << '\n';



        newx = (cx[i]-px[l])/(px[l+1]-px[l]);
        newy = (cy[j]-py[k])/(py[k+1]-py[k]);

        std::cout << "interpolating" << '\n';
        BCI::bicubic_interpolate(newx,newy,A,cvalue,i,j);
        std::cout << "interpolation done" << '\n';











  }

}
