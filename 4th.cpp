#include <iostream>
using namespace std;

class List{
    class Node{
    public:
        int data;
        Node* next;
        Node(int x){data=x;next=NULL;}
    };
    Node* head;
public:
    List(){head=NULL;}

    void add(int x){
        Node* t=new Node(x);
        if(head==NULL) head=t;
        else{
            Node* p=head;
            while(p->next) p=p->next;
            p->next=t;
        }
    }

    void rev(){
        Node* prev=NULL;
        Node* cur=head;
        Node* nxt;
        while(cur){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        head=prev;
    }

    void show(){
        Node* p=head;
        while(p){
            cout<<p->data;
            if(p->next) cout<<"->";
            p=p->next;
        }
        cout<<"->NULL"<<endl;
    }
};

int main(){
    List l;
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.show();
    l.rev();
    l.show();
}
