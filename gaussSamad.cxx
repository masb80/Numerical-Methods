#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void print( vector < vector < double > > A){
  int n = A.size();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n+1; j++){
      cout<< A[i][j]<< "\t";
      if(j == n-1){
	cout << "|";
      } //if
    } // for
    cout << "\n";
  } // for
  cout << endl;
} // print


vector<double> gauss(vector < vector < double > > A){
  int n = A.size();
  for (int i = 0; i < n; i++ ){
    double maxEl = abs(A[i][i]);
    int maxRow = i;
    for(int k = i+1; k < n; k++){
      if( abs(A[k][i]) > maxEl){
	maxEl = abs(A[k][i]);
	maxRow = k; // selecting the max row
      }// if
    }// for
    
    // swap max row with current row (column by column)
    
    for(int k = i; k < n+1; k++){
      double tmp = A[maxRow][k];
      A[maxRow][k] = A[i][k];
      A[i][k] = tmp; // making the first row 
    }// for
    
    // make all rows 0 below this row
    
    for(int k= i+1; k <n; k++){
      double c =  - A[k][i] / A[i][i];
      for(int j = i; j < n+1; j++){
	if( i == j){
	  A[k][j] = 0;
	} else {
	  A[k][j] = c * A[i][j]; // making other element in that column 0
	} // else
      } // for
    } //for 
    
  } // for
  
  // solve for Ax=b, upper triangular
  
  vector<double> x(n);
  for(int i = n-1; i >= 0; i--){
    x[i] = A[i][n] / A[i][i];
    for(int k = i-1; k >= 0; k--){
      A[k][n] -= A[k][i] * x[i];
    } // for
  } // for
  return x;
  
} // gauss



int main(){
  int n;
  cout << "Please input dimension :"<< endl;
  cin >> n;
  cout << "Please input matrix A in a row wise: "<< endl;
  vector < double > line(n+1,0);
  vector < vector <double> > A(n,line);
  // read input data
  for(int i = 0; i < n; i++){
    for(int j=0; j < n; j++){
      cin >> A[i][j];
    } //for 
  }// for
  cout << "Please input b"<< endl;
  for(int i = 0; i <n; i++){
    cin >> A[i][n];
  } //for
  
  //print
  
  print(A); // calling print function
  
  // Calculate Solution
  vector<double> x(n);
  x = gauss(A);

  for( int i = 0; i < n; i++){
    cout<< x[i]<< "\t";
  }
  cout<< endl;
} // main

