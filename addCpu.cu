// Calculationg Two arrays in CPU usig CUDA compiler
#include<studio.h>
#define SIZE 1024

void vectorAdd(int *a, int *b, int *c, int n);

int i;
for(i=0; i < n; i++)
c[i] = a[i] + b[i];

int main(){
int *a, *b, *c; // Host side pointer

a = (int*)malloc(SIZE*sizeof(int));
b = (int*)malloc(SIZE*sizeof(int));
c = (int*)malloc(SIZE*sizeof(int));

for(int i = 0; i < SIZE; ++i){
a[i] = i;
b[i] = i;
c[i] = 0;
}

vectorAdd(a, b, c, SIZE);

for(int i = 0; i < 10; ++i) // printing 1st 10 elements
printf("c[%d] = %d\n", i, c[i]);

free(a);
free(b);
free(c);

return 0;

} // main
