#include <iostream>

using namespace std;

// output contents of array to screen
void printArray(int arr[], int size) {
  for ( int i = 0; i < size; i++ ) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}


int main()
{
  int L1[4] = {0,1,2,3};
  int L2[4] = {4,5,6,7};
  int maxval[4] ;
  int maxval1[4];
  int temp = 0;
 
  for(int i=0;i<4;i++)
    {
      maxval[i] = L1[i];
      if(maxval[i]<L2[i])
	{
	  maxval[i] = L2[i];
	 //int  indexdval[i] = temp;
	}
     }
//cout<< "temp" << temp << endl;
 // cout << "The first max array is: ";
//   printArray(maxval, 4);

/*
 cout << "L2 array is: ";
  printArray(L2, 4);
 
    for(int i=0;i<4;i++)
      {
	maxval1[i] = L2[i];
	if(maxval1[i]<L1[i])
	  {
	    maxval1[i] = L1[i];
	    //	indexdval[i] = L
	  }
      }
    
    cout << "The second max array is: ";
    printArray(maxval1, 4);
  
  */
	int L[2][4] = {{1,6,10,4}, {5,2,7,8}};
	int maxindex[2] = {0,0};
	int maxvalue[4] = {-1, -1, -1, -1};
   for ( int i = 0; i < 2 ; i ++) // Camera
   {
	for (int j = 0; j < 4; j ++) // faces
	{
		if ( maxvalue[j]+3  < L[i][j])
		{
			maxvalue[j] = L[i][j];
			maxindex[j] = i;

		}	

	}

   } 
   cout<< "max values are: ";
   printArray(maxvalue,4);
cout<< "max index are: ";
   printArray(maxindex, 4);
    return 0;
}
