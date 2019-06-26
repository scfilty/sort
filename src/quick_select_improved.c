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
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
  int i, j1, j2, pivot;
  if (n <= 1) return A[0];
  if (n == 2){
    if (A[0] <= A[1]) return A[k]; 
  }

// 真ん中の要素をピボットとする
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
  

  if(j2 < k && k < j1) return pivot;
  else if(j1 <= k) return quick_select(A+j1, n-j1, k-j1);
  else return quick_select(A, j2+1, k);
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//  printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}