#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int d) {
        data = d;
        next = NULL;
    }
};

//  ------- Function to display the linked List
void displayList(Node* head) {
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// -------- Function to get size of the linked list 
int getSize(Node* head) {
    int ans=0;
    Node* temp = head;
    while(temp!=NULL) {
        ans++;
        temp = temp->next;
    }
    return ans;
}

// ------- Function to reverse the linked list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* after = NULL;
    
    while(curr!=NULL) {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    return prev;
}

// Function to reverse the linked list in the range between m and n
Node* reverseInRange(Node* head, int m, int n, int l) {
    if(n>l) return head;
    
    Node* curr = head;
    Node* nodeBeforeM = NULL;
    
    // pointing curr to m-th node
    for(int i=0; i<m-1; i++) {
        nodeBeforeM = curr;
        curr = curr->next;
    }
    
    // traversing and reversing from m-th node
    Node* start = curr;
    Node* prev = NULL;
    Node* after = NULL;
    
    for(int i=0; i<n-m+1; i++) {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    Node* nodeAfterN = curr;
    start->next = nodeAfterN;       // previous m-th node will now point to (n+1)-th node
    if(nodeBeforeM) {
        nodeBeforeM->next = prev;
        return head;
    }
    return prev;
}

// ------ Function to reverse the linked list in the group of size k
Node* reverseK(Node* head, int k, int l) {
    for(int i=1; i<=l; i+=k) {
        head = reverseInRange(head, i, i+k-1, l);
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    
    displayList(head);
    
    // function to reverse in a range(m, n)
    // head = reverseInRange(head, 6, 7);
    // displayList(head);

    
    // function to reverse the linked list
    // head = reverse(head);
    // displayList(head);
    
    // function to reverse the linked list in the groups of k
    int k = 2;
    int l = getSize(head);
    head = reverseK(head, k, l);
    displayList(head);

    return 0;
}