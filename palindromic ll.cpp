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

bool isPalindrome(Node* &head) {
  if(head==NULL){
    return true;
  }

  if(head->next==NULL){
    return true;
  }
  // Find the middle of the linked list
  Node* fast = head;
  Node* slow = head;

  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }

  // Reverse the second half of the linked list
  Node* prev = NULL;
  Node* curr = slow;

  while (curr != NULL) {
    Node* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  // Compare the first half and the reversed second half
  Node* temp1 = head;
  Node* temp2 = prev;

  while (temp2 != NULL) {
    if (temp1->data != temp2->data) {
      return false;
    } else {
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
  }

  return true;
}

int main() {
  // Example usage
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(2);
  head->next->next->next->next = new Node(1);

  if (isPalindrome(head)) {
    cout << "The linked list is a palindrome." << endl;
  } else {
    cout << "The linked list is not a palindrome." << endl;
  }

  // Clean up: delete the nodes
  while (head != NULL) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}
