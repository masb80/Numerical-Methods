#include<iostream>
#include<vector>

using namespace std;

int main(){
//  int i;
  vector<double>a;
  cout<< "First vector size is: "<< a.size()<<endl;
  for(int i=0; i < 5; i++){
    a.push_back(i);
  }
  cout<< "Seconly vector size is: "<< a.size()<<endl;
  for(int i = 0; i < 5; i++){
    cout<< "Value of the vector[ " << i <<" ] = " << a[i] <<endl;
  }
  vector<double>::iterator it = a.begin();
  while(it != a.end()) {
    cout << "Value of the vector is = " << *it << endl;
    it++;
  }
  return 0;
}
