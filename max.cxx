#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> f1 = {1, 2, 3, 4};
  vector<int> f2 = {5, 6, 7, 8};
  vector<int> p;
  cout<< "size of f1: " << f1.size() << endl;
  cout<< "size of f2: " << f2.size() << endl;
for(int i=1; i < f1.size(); i++)
  {
    if(f1.at(0) < f1.at(i))
      {
	f1.at(0) = f1.at(i);
      }
  }
 cout<< " f1 max value is:  " << f1.at(0) << endl;
  double maxf1 = *max_element(f1.begin(), f1.end());
  cout<<"Max value of f1: "<<maxf1<<endl;
  for(int i = 0; i < f2.size(); i++)
    {
      if(f2.at(0) < f2.at(i))
	{
	  f2.at(0) = f2.at(i);
    }
    }
  cout << "f2 max value is:  " << f2.at(0) << endl;
  double maxf2 = *max_element(f2.begin(), f2.end());
  cout<< "Max value of f2: " << maxf2 << endl;
cout<<"largest element of first three elements:  "<<*max_element(f1.begin(), f1.begin()+3) << endl;

/*
int maxf11(vector<int>& f1) {
    int max = min;
        for (auto val : f1) {
	         if (max < val) max = val;
		     }
		         return max;
			 }
  */
}	
