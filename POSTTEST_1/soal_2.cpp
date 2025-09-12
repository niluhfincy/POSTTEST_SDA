#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matriks[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    int jumlah = 0;
    for (int j = 0; j < N; j++) {
        jumlah += matriks[1][j]; // baris ke-2 (indeks 1)
    }

    cout << "Jumlah elemen baris genap (baris ke-2): " << jumlah << endl;

    return 0;
}