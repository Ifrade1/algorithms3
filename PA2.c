#include <stdio.h>

void floydHeapify(long floyd[], long size, long m){
  long max = m;//max element is root                                                                                                                                                                                                                                                             
  long left = 2*m +1;//left= 2m+1                                                                                                                                                                                                                                                                
  long right = 2*m +2;//right = 2m+2                                                                                                                                                                                                                                                             
  long temp;
  if((left < size) && (floyd[left] > floyd[max]))//left child > root                                                                                                                                                                                                                             
    max = left;//left element is larger than root                                                                                                                                                                                                                                                
  if((right < size) && (floyd[right] > floyd[max]))//right child > max element                                                                                                                                                                                                                   
    max = right;
  if(max != m){// max element is not the root                                                                                                                                                                                                                                                    
    temp = floyd[m];
    floyd[m] = floyd[max];
    floyd[max] = temp;
    floydHeapify(floyd, size, max);//recursion step                                                                                                                                                                                                                                              
  }
}
void heapsort(long heap[], long n){//builds the array                                                                                                                                                                                                                                            
  long temp;//temporary variable for swap                                                                                                                                                                                                                                                        
  for(long i = (n/2) - 1; i >= 0; i--){
    floydHeapify(heap, n, i);//builds the heap                                                                                                                                                                                                                                                   
  }
  for(long j = n-1; j >= 0; j--){
    temp = heap[0];//swaps variables                                                                                                                                                                                                                                                             
    heap[0] = heap[j];
    heap[j] = temp;
    // swap(heap[0], heap[j]);//extract element from heap                                                                                                                                                                                                                                        
    floydHeapify(heap, j, 0);
  }//calls floydHeapify                                                                                                                                                                                                                                                                          

}

int main(){
  long k;//reading kth smallest integer                                                                                                                                                                                                                                                          
  long num;                                                                                                                                                                                 
  long n;//size of array from input                                                                                                                                                                                                                                                              
  scanf("%ld %ld",&n,&k);//scans size of the array and k                                                                                                                                                                                                                                         
  long val[n];//array for storing integer                                                                                                                                                                                                                                                        
  for(long i = 0; i < n-1; i++){
    scanf("%ld\n", &num);//reads integers line by line;                                                                                                                                                                                                                                          
 val[i] = num;
  }
  scanf("%ld", &num);//reads last integer to store in array
  val[n-1] = num;

  heapsort(val, n);//calls to heap sort                                                                                                                                                                                                                                                          
  /* for(long i = 0; i < n; i++){                                                                                                                                                                                                                                                                
   printf("%ld\n", val[i]);//prints the integers in ascending order, use it for debugging                                                                                                                                                                                                        
   }                                                                                                                                                                                                                                                                                             
  */
  if (k != 0){
    printf("%ld\n", val[k-1]);//prints integer at the kth location                                                                                                                                                                                                                               
  }
}
