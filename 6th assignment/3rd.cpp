#include <bits/stdc++.h>
using namespace std;
struct Node {int data; Node* next; Node* prev;};
int sizeDLL(Node* head){
    int c=0;
    while(head){c++; head=head->next;}
    return c;
}
int sizeCLL(Node* head){
    if(!head) return 0;
    Node* temp=head; int c=0;
    do{c++; temp=temp->next;}while(temp!=head);
    return c;
}
int main(){
    Node* a=new Node{1,NULL,NULL};
    Node* b=new Node{2,NULL,NULL};
    Node* c=new Node{3,NULL,NULL};
    a->next=b; b->prev=a; b->next=c; c->prev=b;
    cout<<"DLL size: "<<sizeDLL(a)<<"\n";
    a->next=b; b->next=c; c->next=a;
    cout<<"CLL size: "<<sizeCLL(a);
}

