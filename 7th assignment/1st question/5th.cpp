#include <bits/stdc++.h>
using namespace std;
int partitionArr(int a[],int l,int r){
    int pivot=a[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
void quickSort(int a[],int l,int r){
    if(l<r){
        int p=partitionArr(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}
int main(){
    int a[]={10,7,8,9,1,5};
    int n=6;
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
