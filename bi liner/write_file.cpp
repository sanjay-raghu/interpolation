#include<iostream>
#include<fstream>
#include <string>
#include"write_file.h"
using namespace std ;

namespace write_file {
  void write_file(char const file_name[] ,double **variable ,int nx, int ny) {
  fstream file;
  file.open(file_name,ios::out);

  if(!file.is_open())
  {
    cout << "error opening" << file_name << "file" << endl;
  }

  for(int j=0;j<nx;j++)
  {
    for(int i=0;i<nx;i++)
    {
      file << variable[i][j] << " " ;

    }
    file << endl;

  }
  file.close();
};
}
