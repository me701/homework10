// Dot Product
//
// Compile using 
// $$ g++ -O3 -fopenmp dot.cc -o dot
#include <omp.h>
#include <cstdio>
#include <string>
#include <sstream>

double dot(double *x, double *y, const long int n)
{
  double v = 0;
  for (long int i = 0; i < n; ++i)
  {
    v += x[i]*y[i];
  }

  return v;
}

int main(int argc, char* argv[])
{

  long int n = 0;
  if (argc != 2) 
  {
    std::printf("usage: %s <n> \n where <n> is an integer.\n", argv[0]);
    return 1;
  }
  else 
  {
    std::string s = argv[1];
    if (!(std::istringstream(s) >> n)) 
    {
      std::printf("argument could not be converted to an integer...\n");
      return 2;
    }
  }
  
  double *a = new double[n];
  double *b = new double[n];
  for (long int i = 0; i < n; ++i)
  {
    a[i] = 1.0;
    b[i] = 2.0;
  }

  // initialize timer
  double et = omp_get_wtime();

  double v = dot(a, b, n);

  // finalize time
  et = omp_get_wtime() - et;

  printf("v = %.3e\n", v);
  printf("v should be %.3e\n", n*2.0);
  printf("time = %8.4f\n", et);

  delete [] a;
  delete [] b;

  return 0;
}
