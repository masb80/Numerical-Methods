#include<iostream>
#include<cmath>
#include <stdlib.h> 

using namespace std;

double f(double x)
{
  return 1.0/x + log(1+x) - 5.0;
  
}
//double incrementalSearch(double& fa, double xl, double xr, double eps)
double incrementalSearch(double (*f) (double), double xl, double xr, double eps)
//double incrementalSearch(double (*f) double, double x0, double deltax, double eps)
{
  double fl = f(xl), fr = f(xr);
  if(fl*fr > 0.0)
    {
      cerr<<"fl * fr > 0.0 in bisection \n";
      exit (-1);
    }
  while(fabs(xl - xr)/2.0 > eps)
    {
      double xc = (xl + xr)/2.0, fc = f(xc);
      if(fl * fc <= 0.0)
	{
	  xr = xc;
	  fr = fc;
	}
      else
	{
	  xl=xc;
	  fl = fc;
	}
      return (xl + xr)/2.0;
    }
}

main()
{
  double xl = 0.1, xr = 1.0, eps = 1.0e-6;
  double in = incrementalSearch(f, xl,xr,eps);
  cout << in << endl;
}
