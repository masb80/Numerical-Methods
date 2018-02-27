#include<iostream>

using namespace std;

//Unknown(int *p, int num);
//void HardToFollow(int *p, int q, int *num);
/*
void Unknown(int *p, int num) 
{
  int *q;	
  q = &num;
  *p = *q + 2;
   num = 7;
}

void HardToFollow(int *p, int q, int *num) 
{
  *p = q + *num;
   *num = q;
   num = p;
   p = &q;
   Unknown(num, *p);
 }

 
 main() 
 {
    int *q;
    int trouble[3];
    trouble[0] = 1;
    q = &trouble[1];
    *q = 2;
    trouble[2] = 3;
    HardToFollow(q, trouble[0], &trouble[2]);
    Unknown(&trouble[0], *q);
    cout << *q << " " << trouble[0] << " " << trouble[2] << endl;
 }
 */
/*
 void Duplicate(int &a, int &b, int &c)
 {
  a*=a;
  b*=b;
  c*=c;
 }
 int main()
 {
  int x = 1, y = 2, z = 3;
  Duplicate(x, y, z);
cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
  return 0;
 }
 */
 /*
 void Duplicate(int *a, int *b, int *c)
 {
  *a *= 2;
  *b *= 2;
  *c *= 2;
 }
 int main()
 {
  int x=3, y=6, z=9;
  Duplicate(&x, &y, &z);
  cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
  return 0;
 }
 */
 void Doit(int &foo, int goo)
 {
  cout << "foo dhuklo: " << foo << endl;
  cout << "goo dhuklo: " << goo << endl;
  foo = goo + 3;
  goo = foo + 4;
  foo = goo + 3;
  goo = foo; // er portheke foo change hole goo o change hoye jay
 }
 int main()
 {
  int *foo, *goo;
  foo = new int;
  *foo = 1;
  
  cout <<"*foo = 1:   " << (*foo) << endl;
  goo = new int;
  *goo = 3;
  cout << "*goo = 3: " << *goo << endl;
  *foo = *goo + 3;

  cout << "*foo = *goo + 3:  " <<(*foo) << endl;
  foo = goo; // er por theke goo er man change korle foo er man e change hoye jay

  cout << "foo = goo khali :  " << foo << endl; // only foo er kono value nai
  cout << " foo = goo :  "  <<(*foo) << endl;
  *goo = 5;
  cout << " foo = goo :  "  <<(*foo) << endl;
  cout << "*goo = 5: " << *goo << endl;
  *foo = *goo + *foo;
  cout << "*foo = *goo + *foo;  :  " << (*foo) << endl;
  // since foo is 10 then goo also changed to 10
  Doit(*foo, *goo);
  cout << "Function call er por *foo:  " << (*foo) << endl;
  // fooo jeheto change holo then goo o change hoye gelo
  cout <<"Function call er por *goo:  "<< (*goo) << endl;
 }
