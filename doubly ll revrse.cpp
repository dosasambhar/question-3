#include <iostream>
using namespace std;


class Node{
  public:

  int data;
  Node* next;
  Node* prev;

 
  Node(){
    this->data = 0;
    this->next = NULL;
    this->prev = NULL;
  }

  Node(int data){
    this->data= data;
    this->next = NULL;
    this->prev = NULL;
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
  //reverse using loops

  Node* reverseloop(Node* &head){
    Node*prev = NULL;
    Node*curr=head;

    while(curr!=NULL){
      Node*temp = curr->next;
      curr->next = prev;
      curr->prev = temp;
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
  Node* fourth = new Node(40);

  first->next = second;
  second->prev=first;
  second->next = third;
  third->prev=second;
  third->next = fourth;
  fourth->prev =third;

    Node* head = first;
    Node* tail = fourth;

    Node*prev = NULL;
    Node*curr = head;

  //  head= head->reverse(prev, curr);
   head = head->reverseloop(head);

  head->print(head);

  return 0;

}