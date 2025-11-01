#include <bits/stdc++.h>
using namespace std;
void bubble(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}
int main(){
    int a[]={6,2,8,5,1};
    int n=5;
    bubble(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
