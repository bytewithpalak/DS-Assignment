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

    void delkey(int k){
        int cnt=0;
        while(head && head->data==k){
            Node* t=head;
            head=head->next;
            delete t;
            cnt++;
        }
        Node* p=head;
        while(p && p->next){
            if(p->next->data==k){
                Node* t=p->next;
                p->next=t->next;
                delete t;
                cnt++;
            }else p=p->next;
        }
        cout<<"Count: "<<cnt<<endl;
        cout<<"Updated Linked List: ";
        Node* q=head;
        while(q){
            cout<<q->data;
            if(q->next) cout<<"->";
            q=q->next;
        }
        cout<<endl;
    }
};

int main(){
    List l;
    l.add(1);
    l.add(2);
    l.add(1);
    l.add(2);
    l.add(1);
    l.add(3);
    l.add(1);
    l.delkey(1);
}
