/*
  We need 3 steps to make CPU to GPU:
  1) Parallelized the vector function
  2) All CPU move to GPU and execute and move back to CPU
  3) Finally modify the vectorAdd to modify the function in GPU
*/
#include<studio.h>
#define SIZE 1024
/*
  parallelized the vector
  it tells the compiler that it will execute in GPU
*/
_global_void vectorAdd(int *a, int *b, int *c, int n){
  int i = threadId.x; // needed for thread
  if(i < n)
    c[i] = a[i] + b[i];
} // _global_void vector
int main(){
  int *a, *b, *c;
  int *d_a, *d_b, *d_c; // variables for GPU
  // for CPU Memory Allocation
  a = (int*)malloc(SIZE*sizeof(int));
  b = (int*)malloc(SIZE*sizeof(int));
  c = (int*)malloc(SIZE*sizeof(int));
  // for GPU Memory Allocation, not a back up pointer, use address &
  cudaMalloc( &d_a, SIZE*sizeof(int));
  cudaMalloc( &d_b, SIZE*sizeof(int));
  cudaMalloc( &d_c, SIZE*sizeof(int));
  // Copy the data CPU to the GPU
  //  cudaMemCpy( destination, source, SIZE, direction of the data);
  cudaMemCpy( d_a, a, SIZE*sizeof(int), cudaMemCpyHostToDevice);
  cudaMemCpy( d_b, b, SIZE*sizeof(int), cudaMemCpyHostToDevice);
  cudaMemCpy( d_c, c, SIZE*sizeof(int), cudaMemCpyHostToDevice);
  for(int i = 0; i < SIZE; ++i){
    a[i] = i;
    b[i] = i;
    c[i] = 0;
  }
  // Syntax change for CUDA
  // vectorAdd <<< (no of block, Size of block) >>> (d_a, d_b, d_c, SIZE);
  vectorAdd <<< (1, SIZE) >>> (d_a, d_b, d_c, SIZE);
  // Copy the data GPU to the CPU
  cudaMemCpy( destination, source, SIZE, direction of the data);
  cudaMemCpy( c, d_c, SIZE*sizeof(int), cudaMemCpyDeviceToHost);
  for(int i = 0; i < 10; ++i)
    printf("c[%d] = %d\n", i, c[i]);
  // making free the CPU
  free(a);
  free(b);
  free(c);
  // making free the GPU
  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);
  return 0;
}
