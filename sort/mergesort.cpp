#include <iostream>
using namespace std;

void mergeSort(int A[],int l, int r){
    if(l>=r) return;

    int mid=l+(r-l)/2;
    mergeSort(A,l,mid);
    mergeSort(A,mid+1,r);

    int temp[r-l+1];
    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=r){
        if(A[i]<=A[j]){
            temp[k++]=A[i++];
        }else{
            temp[k++]=A[j++];
        }
    }
    while(i<=mid) temp[k++]=A[i++];
    while(j<=r) temp[k++]=A[j++];
    
    i=l,k=0;
    while(i<=r){
        A[i++]=temp[k++];
    }

}