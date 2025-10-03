#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;        // nyimpen karakter tunggal
    Node* next;       // pointer ke node berikutnya
};

void push(Node*& top, char data) {
    // bikin node baru terus ditaruh di paling atas stack
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    // ngambil data paling atas dari stack
    if (top == nullptr) return '\0'; // kalau kosong, balikin karakter kosong
    Node* temp = top;                // simpan alamat node atas
    char poppedValue = temp->data;   // ambil datanya
    top = top->next;                 // geser top ke bawah
    delete temp;                     // hapus node lama
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;  // inisialisasi stack kosong
    string reversed = "";

    // setiap huruf dimasukin ke stack
    for (int i = 0; i < s.length(); i++) {
        push(stackTop, s[i]);
    }
    
    // keluarin huruf satu per satu biar jadi terbalik
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }
    
    return reversed;
}

int main() {
    string text = "Struktur Data";   // teks awal
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl;
    return 0;
}
