#include<iostream>
using namespace std;

int a[20][20],vis[20],n;

void dfs(int x){
    cout<<x<<" ";
    vis[x]=1;
    for(int i=0;i<n;i++){
        if(a[x][i]==1 && vis[i]==0){
            dfs(i);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
        vis[i]=0;
    }
    int start;
    cin>>start;
    dfs(start);
}
