#include <stdio.h>

// 素数
#define N 2999

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
  pivot = A[0];
  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }
  if (n <= 1) return;

  quick_sort(A,j-1);
  quick_sort(A+j,n-j);

}

int main(){
  int i;
  A[0] = 1;
  A[1] = 1;
  A[2] = 1;

  quick_sort(A,3);
  for (i = 0; i < 3; i++){
    printf("%d ",A[i]);
  }
}