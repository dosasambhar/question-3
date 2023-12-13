#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

void print(Node* head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

Node* sorting(Node* head) {
  int zero = 0;
  int one = 0;
  int two = 0;

  Node* temp = head;

  while (temp != NULL) {
    if (temp->data == 0) {
      zero++;
    } else if (temp->data == 1) {
      one++;
    } else if (temp->data == 2) {
      two++;
    }
    temp = temp->next;
  }

  temp = head;

  while (zero--) {
    temp->data = 0;
    temp = temp->next;
  }

  while (one--) {
    temp->data = 1;
    temp = temp->next;
  }

  while (two--) {
    temp->data = 2;
    temp = temp->next;
  }

  return head;
}



Node* sorting2(Node* &head) {
  //dummy
  Node* zerohead = new Node(-1);
  Node* zerotail = zerohead;

  Node* onehead = new Node(-1);
  Node* onetail = onehead;

  Node* twohead = new Node(-1);
  Node* twotail = twohead;

  //transverse the ll and add 0, 1, 2 in the dummy list;

  Node* temp = head;

  while (temp != NULL) {
    if (temp->data == 0) {
      Node* curr = temp;
      temp=temp->next;
      curr->next=NULL;
      zerotail->next = curr;
      zerotail = curr;

    }
     else if (temp->data == 1) {
      Node* curr = temp;
      temp=temp->next;
      curr->next=NULL;
      onetail->next = curr;
      onetail = curr;
    } 
    else if (temp->data == 2) {
     Node* curr = temp;
      temp=temp->next;
      curr->next=NULL;
      twotail->next = curr;
      twotail = curr;
    }
  }

  // delete and connect the dummy list

  Node* curr = onehead;
  onehead = onehead->next;
  curr->next = NULL;
  delete curr;

  curr = twohead;
  twohead = twohead->next;
  curr->next = NULL;
  delete curr;

  if (onehead != NULL) {
    zerotail->next = onehead;
    if (twohead != NULL) {
      onetail->next = twohead;
    }
  } else {
    if (twohead != NULL) {
      zerotail->next = twohead;
    }
  }

  // Save the head and delete the dummy node
  // Node* sortedHead = zerohead->next;
  // zerohead->next = NULL;
  // delete zerohead;
  
  Node* temp1 = zerohead;
  zerohead = zerohead->next;
  temp1->next = NULL;
  delete temp1;

  return zerohead;
}

int main() {
  Node* first = new Node(1);
  Node* second = new Node(0);
  Node* third = new Node(0);
  Node* fourth = new Node(2);
  Node* fifth = new Node(1);
  Node* sixth = new Node(2);
  Node* seventh = new Node(1);

  first->next= second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;
  sixth->next = seventh;

  Node* head= first;
  

  cout << "Original Linked List: ";
  print(head);

  head = sorting2(head);

  cout << "\nSorted Linked List: ";
  print(head);

  return 0;
}
