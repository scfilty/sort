#include <stdio.h>

// 素数
#define N 19

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}


/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
  int i, j, pivot;
  pivot = A[n/2];
  A[n/2] = A[0];
  A[0] = pivot;
  printf()
  printf("pivot=%d\n",pivot);
  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }
  if (n == 1) return;

  quick_sort(A,n/2);

}

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  for (i = 0;i < N;i++){
    printf("%d\n",A[i]);
  }
  quick_sort(A, N);
  for(i=0;i<N;i++){
    printf("%dth element is %d\n", i, A[i]);
  }
}
