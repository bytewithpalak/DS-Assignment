#include <bits/stdc++.h>
using namespace std;
struct Node{int data;Node* next;};
bool isCircular(Node* head){
    if(!head) return false;
    Node* temp=head->next;
    while(temp && temp!=head) temp=temp->next;
    return temp==head;
}
int main(){
    Node* a=new Node{2,NULL};
    Node* b=new Node{4,NULL};
    Node* c=new Node{6,NULL};
    Node* d=new Node{7,NULL};
    Node* e=new Node{5,NULL};
    a->next=b;b->next=c;c->next=d;d->next=e;e->next=a;
    cout<<(isCircular(a)?"True":"False");
}
