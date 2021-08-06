#include <iostream>
using namespace std;


void down(vector<int> &A,int parent,int n){
    int child=parent*2+1;
    while(child<n){
        if(child+1<n && A[child]<A[child+1]){
            child=child+1;
        }
        if(A[parent]>=A[child])
            break;
        swap(A[parent],A[child]);
        parent=child;
        child=child*2+1;
    }
}

void heapSort(vector<int> &A){
    if(A.size()<=1) return;
    int n=A.size();

    for(int i=n/2-1;i>=0;--i){
        donw(A,i,n);
    }

    for(int i=n-1;i>0;--i){
        swap(A[0],A[i]);
        down(A,0,i);
    }
}

int main(){
    vector<int> A{2,5,7,3,1,9,8};

    heapSort(A);

    for(auto num:A){
        cout<< num<<" ";
    }
    cout<<endl;

    return 0;
}