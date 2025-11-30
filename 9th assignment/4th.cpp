#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[20][20],vis[20]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vis[0]=1;
    int cost=0;
    for(int k=0;k<n-1;k++){
        int mn=999,u=-1,v=-1;
        for(int i=0;i<n;i++){
            if(vis[i]){
                for(int j=0;j<n;j++){
                    if(!vis[j] && a[i][j]!=0 && a[i][j]<mn){
                        mn=a[i][j];
                        u=i;v=j;
                    }
                }
            }
        }
        vis[v]=1;
        cost+=mn;
    }
    cout<<cost;
}
