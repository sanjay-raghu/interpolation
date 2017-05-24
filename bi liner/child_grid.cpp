#include <iostream>
#include <string>
#include"child_grid.h"
#include "grid_gen.h"
#include"write_file.h"

namespace child_grid
{


  void child_grid(double xmin,double xmax,double ymin, double ymax,int cnx,int cny,double** cx,double** cy)
  {
    grid_gen::grid_gen(xmin,xmax,ymin,ymax,cnx,cny, cx,cy);
    write_file::write_file("cx.txt", cx , cnx, cny);
    write_file::write_file("cy.txt", cy , cnx, cny);
  }

}
