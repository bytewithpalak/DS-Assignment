#include <bits/stdc++.h>
using namespace std;
void insertion(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main(){
    int a[]={7,4,1,9,3};
    int n=5;
    insertion(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
