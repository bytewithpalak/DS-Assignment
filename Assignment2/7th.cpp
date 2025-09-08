#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int A[100];
    cout<<"Enter "<<n<<" elements:"<<endl;
    for(int i=0;i<n;i++) cin>>A[i];

    int inv=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(A[i]>A[j]) inv++;
        }
    }

    cout<<"Number of inversions: "<<inv<<endl;

    return 0;
}
