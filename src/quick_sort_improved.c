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
    int i, j1, j2, pivot;
  if (n <= 1) return;
  if (n == 2){
    if (A[0] <= A[1]) return; 
  }
  pivot = A[n/2];
  A[n/2] = A[0];
  A[0] = pivot;

  for(i = j1 = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j1);
      j1++;
    }
  }

  swap(A+0,A+j1-1);


  for (i = j2 = 0; i < j1 ; i++){
    if(A[i] < pivot){
      swap(A+i, A+j2);
      j2++;
    }
  }
  quick_sort(A,j2);
  quick_sort(A+j1,n-j1);

}

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for (i = 0; i < N; i++){
    printf("%d = %d\n",i, A[i]);
  }
}
