#include<iostream>
using namespace std;

int parent[20];

int find(int x){
    while(parent[x]!=x)x=parent[x];
    return x;
}

int main(){
    int n,e;
    cin>>n>>e;
    int u[50],v[50],w[50];
    for(int i=0;i<n;i++) parent[i]=i;
    for(int i=0;i<e;i++) cin>>u[i]>>v[i]>>w[i];

    for(int i=0;i<e-1;i++){
        for(int j=i+1;j<e;j++){
            if(w[i]>w[j]){
                int t=w[i];w[i]=w[j];w[j]=t;
                t=u[i];u[i]=u[j];u[j]=t;
                t=v[i];v[i]=v[j];v[j]=t;
            }
        }
    }

    int cost=0;
    for(int i=0;i<e;i++){
        int a=find(u[i]);
        int b=find(v[i]);
        if(a!=b){
            parent[b]=a;
            cost+=w[i];
        }
    }
    cout<<cost;
}
