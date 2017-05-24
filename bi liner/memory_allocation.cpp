#include<iostream>
#include"memory_allocation.h"
namespace memory_allocation
{

  void memory_allocation_2d(double**p,int nx,int ny)
  {


    for(int i=0;i< nx ;i++)
    {
      p[i]=new double[ny];
    }
  }
}
