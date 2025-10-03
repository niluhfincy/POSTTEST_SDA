#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;        // nyimpen karakter (bracket buka)
    Node* next;       // pointer ke node bawah
};

void push(Node*& top, char data) {
    // masukin data baru ke stack (push)
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    // keluarin data paling atas stack (pop)
    if (top == nullptr) return '\0';  // kalau kosong, return char kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr; // inisialisasi stack kosong
    
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        
        // kalau bracket buka, taruh ke stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(stackTop, ch);
        }
        // kalau bracket tutup, cek pasangannya
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stackTop == nullptr) { // kalau kosong, pasti salah
                return false;
            }
            
            char topChar = pop(stackTop); // ambil yang paling atas
            // cek pasangan bracketnya bener apa nggak
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    
    // kalau stack kosong, berarti semua bracket berpasangan
    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    
    return 0;
}