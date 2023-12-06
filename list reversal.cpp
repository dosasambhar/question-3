#include <iostream>
using namespace std;


class Node{
  public:

  int data;
  Node* next;

 
  Node(){
    this->data = 0;
    this->next = NULL;
  }

  Node(int data){
    this->data= data;
    this->next = NULL;
  };

  Node* reverse(Node* &prev, Node* &curr){
    //base case
    if(curr == NULL){
      return prev;    //reverse ho gyi h
    }

    Node*forward = curr->next;
    curr->next = prev;

    return reverse(curr, forward);
  }

  Node* reverseloop(Node* &head){
    Node*prev = NULL;
    Node*curr=head;

    while(curr!=NULL){
      Node*temp = curr->next;
      curr->next = prev;
      prev=curr;
      curr=temp;
    }

    return prev;
  }
  

 void print (Node* &head){
    Node* temp = head;
    while(temp!= NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
  }
};


int main() {
  
  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);

  first->next = second;
  second->next = third;

    Node* head = first;
    Node* tail = third;

    Node*prev = NULL;
    Node*curr = head;

   head= head->reverse(prev, curr);
  //  head = head->reverseloop(head);

  head->print(head);

  return 0;

}