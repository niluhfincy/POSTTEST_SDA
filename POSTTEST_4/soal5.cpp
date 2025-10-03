#include <iostream>
using namespace std;

struct Node {
    int data;       // simpan angka
    Node* next;     // pointer node berikut
    Node* prev;     // pointer node sebelumnya
};

void exchangeHeadAndTail(Node *&head_ref) {
    // kalau kosong atau cuma ada 1 node, ga perlu ditukar
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }
    
    Node* head = head_ref;
    Node* tail = head_ref->prev;
    
    // kalau cuma ada 2 node, tinggal balik aja
    if (head->next == tail) {
        head_ref = tail;
        return;
    }
    
    // simpan tetangga head & tail
    Node* head_next = head->next;
    Node* tail_prev = tail->prev;
    
    // sambungin tail ke posisi head
    tail->next = head_next;
    tail->prev = head;
    head_next->prev = tail;
    
    // sambungin head ke posisi tail
    head->next = tail;
    head->prev = tail_prev;
    tail_prev->next = head;
    
    // update head jadi tail
    head_ref = tail;
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

void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};
    if (head_ref == nullptr) {
        // kalau kosong, bikin node pertama
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    // kalau udah ada isi, taruh di belakang (sebelum head)
    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node *head = nullptr;
    
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    
    cout << "List sebelum exchange: ";
    printList(head);
    
    exchangeHeadAndTail(head);
    
    cout << "List setelah exchange head dan tail: ";
    printList(head);
    
    return 0;
}