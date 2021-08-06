#include <iostream>
using namespace std;

int partition(vector<int> &A,int l,int r){
    swap(A[l],A[rand()%(r-l+1)+l]);

    int pivot=A[l];
    while(l<r){
        while(l<r && A[r]>=pivot) r--;
        if(l<r) A[l++]=A[r];
        while(l<r && A[l]<=pivot) l++;
        if(l<r) A[r--]=A[l];
    }
    A[l]=pivot;
    return l;
}

void quickSort(vector<int> &A,int l,int r){
    if(l>=r) return;
    
    int mid=partition(A,l,r);
    quickSort(A,l,mid-1);
    quickSort(A,mid+1,r);
}