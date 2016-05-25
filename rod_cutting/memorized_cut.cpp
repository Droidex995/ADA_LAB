#include <iostream>
#include <fstream>
#include <time.h> 
#include <stdio.h>  
#include <limits.h>
using namespace std;

int max(int a, int b) { return (a > b)? a : b;}

int memorized_cut_rod_aux(int price[],int n,int r[]){
  int q;
  if( r[n]>=0 )
      return r[n];
  if (n==0)
    q=0;
  else q=INT_MIN;
    for(int i=1;i<=n;i++)
      q=max(q,price[i]+memorized_cut_rod_aux(price,n-i,r));
  r[n]=q;
  return q;
}

int memorized_cut_rod(int price[],int n){
  int r[n+1];
  for(int i=0;i<=n;i++)
    r[i]=INT_MIN;
  return memorized_cut_rod_aux(price,n,r);
}

int main()
{
    clock_t start, end; 
    double secs;
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<< size<<endl;
    start = clock(); 
    printf("Maximum Obtainable Value is %d\n", memorized_cut_rod(arr, size));
    getchar();
    end = clock(); 
    secs = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.16g milisegundos\n", secs * 1000.0);

    return 0;
}