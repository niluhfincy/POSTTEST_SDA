#include <iostream>
using namespace std;

struct Node {
    int data;       // nyimpen angka
    Node* next;     // pointer ke node setelahnya
    Node* prev;     // pointer ke node sebelumnya
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    
    if (head_ref == nullptr) {
        // kalau list kosong, node pertama menunjuk dirinya sendiri
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    
    // kalau data baru lebih kecil dari head
    if (data < head_ref->data) {
        Node* tail = head_ref->prev;
        
        newNode->next = head_ref;
        newNode->prev = tail;
        head_ref->prev = newNode;
        tail->next = newNode;
        head_ref = newNode; // update head jadi node baru
        return;
    }
    
    Node* current = head_ref;
    
    // cari posisi yang pas (data lebih kecil dari node setelahnya)
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }
    
    // sisipkan node baru di posisi yang ketemu
    Node* nextNode = current->next;
    newNode->next = nextNode;
    newNode->prev = current;
    current->next = newNode;
    nextNode->prev = newNode;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }
    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node *head = nullptr;
    
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);
    
    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);
    
    return 0;
}