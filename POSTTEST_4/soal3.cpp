#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;  // nama file dokumen
    Node* next;       // pointer ke node berikutnya
};

void enqueue(Node*& front, Node*& rear, string document) {
    // bikin node baru untuk dokumen baru
    Node* newNode = new Node{document, nullptr};
    
    if (front == nullptr) { 
        // kalau antrian kosong, front & rear jadi node ini
        front = newNode;
        rear = newNode;
    }
    else {
        // kalau ada isinya, taruh di belakang
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    // ambil data dari depan
    if (front == nullptr) return ""; // kalau kosong, balikin string kosong
    
    Node* temp = front;
    string data = front->document;
    
    // geser front ke node berikutnya
    front = front->next;
    
    // kalau udah habis, rear juga kosong
    if (front == nullptr) {
        rear = nullptr;
    }
    
    delete temp;
    return data;
}

void processAllDocuments(Node*& front, Node*& rear) {
    // proses semua dokumen sampai habis
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;
    
    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");
    
    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);
    
    return 0;
}