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
};

Node* remove(Node* head) {
        Node* fast = head;
        Node* slow = head;

        if (head == nullptr) {
            return nullptr; // No cycle found
        }

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }

            if (slow == fast) {
                slow=head;
                break;
            }
    }
    Node* temp = fast;
     while(slow!=fast){
      temp = fast;
              slow=slow->next;
              fast=fast->next;
            }
            temp->next =  NULL;
            return slow;
}

int main() {
    
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);

    Node* tenth = new Node(30); // Creating a new node with the same value as the third node

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;

    ninth->next = sixth; // Creating a cycle by connecting the last node to the sixth node

    Node* head = first;
     Node* cycleStart = remove(head);

    

    // Correcting the way to print the result of hasCycle function
     Node* cycleStart = remove(head);

    if (cycleStart != nullptr) {
        cout << "Cycle starts at node with data: " << cycleStart->data << endl;
    } else {
        cout << "No cycle found" << endl;
    }
    return 0 ;
}
