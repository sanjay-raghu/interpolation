#include <iostream>
#include <string>
#include "grid_gen.h"
#include"parent_grid.h"
#include"write_file.h"

//#define parent_grid main
namespace parent_grid
{



  void parent_grid(double xmin,double xmax,double ymin, double ymax,int pnx,int pny,double** px,double** py)
  {
    grid_gen::grid_gen(xmin,xmax,ymin,ymax,pnx,pny, px,py);
    write_file::write_file("px.txt", px , pnx, pny);
    write_file::write_file("py.txt", py , pnx, pny);
  }
}
