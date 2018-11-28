#include <cstdio>

void matvec(double *a, double *x, double *y, int n);
void zero_array(double *v, int n);

int main(int argc, char* argv[])
{
  // size of arrays
  int n = 100; 

  // allocate memory
  double *a = new double[n*n];
  double *x = new double[n];
  double *y = new double[n];

  // initialize input arrays
  for (int i = 0; i < n*n; ++i)
    a[i] = 0.0;
  for (int i = 0; i < n; ++i)
  {
    a[i*n+i] = 4.0;
    if (i > 0) a[i*n+i-1] = -1.0;
    if (i < n-1) a[i*n+i+1] = -1.0;
    x[i] = 1.0;
    y[i] = 0.0;
  }

  // zero out output array
  zero_array(y, n);

  // compute the matrix vector product
  matvec(a, x, y, n);

  // print out the first two elements of y
  printf("y[0]=%8.4e and y[1]=%8.4e\n", y[0], y[1]);
  double b = y[1];
  // free memory
  delete [] a;
  delete [] x;
  delete [] y;

  return 0;
}

void zero_array(double *v, int n)
{
  for (int i = 0; i < n; ++i)
    v[i] = 0.0;
}

void matvec(double *a, double *x, double *y, int n)
{
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      y[i] += a[i*n+j]*x[j];
    }
  }
}

