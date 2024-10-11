#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head=NULL;

void insert_node(int value);
void display_node();

int main(){
    insert_node(5);
    insert_node(5);
    insert_node(5);
    insert_node(5);
    display_node();
}

void insert_node(int value){
    node* new_node, *last;
    new_node=new node;
    new_node->data=value;

    if(head==NULL){
        head=new_node;
        new_node->next=NULL;
    }else{
        last=head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=new_node;
        new_node->next=NULL;
    }
}

void display_node(){
    node* current_node;
    if(head->next==NULL){
        cout<<"no elements";
    }else{
        current_node=head;
        while(current_node->next!=NULL){
            cout<<current_node->data<<" ";
            current_node=current_node->next;
        }
    }

}
