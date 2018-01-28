#include<iostream>
#include<cmath>

using namespace std;

void rtop(double x, double y, double& r, double& a)
{
  r = sqrt(x*x + y*y);
  a = atan2(y,x);

}
main(){

  double x = 3.0, y = 2.0, radius, angle;
  rtop(x, y , radius, angle);
  cout<<"radius = " << radius <<", "<< "angle = " << angle << "  radian \n";

}
