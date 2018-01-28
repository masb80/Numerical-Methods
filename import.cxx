#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>


using namespace std;

int ReadFromFile( const string & s, vector <double> & v );
void importMatrix(const char* filename_X, vector <double>& v, int& r, int& c);

int main(){
  vector <double> v;
  int r=0;
  int c=0;
  
  importMatrix("cjh3d.dat",v,r,c);
}

int ReadFromFile( const string & s, vector <double> & v ) {
  istringstream is( s );
  double n;
  while( is >> n ) {
    v.push_back( n );
  }
  return v.size();
}



void importMatrix(const char* filename_X, vector <double>& v, int& r, int& c){
  
  ifstream file_X;
  string line;
  
  file_X.open(filename_X);
  if (file_X.is_open())
    {
      int i=0;
      getline(file_X, line);
      
      
      c =ReadFromFile( line, v );
      cout << "cols:" << c << endl;
        
      
      for ( i=1;i<32767;i++){
	if ( getline(file_X, line) == 0 ) break;
	ReadFromFile( line, v );
        
      }
      
      r=i;
      cout << "rows :" << r << endl;
      if(r >32766) cout<< "N must be smaller than maximum integer";
      
      file_X.close();
    }
  else{
    cout << "failed to open the file";
  }
  
  cout << "v:" << endl;
  ofstream outdata;
  outdata.open("cjh3dOutput.dat");
  for (int i=0;i<r;i++){
    for (int j=0;j<c;j++){
      cout << v[i*c+j] << "\t" ;
      // outdata << v[i*c+j]<<endl;
      //outdata.close();
    }
    cout << endl;
    
  }
}

