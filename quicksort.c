#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int comparator(const void * p, const void * q){
  return(*(int*)p - *(int*)q);
}

int main(){
   int k;
  int size = 1000000;
  int val[size];
  clock_t starttime;//start time
  clock_t endtime;//end time
  double execution_time;
  printf("Input a k: \n");
  scanf("%d", &k);
  starttime = clock();
  FILE *input = fopen("InputMil.txt", "r");//text file 
  //int val[] = {234, 32, 543, 636, 75, 8567, 54, 33, 78, 8976, 43, 312, 13, 243};//will replace with reading from a file
  //int size = sizeof(val) / sizeof(val[0]);
  for(int i = 0; i< size; i++){
    fscanf(input, "%d", &val[i]);
  }
  /*  printf("Before sorting the array: \n");
  for(int i = 0; i < size; i++){
    printf("%d\n", val[i]);
  }
  */
  qsort(val, size, sizeof(int), comparator);//sorts the integers using quicksort                    
  /*printf("\nQuick sort array is: \n");
  for(int i = 0; i<size; i++){
    printf("%d\n", val[i]);//prints the integers in ascending order                                 
  }
   printf("\nkth smallest integer: \n");
  */
  printf("%d\n", val[k-1]);//prints the kth integer after quick sorting
  endtime = clock();
  execution_time = (double)(endtime-starttime) /CLOCKS_PER_SEC;
  printf("Quicksort execution time: %f seconds \n", execution_time);  
  fclose(input);
}