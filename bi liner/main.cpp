#include<iostream>
#include<fstream>
#include"parent_grid.h"
#include"amrsolver.h"
#include"memory_allocation_2d.h"
#include "grid_gen.h"
using namespace std;


int main(){
  double xmin=0,xmax=10,ymin=0,ymax=10 ;
  int pnx=11,pny=11, cnx=21, cny=21 ;
  double *px,*py,**pvalue ;



  //std::cout << "please enter the values of (xmin,xmax) and (ymin,ymax) and pnx(number of nodes in x direction) pny (number of nodes in y direction) \n" << std::endl;
  //std::cin >> xmin >> xmax >> ymin >> ymax >> pnx >> pny  ;
  //dynamic memory alocation to grid points

  px = new double[pnx];
  py = new double[pny];
  pvalue = new double* [pnx];
  MA2::memory_allocation_2d(pvalue,pnx,pny);

  //........................................

  PG::parent_grid(xmin,xmax,ymin,ymax,pnx,pny,px,py,pvalue);

  double *cx,*cy,*wx,*wy;
  double **cvalue,**wvalue;
  wx = new double[4];
  wy = new double[4];
  wvalue = new double* [4];

  for(int i=0;i<4;i++)
  {
    wvalue[i]=new double[4];
  }

  fstream pgrid;
  pgrid.open("pgrid.txt");

 if(!pgrid.is_open())
 {
      cout << "error opening pgrid file" << endl;
 }

  for(int i=0;i<pnx;i++)
  {
    for(int j=0;j<pny;j++)
    {
      pgrid << pvalue[i][j] << " " ;

    }
    pgrid << endl;

  }
  pgrid.close();

  std::cout << "finished writing pgrid" << '\n';

  fstream fpx;
  fpx.open("px.txt");

 if(!fpx.is_open())
 {
      cout << "error opening fpx file" << endl;
 }

  for(int i=0;i<pnx;i++)
  {

    {
      fpx << px[i] << " " ;

    }


  }
  fpx.close();
  std::cout << "finished writing fpx" << '\n';


  //std::cout <<"enter the number of nodes need in child_grid  in x direction, and in y direction"<< std::endl;


  //std::cin >> cnx >> cny ;

  //dynamic memory alocation for child grid points
  // boundary cell is not included
  cx = new double[cnx];
  cy = new double[cny];
  cvalue = new double* [cnx];
  MA2::memory_allocation_2d(cvalue,cnx,cny);

  grid_gen::grid_gen(xmin,xmax, ymin, ymax,cnx,cny,cx,cy);



  fstream fcx;
  fcx.open("cx.txt");

 if(!fcx.is_open())
 {
      cout << "error opening fcx file" << endl;
 }

  for(int i=0;i<cnx;i++)
  {

    {
      fcx <<'('<< cx[i] <<',' << cy[i] << ')' << " " ;

    }


  }
  fcx.close();
  std::cout << "finished writing fcx" << '\n';


  std::cout << "starting calculation of cvalue" << '\n';
  for(int k=0;k<pnx-1;k++)
  {

    for(int l=0;l<pny-1;l++)
    {
      for(int i=int(cnx*k/(pnx-1));i<int(cnx*(k+1)/(pnx-1));i++)
      {
        for(int j=int(cny*l/(pny-1));j < int(cny*(l+1)/(pny-1));j++)
        {

          {
            amrsolver::bilinear_interpolate(px,py,pvalue,cx,cy,cvalue,i,j, k,l);

          }


        }




      }



    }

  }
  for (int i = 0; i < cnx; i++) {
    for (int j = 0; i < cnx; i++) {
      if(i==cnx-1||j==cny-1)
              {
              cvalue[i][j]=0;
               }
    }

  }


//cg::child_grid(pvalue ,cvalue ,cx,cy,px,py,pnx,pny,cnx,cny, 3 ,3, 1,1 );

 std::cout << "writing file" << '\n' << endl;
 //std::cout << cvalue[3][3] << '\n';

  ofstream file;
  file.open("cvalue.txt");

  if(!file.is_open()){

    std::cout <<"unable to open file "<<std::endl;

  }
  else
  {
    for(int i=0; i < cnx-1;i++)
    {
      for(int j=0 ; j< cny-1 ; j++)
      {
        file << cvalue[i][j]<<" ";
      }
      file << endl;
    }
    file.close();

  }

 return 0;
}
