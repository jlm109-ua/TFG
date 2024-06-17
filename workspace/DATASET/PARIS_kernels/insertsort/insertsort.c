#include <stdio.h>

#define SCALE_FACTOR    (REPEAT_FACTOR >> 0)
#define N 11
int total_errors;
int a[N];   
const int expected[N]= {0,2,3,4,5,6,7,8,9,10,11};
const int initVals[N]= {0,11,10,9,8,7,6,5,4,3,2};  

void init() 
{
    total_errors=0;
    for (int Index = 0; Index < N; Index ++)
        a[Index] = initVals[Index];
}

void test ()
{
  int i,j, temp;
  i = 2;
  while(i <= 10){
      j = i;
      while (a[j] < a[j-1])
      {
	temp = a[j];
	a[j] = a[j-1];
	a[j-1] = temp;
	j--;
      }
      i++;
    }
}

void check() {
   for (int i=0; i<N; i++) {
    //printf("%i",a[i]);
  }
 // printf("total_errors: %d \n", total_errors);
}

void runMain(){
  init();
  test();
  check();
}

int main()
{
  runMain();
  return 0;
}