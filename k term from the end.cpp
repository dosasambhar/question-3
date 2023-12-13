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

Node* reverse(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

void print (Node*&head){
  Node*temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" "<<endl;
    temp=temp->next;
  }
}

int main() {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    Node* head = first;

    Node* reversehead = reverse(head);
    int k = 4;

    int i = 0;
    Node* temp = reversehead;
    while (i < k) {
        temp = temp->next;
        i++;
    }
    cout << temp->data << endl;


    return 0;
}
