#include<iostream>
#include"memory_allocation_2d.h"
namespace MA2
{

  void memory_allocation_2d(double**p,int nx,int ny)
  {


    for(int i=0;i< nx ;i++)
    {
      p[i]=new double[ny];
    }
  }
}
