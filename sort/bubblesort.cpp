#include <iostream>
using namespace std;


bool isChange=true;
void bubbleSort(int A[],int l,int r){
    if(l>=r) return;

    int n =r-l+1;
    for(int i=0;i<n-1 && isChange;++i){
        isChange=false;
        for(int j=0;j<n-1-i;++j){
            if(A[j]>A[j+1]){
                isChange=true;
                swap(A[j],A[j+1]);
            }
        }
    }
}