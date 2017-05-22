#include <iostream>
#include <string>
#include "grid_gen.h"
#include"parent_grid.h"
#include"get_value.h"
//#define parent_grid main
namespace PG
{



  void parent_grid(double xmin,double xmax,double ymin, double ymax,int pnx,int pny,double* px,double* py,double** pvalue)
  {

    grid_gen::grid_gen(xmin,xmax,ymin,ymax,pnx,pny,px,py);
    get_value::get_value(px,py,pvalue,pnx,pny);


  }
}
