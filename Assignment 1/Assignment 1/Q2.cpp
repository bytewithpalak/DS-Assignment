#include<iostream>
using namespace std;
int main(){
    int n;
     cout<<"enter n"<<endl;
     cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cout<<"enter array"<<endl;
        cin>>arr[i];

    }
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                for(int k=j;k<n-1;k++){
                    arr[k] = arr[k+1];
                }
                n--;
                j--;
            }
        }
    }
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }




    return 0;
}