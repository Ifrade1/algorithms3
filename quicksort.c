#include <stdio.h>
#include <stdlib.h>

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int comparator(const void * p, const void * q){
  return(*(int*)p - *(int*)q);
}

int main(){
  FILE *input = fopen("test14.txt", "r");//text file                                                                           
  int k;
  int size = 14;
  int val[size];
  //int val[] = {234, 32, 543, 636, 75, 8567, 54, 33, 78, 8976, 43, 312, 13, 243};//will replace with reading from a file
  //int size = sizeof(val) / sizeof(val[0]);
  for(int i = 0; i< size; i++){
    fscanf(input, "%d", &val[i]);
  }
  printf("Before sorting the array: \n");
  for(int i = 0; i < size; i++){
    printf("%d\n", val[i]);
  }
  printf("Input a k: \n");
  scanf("%d", &k);
  qsort(val, size, sizeof(int), comparator);//sorts the integers using quicksort                    
  printf("\nQuick sort array is: \n");
  for(int i = 0; i<size; i++){
    printf("%d\n", val[i]);//prints the integers in ascending order                                 
  }
  printf("\nkth smallest integer: \n");
  printf("%d\n", val[k-1]);//prints the kth integer after quick sorting
  fclose(input);
  return(0);

}
