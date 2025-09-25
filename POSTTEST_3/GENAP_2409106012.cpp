#include <iostream>
#include <string>
using namespace std;

// Struct untuk data jadwal penerbangan
struct JadwalPenerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
};

// Struct untuk Node Double Linked List
struct Node {
    JadwalPenerbangan data;
    Node *next;
    Node *prev;
};

// Variabel global
Node *head = NULL;
Node *tail = NULL;
int panjangList = 0;
string nimTerakhir;
int posisiSisip;

// Fungsi untuk generate kode penerbangan
string generateKodePenerbangan() {
    if (panjangList == 0) {
        return "JT-" + nimTerakhir;
    } else {
        return "JT-" + nimTerakhir + "-" + to_string(panjangList);
    }
}

// Insert First
void insertFirst(Node *&head, Node *&tail) {
    cout << "\n[ Tambah jadwal di awal ]" << endl;
    Node *newNode = new Node();
    
    newNode->data.kodePenerbangan = generateKodePenerbangan();
    cout << "Kode Penerbangan: " << newNode->data.kodePenerbangan << " (Auto)" << endl;
    cout << "Tujuan: "; cin.ignore(); getline(cin, newNode->data.tujuan);
    cout << "Status: "; getline(cin, newNode->data.status);
    
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }
    
    panjangList++;
    cout << "Data telah tersimpan." << endl;
    system("pause");
}

// Insert Last
void insertLast(Node *&head, Node *&tail) {
    cout << "\n[ Tambah jadwal di akhir ]" << endl;
    Node *newNode = new Node();
    
    newNode->data.kodePenerbangan = generateKodePenerbangan();
    cout << "Kode Penerbangan: " << newNode->data.kodePenerbangan << " (Auto)" << endl;
    cout << "Tujuan: "; cin.ignore(); getline(cin, newNode->data.tujuan);
    cout << "Status: "; getline(cin, newNode->data.status);
    
    newNode->prev = tail;
    newNode->next = NULL;
    
    if (head == NULL && tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    
    panjangList++;
    cout << "Data telah tersimpan." << endl;
    system("pause");
}

// Insert Specific (dengan personalisasi NIM)
void insertAt(Node *&head, Node *&tail) {
    int posisi = posisiSisip; // Gunakan posisi dari NIM
    
    if (posisi < 1 || posisi > panjangList + 1) {
        cout << "Posisi tidak valid! Menambah di akhir." << endl;
        insertLast(head, tail);
        return;
    }
    
    if (posisi == 1) {
        insertFirst(head, tail);
    } else if (posisi == panjangList + 1) {
        insertLast(head, tail);
    } else {
        cout << "\n[ Tambah jadwal di posisi " << posisi << " (berdasarkan NIM) ]" << endl;
        Node *newNode = new Node();
        
        newNode->data.kodePenerbangan = generateKodePenerbangan();
        cout << "Kode Penerbangan: " << newNode->data.kodePenerbangan << " (Auto)" << endl;
        cout << "Tujuan: "; cin.ignore(); getline(cin, newNode->data.tujuan);
        cout << "Status: "; getline(cin, newNode->data.status);
        
        Node *temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        
        panjangList++;
        cout << "Data telah tersimpan." << endl;
        system("pause");
    }
}

// Delete First
void deleteFirst(Node *&head, Node *&tail) {
    if (head == NULL && tail == NULL) {
        cout << "LinkedList Kosong" << endl;
        system("pause");
    } else if (head->next == NULL) {
        cout << "Jadwal yang dihapus: " << head->data.kodePenerbangan << " - " << head->data.tujuan << endl;
        delete head;
        head = NULL;
        tail = NULL;
        panjangList--;
        cout << "Data telah terhapus." << endl;
        system("pause");
    } else {
        cout << "Jadwal yang dihapus: " << head->data.kodePenerbangan << " - " << head->data.tujuan << endl;
        Node *del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
        panjangList--;
        cout << "Data telah terhapus." << endl;
        system("pause");
    }
}

// Delete Last
void deleteLast(Node *&head, Node *&tail) {
    if (head == NULL && tail == NULL) {
        cout << "LinkedList Kosong" << endl;
        system("pause");
    } else if (head->next == NULL) {
        cout << "Jadwal yang dihapus: " << head->data.kodePenerbangan << " - " << head->data.tujuan << endl;
        delete head;
        head = NULL;
        tail = NULL;
        panjangList--;
        cout << "Data telah terhapus." << endl;
        system("pause");
    } else {
        cout << "Jadwal yang dihapus: " << tail->data.kodePenerbangan << " - " << tail->data.tujuan << endl;
        Node *del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
        panjangList--;
        cout << "Data telah terhapus." << endl;
        system("pause");
    }
}

// Print List dari depan
void printList(Node *head) {
    if (head == nullptr) {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    
    cout << "\nIsi LinkedList (Maju - dari Head ke Tail):" << endl;
    int i = 1;
    while (head != nullptr) {
        cout << i++ << ". Kode: " << head->data.kodePenerbangan
             << ", Tujuan: " << head->data.tujuan
             << ", Status: " << head->data.status << endl;
        head = head->next;
    }
    cout << endl;
}

// Fitur baru: Print List dari belakang (Traversal mundur)
void printListReverse(Node *tail) {
    if (tail == nullptr) {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    
    cout << "\nIsi LinkedList (Mundur - dari Tail ke Head):" << endl;
    int i = panjangList;
    while (tail != nullptr) {
        cout << i-- << ". Kode: " << tail->data.kodePenerbangan
             << ", Tujuan: " << tail->data.tujuan
             << ", Status: " << tail->data.status << endl;
        tail = tail->prev;
    }
    cout << endl;
}

// Update status penerbangan (fungsi paling kompleks)
void updateStatus() {
    if (head == nullptr) {
        cout << "LinkedList Kosong" << endl;
        system("pause");
        return;
    }
    
    string kodeInput;
    cout << "Masukkan Kode Penerbangan yang akan diupdate: ";
    cin >> kodeInput;
    
    Node *temp = head;
    int posisi = 1;
    bool found = false;
    
    while (temp != nullptr) {
        if (temp->data.kodePenerbangan == kodeInput) {
            cout << "\nData ditemukan pada posisi: " << posisi << endl;
            cout << "Kode: " << temp->data.kodePenerbangan << endl;
            cout << "Tujuan: " << temp->data.tujuan << endl;
            cout << "Status lama: " << temp->data.status << endl;
            
            string statusBaru;
            cout << "Masukkan Status Baru: ";
            cin.ignore();
            getline(cin, statusBaru);
            
            cout << "Update dari '" << temp->data.status << "' ke '" << statusBaru << "'? (y/n): ";
            char konfirmasi;
            cin >> konfirmasi;
            
            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                temp->data.status = statusBaru;
                cout << "Status berhasil diupdate!" << endl;
                
                // Tampilkan info navigasi Double Linked List
                if (temp->prev != nullptr) {
                    cout << "Jadwal Sebelumnya: " << temp->prev->data.kodePenerbangan << endl;
                }
                if (temp->next != nullptr) {
                    cout << "Jadwal Berikutnya: " << temp->next->data.kodePenerbangan << endl;
                }
            } else {
                cout << "Update dibatalkan!" << endl;
            }
            found = true;
            break;
        }
        temp = temp->next;
        posisi++;
    }
    
    if (!found) {
        cout << "Jadwal dengan kode " << kodeInput << " tidak ditemukan!" << endl;
    }
    
    system("pause");
}

// Fitur baru: Tampilkan detail berdasarkan kode
void tampilkanDetailKode() {
    if (head == nullptr) {
        cout << "LinkedList Kosong" << endl;
        system("pause");
        return;
    }
    
    string kodeInput;
    cout << "Masukkan Kode Penerbangan: ";
    cin >> kodeInput;
    
    Node *temp = head;
    int posisi = 1;
    bool found = false;
    
    while (temp != nullptr) {
        if (temp->data.kodePenerbangan == kodeInput) {
            cout << "\n=== DETAIL JADWAL PENERBANGAN ===" << endl;
            cout << "Kode Penerbangan: " << temp->data.kodePenerbangan << endl;
            cout << "Tujuan         : " << temp->data.tujuan << endl;
            cout << "Status         : " << temp->data.status << endl;
            cout << "Posisi dalam List: " << posisi << endl;
            
            // Info navigasi Double Linked List
            if (temp->prev != nullptr) {
                cout << "Jadwal Sebelumnya: " << temp->prev->data.kodePenerbangan 
                     << " ke " << temp->prev->data.tujuan << endl;
            } else {
                cout << "Jadwal Sebelumnya: (Tidak ada - ini jadwal pertama)" << endl;
            }
            
            if (temp->next != nullptr) {
                cout << "Jadwal Berikutnya: " << temp->next->data.kodePenerbangan 
                     << " ke " << temp->next->data.tujuan << endl;
            } else {
                cout << "Jadwal Berikutnya: (Tidak ada - ini jadwal terakhir)" << endl;
            }
            found = true;
            break;
        }
        temp = temp->next;
        posisi++;
    }
    
    if (!found) {
        cout << "Jadwal dengan kode " << kodeInput << " tidak ditemukan!" << endl;
    }
    
    system("pause");
}

// Fitur baru: Cari dan tampilkan detail berdasarkan tujuan
void cariDetailTujuan() {
    if (head == nullptr) {
        cout << "LinkedList Kosong" << endl;
        system("pause");
        return;
    }
    
    string tujuanCari;
    cout << "Masukkan Tujuan yang dicari: ";
    cin.ignore();
    getline(cin, tujuanCari);
    
    Node *temp = head;
    int posisi = 1;
    bool found = false;
    
    while (temp != nullptr) {
        if (temp->data.tujuan.find(tujuanCari) != string::npos) {
            cout << "\n=== JADWAL DITEMUKAN ===" << endl;
            cout << "Kode: " << temp->data.kodePenerbangan << endl;
            cout << "Tujuan: " << temp->data.tujuan << endl;
            cout << "Status: " << temp->data.status << endl;
            cout << "Posisi: " << posisi << endl;
            cout << "=========================" << endl;
            found = true;
        }
        temp = temp->next;
        posisi++;
    }
    
    if (!found) {
        cout << "Tidak ada jadwal ke " << tujuanCari << endl;
    }
    
    system("pause");
}

// Fungsi statistik
void statistikStatus() {
    if (head == nullptr) {
        cout << "LinkedList Kosong" << endl;
        system("pause");
        return;
    }
    
    int tepatWaktu = 0, terlambat = 0, naikPesawat = 0, lainnya = 0;
    Node *temp = head;
    
    while (temp != nullptr) {
        if (temp->data.status == "Tepat Waktu") tepatWaktu++;
        else if (temp->data.status == "Terlambat") terlambat++;
        else if (temp->data.status == "Naik Pesawat") naikPesawat++;
        else lainnya++;
        temp = temp->next;
    }
    
    cout << "\n=== STATISTIK STATUS PENERBANGAN ===" << endl;
    cout << "Tepat Waktu  : " << tepatWaktu << " jadwal" << endl;
    cout << "Terlambat    : " << terlambat << " jadwal" << endl;
    cout << "Naik Pesawat : " << naikPesawat << " jadwal" << endl;
    cout << "Status Lain  : " << lainnya << " jadwal" << endl;
    cout << "Total Jadwal : " << panjangList << " jadwal" << endl;
    
    system("pause");
}

int main() {
    string nama, nim;
    cout << "=== FLIGHT SCHEDULE SYSTEM (DOUBLE LINKED LIST) ===" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);
    
    if (nim.length() < 3) {
        cout << "NIM harus minimal 3 digit!" << endl;
        return 1;
    }
    
    // Inisialisasi berdasarkan NIM
    nimTerakhir = nim.substr(nim.length() - 3);
    posisiSisip = (nim.back() - '0') + 1;
    
    cout << "\nSistem berhasil diinisialisasi!" << endl;
    cout << "3 digit terakhir NIM: " << nimTerakhir << endl;
    cout << "Posisi sisip otomatis: " << posisiSisip << endl;
    system("pause");
    
    int pilihan;
    
    do {
        system("cls");
        cout << "=============================================" << endl;
        cout << "    FLIGHT SCHEDULE SYSTEM (DLL)" << endl;
        cout << "    " << nama << " - " << nim << endl;
        cout << "=============================================" << endl;
        cout << "1. Tambah Jadwal (Awal)" << endl;
        cout << "2. Tambah Jadwal (Akhir)" << endl;
        cout << "3. Sisipkan Jadwal (Posisi " << posisiSisip << " berdasarkan NIM)" << endl;
        cout << "4. Hapus Jadwal Paling Awal" << endl;
        cout << "5. Hapus Jadwal Paling Akhir" << endl;
        cout << "6. Update Status Penerbangan" << endl;
        cout << "7. Tampilkan Semua Jadwal (Maju)" << endl;
        cout << "8. Tampilkan Semua Jadwal (Mundur)" << endl;
        cout << "9. Cari Detail berdasarkan Kode" << endl;
        cout << "10. Cari Detail berdasarkan Tujuan" << endl;
        cout << "11. Statistik Status" << endl;
        cout << "0. Keluar" << endl;
        cout << "=============================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: insertFirst(head, tail); break;
            case 2: insertLast(head, tail); break;
            case 3: insertAt(head, tail); break;
            case 4: deleteFirst(head, tail); break;
            case 5: deleteLast(head, tail); break;
            case 6: updateStatus(); break;
            case 7: 
                printList(head);
                system("pause");
                break;
            case 8: 
                printListReverse(tail);
                system("pause");
                break;
            case 9: tampilkanDetailKode(); break;
            case 10: cariDetailTujuan(); break;
            case 11: statistikStatus(); break;
            case 0:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                system("pause");
        }
    } while (pilihan != 0);
    
    return 0;
}