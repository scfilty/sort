#include <stdio.h>

// 素数
#define N 2999

int A[N];
int Ar[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

int quick_select0(int A[], int n, int k){
  int i, j, pivot;

// 真ん中の要素をピボットとする
  pivot = A[n/2];
  A[n/2] = A[0];
  A[0] = pivot;
  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }

  if(j == k+1) return pivot;
  else if(j < k+1) return quick_select0(A+j, n-j, k-j);
  else return quick_select0(A+1, j-1, k);
}


int select_pivot(int A[],int n){
  int B[n],i;

  if (n <= 5) return quick_select0(A,n,n/2);
  else
  {
    for (i = 0; i < n/5; i++){
      B[i] = quick_select0(A+(5*i),5,2);
    }
    return select_pivot(B,n/5);
  }
}



int quick_select(int A[],int n, int k){
  int pivot,i,r1,r2;
  if (n <= 5) return quick_select0(A,n,k);
  
  for (i = 0; i < n; i++){
      Ar[i] = A[i];
  }
  pivot = select_pivot(Ar,n);
  

  for(i = r1 = 0; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+r1);
      r1++;
    }
  }

  for(i = r2 = 0; i < n; i++){
    if(A[i] < pivot){
      swap(A+i, A+r2);
      r2++;
    }
  }

  if (r2 < k && k <= r1) return A[k];
  else if (r1 < k) return quick_select(A+r1,n-r1,k-r1);
  else return quick_select(A,r2,k);  
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}