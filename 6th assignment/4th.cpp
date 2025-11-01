#include <bits/stdc++.h>
using namespace std;
struct Node{char data;Node* next;Node* prev;};
bool check(Node* head){
    if(!head) return true;
    Node* tail=head;
    while(tail->next) tail=tail->next;
    while(head!=tail && tail->next!=head){
        if(head->data!=tail->data) return false;
        head=head->next;
        tail=tail->prev;
    }
    return true;
}
int main(){
    Node* a=new Node{'r',NULL,NULL};
    Node* b=new Node{'a',NULL,NULL};
    Node* c=new Node{'d',NULL,NULL};
    Node* d=new Node{'a',NULL,NULL};
    Node* e=new Node{'r',NULL,NULL};
    a->next=b;b->prev=a;b->next=c;c->prev=b;c->next=d;d->prev=c;d->next=e;e->prev=d;
    cout<<(check(a)?"True":"False");
}
