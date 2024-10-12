#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head=NULL;

void insert_node(int value);
void display_node();
void delete_node(int value);
void isert_begin(int value);
void delete_begin();
void delete_end();

int main(){
    insert_node(5);
    insert_node(5);
    insert_node(5);
    insert_node(4);
    display_node();
    delete_node(4);
    display_node();
    insert_begin(10);
    display_node();
    delete_begin();
    display_node();
    delete_begin();
    display_node();
    delete_end();
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
void delete_node(int value){
    node* current,*prev_node;
    current=head; prev_node=head;
    if(current->data==value){
        head=head->next;
        free(current);
        return;
    }
    while(current->data!=value){
        prev_node=current;
        current=current->next;
    }
    prev_node->next=current->next;
    free(current);
}

void insert_begin(int value){
    node *new_node;
    new_node=new node;
    new_node->data=value;
    new_node->next=head;
    head=new_node;
}

void delete_begin(){
    if(head==NULL){cout<<"empty";}
    node* first_node=head;
    head=first_node->next;
    free(first_node);
}

void delete_end(){
    if(head==NULL){cout<<"empty";}
    else if(head->next==NULL){
        head=NULL;
        free(head);
    }else{
        node* ptr=head;
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }free(ptr->next);
        ptr->next=NULL;
    }
}
