#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
  
  Node(int n) {
      data = n, next = NULL;
  }
  Node() {
      data = NULL;
      next = NULL;
  }
};

Node* reverse(Node* node) {
    Node* prev=NULL;
    Node* curr; Node* after=NULL;
    curr = node;

    while(curr!=NULL) {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    node = prev;
    return node;
}

int main() {
    // Write C++ code here
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);

    head = reverse(head);
    
    Node* temp = head;
    
    while(temp!=NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    return 0;
}