#include<iostream>
#include<cmath>

using namespace std;

double f(double x)
{
  return sin(5*x);

}
double incrementalSearch(double& fa, double x0, double deltax, double eps)
//double incrementalSearch(double (*f) double, double x0, double deltax, double eps)
{
  double x = x0, fx = f(x);
  do
    {
      double fxpdx = f(x+deltax);
      if (fx * fxpdx >= 0.0)
	{
	  x += deltax;
	  fx = fxpdx;
	}
      else
	{
	  deltax /= 10.0;
	}
    } while (fabs(deltax) >= eps);
  return x;
}
main()
{
  double x = 0.1, deltax = 0.0625, fa;
  cout << incrementalSearch(fa,x,deltax,1.0e-6) << endl;
}
