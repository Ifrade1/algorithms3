#include <stdio.h>

void floydHeapify(int floyd[], int size, int m){
  int max = m;//max element is root                                                                                                                     
  int left = 2*m +1;//left= 2m+1                                                                                                                        
  int right = 2*m +2;//right = 2m+2                                                                                                                     
  int temp;
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
void heapsort(int heap[], int n){//builds the array                                                                                                     
  int temp;//temporary variable for swap                                                                                                                
  for(int i = (n/2) - 1; i >= 0; i--){
    floydHeapify(heap, n, i);//builds the heap                                                                                                          
  }
  for(int j = n-1; j >= 0; j--){
    temp = heap[0];//swaps variables                                                                                                                    
    heap[0] = heap[j];
    heap[j] = temp;
    // swap(heap[0], heap[j]);//extract element from heap                                                                                               
    floydHeapify(heap, j, 0);
  }//calls floydHeapify                                                                                                                                 

}

int main(){
  int k;//reading kth smallest integer                                                                                                                  
  int num;
  //int val[] = {25, 12,16,23, 13, 10};//sample array for testing, will replace with reading integers from input                                        
  int n;//size of array from input                                                                                                                      
  scanf("%d %d",&n,&k);//scans size of array and k
  int val[n];//array for storing integers
  for(int i = 0; i < n-1; i++){
    scanf("%d\n", &num);//reads integers line by line                                                                                                
    val[i] = num;
  }
  scanf("%d", &num);
  val[n-1] = num;
  
                                                                            
  heapsort(val, n);//calls to heap sort                                                                                                                 
  //for(int i = 0; i < n; i++){
   //printf("%d\n", val[i]);//prints the integers in ascending order, use it for debugging                                                               
  //}                                                                                                   
 if (k != 0){
  printf("%d\n", val[k-1]);//prints integer at the kth location
 }
}
