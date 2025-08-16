#include<iostream>
using namespace std;


int main(){
    int arr[5] = {1,2,3,4,5};
    int brr[5] = {6,7,8,9,10};
    int crr[5];
    for(int i=0;i<5;i++){
        crr[i] = arr[i]+ brr[i];
    }
    for(int i=0;i<5;i++){
        cout<<crr[i]<<" ";
    }
    return 0;

}
