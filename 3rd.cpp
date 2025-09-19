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

    void mid(){
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow) cout<<"Middle: "<<slow->data<<endl;
    }
};

int main(){
    List l;
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);
    l.mid();
}
