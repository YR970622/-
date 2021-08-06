#include <iostream>
using namespace std;

void insertSort(int A[],int n){
    if(A==nullptr || n<2) return;

    for(int i=1;i<n;++i){
        if(A[i]<A[i-1]){
            int num=A[i];
            int j=i-1;
            while(j>=0 && A[j]>num){
                A[j+1]=A[j];
                j--;
            }
            A[j+1]=num;
        }
    }
}