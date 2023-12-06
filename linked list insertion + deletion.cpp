#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;

  Node() {
    this->data = 0;
    this->next = NULL;
  }

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }

  void insertStart(Node* &head, Node* &tail, int data) {
    Node* newnode = new Node(data);
    if (head == NULL) {
      head = tail = newnode;
    } else {
      newnode->next = head;
      head = newnode;
    }
  }

    void insertTail(Node* &head, Node* &tail, int data) {
    Node* newnode = new Node(data);
    if (head == NULL) {
      head = tail = newnode;
    } else {
      tail->next = newnode;
      tail=newnode;
    }
  }

  int find(Node* head){
    int count =0; 
    Node*temp = head;
    while(temp!=NULL){
      temp=temp->next;
      count++;
    }
    return count;
  }


  void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
  }

    void insertPosition(Node* &head, Node* &tail, int position, int data) {
    Node* newnode = new Node(data);

    if(position==0){
      insertStart(head, tail, data);
      return;
    }

   int len = find(head);
    if(position>=len){
      insertTail(head, tail, data);
      return;
    }


    if (head == NULL) {
      head = tail = newnode;
    } else {
    //position 
    int i =1;
    Node*prev = head;
    while(i<position){
      prev= prev-> next;
      i++;
    }
    Node* current = prev->next;

    Node* newnode = new Node(data);

    newnode->next=current;

    prev->next = newnode;
    }
  }

  //deletion 

  void deletion(int position, Node* &head, Node* &tail) {
    if (head == NULL) {
      tail==NULL;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    } 
    
    else {
        int len = find(head);

        if (position == len) {
            int i = 1;
            Node* prev = head;
            while (i < position - 1) {
                prev = prev->next;
                i++;
            }
            Node* temp = tail;
            prev->next= NULL;
            tail = prev;
            delete temp;
        }
    }
}
};

int main() {
  Node* head = new Node(2);
  Node* tail = new Node(8);

  head->next = tail;

  head->insertStart(head, tail, 5);
  head->insertTail(head, tail, 9);
  head->insertPosition(head, tail, 2,11);
  head->deletion(2,head, tail);
  head->print(head);

  return 0;
}

