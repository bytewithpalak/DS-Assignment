#include <bits/stdc++.h>
using namespace std;
void selection(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]) min=j;
        }
        swap(a[i],a[min]);
    }
}
int main(){
    int a[]={5,3,8,1,2};
    int n=5;
    selection(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
