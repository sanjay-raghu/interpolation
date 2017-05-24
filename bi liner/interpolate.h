namespace interpolate {

  void bilinear_interpolate(double **x,double **y,double **value,double **xnew,double **ynew,double **res,int pnx,int pny,int cnx,int cny ,int i ,int j) ;
  void bicubic_interpolate(double** pvalue ,double** cvalue ,double** cx,double** cy,double** px,double** py,int pnx,int pny, int cnx, int cny, int i ,int j);
  void get_A_matrix(double **value, double**a ,int k,int l);
  void get_cvalue(double Tnewx,double Tnewy,double**a,double** cvalue,int index_x,int index_y);
}
