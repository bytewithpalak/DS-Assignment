#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int vis[20]={0};
    int q[20];
    int f=0,r=0;
    int start;
    cin>>start;
    q[r++]=start;
    vis[start]=1;
    while(f<r){
        int u=q[f++];
        cout<<u<<" ";
        for(int v=0;v<n;v++){
            if(a[u][v]==1 && vis[v]==0){
                vis[v]=1;
                q[r++]=v;
            }
        }
    }
    return 0;
}
