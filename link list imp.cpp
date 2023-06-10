#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};     //making of Node

void insertAtHead(node* &head, int val){

    node* n = new node(val);
    n->next=head;
    head=n;
}     //end of inserthead

void insertAtTail(node* &head, int val){

node* n = new node(val);

if(head==NULL){
    head=n;
    return;
}

node* temp = head;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=n;

 }     // end of inserttail

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}           // end of display function

bool search(node* head, int key){

    node* temp=head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;

        }
        temp=temp->next;
    }
    return false;

}           // search any node

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;

    delete todelete;
}           //deletion of head of the linklist

void deletion(node* &head, int val){

    if(head == NULL){
        return;
    }         //If our linklist is completely NULL
    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }        //if our linklist have only one node

    node* temp = head;

    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
}            //delete any node 



int main(){

    node* head = NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,4);
    display(head);
    cout<<search(head,5)<<endl;
    deletion(head,2);
    display(head);
    deleteAtHead(head);
    display(head);


    return 0;
}