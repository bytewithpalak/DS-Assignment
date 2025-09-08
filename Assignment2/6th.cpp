#include <iostream>
using namespace std;

struct Term {
    int r,c,v;
};

int main() {
    int n1,n2;
    cout<<"Enter non-zero terms in A: ";
    cin>>n1;
    Term A[20];
    cout<<"Enter rows cols vals for A:"<<endl;
    for(int i=0;i<n1;i++) cin>>A[i].r>>A[i].c>>A[i].v;

    cout<<"Enter non-zero terms in B: ";
    cin>>n2;
    Term B[20];
    cout<<"Enter rows cols vals for B:"<<endl;
    for(int i=0;i<n2;i++) cin>>B[i].r>>B[i].c>>B[i].v;

    cout<<"A:"<<endl;
    for(int i=0;i<n1;i++) cout<<A[i].r<<" "<<A[i].c<<" "<<A[i].v<<endl;
    cout<<"B:"<<endl;
    for(int i=0;i<n2;i++) cout<<B[i].r<<" "<<B[i].c<<" "<<B[i].v<<endl;

    // transpose of A
    cout<<"Transpose of A:"<<endl;
    for(int c=0;c<3;c++) {
        for(int i=0;i<n1;i++) {
            if(A[i].c==c) cout<<A[i].c<<" "<<A[i].r<<" "<<A[i].v<<endl;
        }
    }

    // addition
    cout<<"A+B:"<<endl;
    int i=0,j=0;
    while(i<n1 && j<n2) {
        if(A[i].r==B[j].r && A[i].c==B[j].c) {
            cout<<A[i].r<<" "<<A[i].c<<" "<<A[i].v+B[j].v<<endl;
            i++; j++;
        } else if(A[i].r<B[j].r || (A[i].r==B[j].r && A[i].c<B[j].c)) {
            cout<<A[i].r<<" "<<A[i].c<<" "<<A[i].v<<endl;
            i++;
        } else {
            cout<<B[j].r<<" "<<B[j].c<<" "<<B[j].v<<endl;
            j++;
        }
    }
    while(i<n1) { cout<<A[i].r<<" "<<A[i].c<<" "<<A[i].v<<endl; i++; }
    while(j<n2) { cout<<B[j].r<<" "<<B[j].c<<" "<<B[j].v<<endl; j++; }

    // multiplication
    cout<<"A*B:"<<endl;
    for(int x=0;x<n1;x++) {
        for(int y=0;y<n2;y++) {
            if(A[x].c==B[y].r) {
                cout<<A[x].r<<" "<<B[y].c<<" "<<A[x].v*B[y].v<<endl;
            }
        }
    }

    return 0;
}
