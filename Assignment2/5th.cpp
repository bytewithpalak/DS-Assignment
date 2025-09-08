#include <iostream>
using namespace std;

int main() {
    int n;

    // (a) Diagonal Matrix
    n = 3;
    int diag[3] = {5,8,9};
    cout << "Diagonal Matrix:" << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) cout << diag[i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;

    // (b) Tri-diagonal Matrix
    n = 4;
    int tri[3*4-2] = {0};
    tri[0] = 1; tri[3] = 4; tri[6] = 7;
    cout << "Tri-diagonal Matrix:" << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i-j==1) cout << tri[i-1] << " ";
            else if(i==j) cout << tri[n-1+i] << " ";
            else if(j-i==1) cout << tri[2*n-1+i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;

    // (c) Lower Triangular Matrix
    n = 3;
    int lower[6] = {1,2,3,4,5,6};
    cout << "Lower Triangular Matrix:" << endl;
    int k=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i>=j) cout << lower[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;

    // (d) Upper Triangular Matrix
    n = 3;
    int upper[6] = {1,2,3,4,5,6};
    cout << "Upper Triangular Matrix:" << endl;
    k=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i<=j) cout << upper[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;

    // (e) Symmetric Matrix
    n = 3;
    int sym[6] = {1,2,3,4,5,6};
    cout << "Symmetric Matrix:" << endl;
    k=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i>=j) cout << sym[i*(i+1)/2+j] << " ";
            else cout << sym[j*(j+1)/2+i] << " ";
        }
        cout << endl;
    }

    return 0;
}
