#include <bits/stdc++.h>
using namespace std;
void improvedSelection(int a[],int n){
    int start=0,end=n-1;
    while(start<end){
        int minIdx=start,maxIdx=start;
        for(int i=start;i<=end;i++){
            if(a[i]<a[minIdx]) minIdx=i;
            if(a[i]>a[maxIdx]) maxIdx=i;
        }
        swap(a[start],a[minIdx]);
        if(maxIdx==start) maxIdx=minIdx;
        swap(a[end],a[maxIdx]);
        start++;
        end--;
    }
}
int main(){
    int a[]={5,2,9,1,7,6,3};
    int n=7;
    improvedSelection(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
