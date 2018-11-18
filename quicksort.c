#include <stdio.h>
#include <stdbool.h>
//partition function                                                                               
int partition(int arr[], int left, int right){
  int l = left;
  int r = right;
  int mid = left + (right-left)/2;
  int piv = arr[mid];//pivot position                                                              
  int temp = 0;
  bool done = false;
  while(!done){
    while(arr[l] < piv){
      l++;//left value inceases                                                                    
    }
    while(piv < arr[r]){
      r--;//right value decreases                                                                  
    }
    if(l >= r) done = true;
    else{
      temp = arr[l];
      arr[l] = arr[r];
      arr[r] = temp;
      l++;
      r--;
    }
  }//end of done while loop                                                                        
  return r;
}

//quick sort function                                                                              
void quickSort(int arr[], int left, int right){
  int mid = 0;//midpoint                                                                           
  if(left >=right) return;//if there's less than 2 elements, array is sorted                       
  mid = partition(arr, left, right);
  quickSort(arr, left, mid);//sorts low partition                                                  
  quickSort(arr, mid+1, right);//sorts high partition                                              
}

int main(){
  FILE *input;//text file                                                                          
  int num;//stores number from text file                                                           
  int vals[5000];
  int c = 0;//array counter                                                                        
  while(!feof(input)){//while the text file isn't empty                                            
    fscanf(input, "%d", &num);//scans number from text file                                        
    vals[c] = num;
    c++;
  }//end of while loop                                                                             
  for(int i = 0; i<c-1; i++){
    printf("%d\n\n", vals[i]);
  }
  printf("Quick Sort Result is: ");
  quickSort(vals, 0, c-2);
  for(int i = 0; i<c-1; i++){
    printf("%d\n\n", vals[i]);
  }//prints integers in quick sort order                                                           
}
