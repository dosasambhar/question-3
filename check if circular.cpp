#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(){
    this->data=0;
    this->next=NULL;
  }

  Node(int data){
    this->data=data;
    this->next=NULL;
  }

    bool hasCycle(Node* head) {
        Node* fast = head;
        Node* slow = head;

        if (head == nullptr) {
            return false; // No cycle found
        }

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }

            if (slow == fast) {
                cout << "Linked list has a cycle." << endl;
            }
        }

        return false; // No cycle found
    }
};

int main() {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->next = second;
    second->next = third;
    

    Node* head = first;

    Node node;
    if (node.hasCycle(head)) {
        cout << "Linked list has a cycle." << endl;
    } else {
        cout << "Linked list does not have a cycle." << endl;
    }

    return 0;
}