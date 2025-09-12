#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int N = 4;
    Mahasiswa mhs[N];

    cout << "Input data mahasiswa:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama : "; cin >> mhs[i].nama;
        cout << "NIM  : "; cin >> mhs[i].nim;
        cout << "IPK  : "; cin >> mhs[i].ipk;
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-1-i; j++) {
            if (mhs[j].ipk > mhs[j+1].ipk) {
                // Tukar posisi struct
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }

    cout << "\nData mahasiswa setelah diurutkan berdasarkan IPK ascending:" << endl;
    for (int i = 0; i < N; i++) {
        cout << mhs[i].nama << " | " << mhs[i].nim << " | " << mhs[i].ipk << endl;
    }

    return 0;
}