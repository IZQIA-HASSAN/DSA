#include<iostream>
using namespace std;

struct Node{
    int data ;
    Node*next ;
    Node*pre ;

    Node(int val){
        data = val ;
        next = nullptr;
        pre = nullptr;
    }
};

Node*head = nullptr;

//now insertion at the begining ;

void insert_at_begining(Node*&head , int val){
    Node* newnode = new Node(val);
    if(head == nullptr){
        head = newnode ;
        head->next = head ;
        head->pre = head ;
    }
    else{
       //create a last node pointer for adding a second node 
       Node*last = head->pre;
       newnode->next = head;
       newnode->pre = last ;

       last->next = newnode;
       head->pre = newnode;

       head = newnode;

    }
}

void inserting_at_end(Node*& head , int val){
    Node * newnode = new Node(val);
    if(head == nullptr){
head = newnode ;
   newnode->next = newnode;
   newnode->pre =  newnode ;
    }
    

else{
   Node*last = head->pre;

   last->next = newnode;
   newnode->pre = last;
   newnode->next = head ;

   head->pre = newnode;
}
}

// delete a node by value 

void delete(Node*& head , int key){//a mistake first check the availability of key and other things 

    if(head == nullptr){
        cout<<"list is empty there is nothing to delete"<<endl;
        return ;
    }
    Node*curr = head;
    
    else{
        //when there is only and only one node ;
        if(curr == head){
            delete curr;
            head = nullptr;
        }

        while(curr->data != key){
            curr = curr->next;
        }
       curr->pre->next = curr->next;
       curr->next->pre = curr->pre ;
       delete curr ;
      
    }
    
    curr  = curr->next ; 
    if(curr-> data != key){
        cout<<"key not found "<<endl;
    }
    break;


}

// displaying forward;

void display(Node*& head){// well made
    if (head == nullptr){
        cout<<"list is empty can not be displayed"<<endl;
        return ;

    }
    
    Node* temp = head ;
    if(temp->next == head && temp->pre == head){
        cout<<"there is only one node"<<endl;
        cout<<temp->data<<" "<<endl;
       
 }else{
    do{
        
        cout<<temp->data<<endl;
        temp = temp->next;
    }while(temp != head)
 }


}

//displaying backward .....
void display_backward(Node* &head ){
    if(head == nullptr){
        cout<<"list is empty"<<endl;
        return ;
    }
    Node*temp = head->pre;
    while(true){
        cout<<temp->data<<endl;
        temp = temp->pre;
        if(curr->next == head)
        break;
    }
    cout<<endl;
}

int main(){
    // //call all the functions like 
    // inserting at the end 
    // inserting at the begining
    // deleting a node
    // etc etc
}