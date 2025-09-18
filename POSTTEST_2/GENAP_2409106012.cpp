#include <iostream>
#include <string>
using namespace std;

// Struct untuk jadwal penerbangan sesuai modul
struct JadwalPenerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    JadwalPenerbangan* next;
};

// Variabel global head sesuai modul
JadwalPenerbangan* head = nullptr;
int jumlahJadwal = 0;
string nimTerakhir;
int posisiSisip;

// Fungsi untuk generate kode penerbangan
string generateKodePenerbangan() {
    if (jumlahJadwal == 0) {
        return "JT-" + nimTerakhir;
    } else {
        return "JT-" + nimTerakhir + "-" + to_string(jumlahJadwal);
    }
}

// Fungsi untuk cek apakah list kosong (sesuai modul)
bool isEmpty() {
    return head == nullptr;
}

// Fungsi transversal/display (sesuai modul)
void transversal() {
    if (isEmpty()) {
        cout << ">> LinkedList kosong <<" << endl;
        return;
    }
    
    cout << "\n=== SEMUA JADWAL PENERBANGAN ===" << endl;
    cout << "Total: " << jumlahJadwal << " jadwal\n" << endl;
    
    JadwalPenerbangan* temp = head;
    int nomor = 1;
    
    while (temp != nullptr) {
        cout << nomor << ". " << temp->kodePenerbangan << " | " 
             << temp->tujuan << " | " << temp->status << endl;
        temp = temp->next;
        nomor++;
    }
}

// 1. Add Last - Tambah jadwal di akhir (sesuai modul)
void addLast() {
    JadwalPenerbangan* nodeBaru = new JadwalPenerbangan;
    nodeBaru->kodePenerbangan = generateKodePenerbangan();
    nodeBaru->next = nullptr;
    
    cout << "Kode Penerbangan: " << nodeBaru->kodePenerbangan << " (Auto)" << endl;
    cout << "Masukkan Tujuan: ";
    cin.ignore();
    getline(cin, nodeBaru->tujuan);
    cout << "Masukkan Status: ";
    getline(cin, nodeBaru->status);
    
    // Jika linked list kosong
    if (head == nullptr) {
        head = nodeBaru;
    } else {
        // Traversal ke node terakhir
        JadwalPenerbangan* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
    
    jumlahJadwal++;
    cout << "Jadwal berhasil ditambahkan!" << endl;
}

// 2. Add Specific - Sisipkan jadwal di posisi tertentu (sesuai modul)
void addMiddle() {
    if (posisiSisip > jumlahJadwal + 1) {
        cout << ">> Posisi tidak boleh melebihi panjang list <<" << endl;
        cout << "Menambah di akhir list." << endl;
        addLast();
        return;
    }
    
    if (posisiSisip <= 1) {
        // Add First
        JadwalPenerbangan* nodeBaru = new JadwalPenerbangan;
        nodeBaru->kodePenerbangan = generateKodePenerbangan();
        
        cout << "Posisi sisip: " << posisiSisip << " (berdasarkan NIM)" << endl;
        cout << "Kode Penerbangan: " << nodeBaru->kodePenerbangan << " (Auto)" << endl;
        cout << "Masukkan Tujuan: ";
        cin.ignore();
        getline(cin, nodeBaru->tujuan);
        cout << "Masukkan Status: ";
        getline(cin, nodeBaru->status);
        
        nodeBaru->next = head;
        head = nodeBaru;
        jumlahJadwal++;
        cout << "Jadwal berhasil disisipkan di posisi " << posisiSisip << "!" << endl;
        return;
    }
    
    JadwalPenerbangan* temp = head;
    int hitung = 1;
    
    while (temp != nullptr && hitung < posisiSisip - 1) {
        temp = temp->next;
        hitung++;
    }
    
    if (temp == nullptr) {
        cout << ">> Posisi tidak boleh melebihi panjang list <<" << endl;
        return;
    } else {
        JadwalPenerbangan* nodeBaru = new JadwalPenerbangan;
        nodeBaru->kodePenerbangan = generateKodePenerbangan();
        
        cout << "Posisi sisip: " << posisiSisip << " (berdasarkan NIM)" << endl;
        cout << "Kode Penerbangan: " << nodeBaru->kodePenerbangan << " (Auto)" << endl;
        cout << "Masukkan Tujuan: ";
        cin.ignore();
        getline(cin, nodeBaru->tujuan);
        cout << "Masukkan Status: ";
        getline(cin, nodeBaru->status);
        
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
        jumlahJadwal++;
        cout << "Jadwal berhasil disisipkan di posisi " << posisiSisip << "!" << endl;
    }
}

// 3. Delete First - Hapus jadwal paling awal (sesuai modul)
void deleteFirst() {
    if (isEmpty()) {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    
    cout << "Jadwal yang akan dihapus: " << head->kodePenerbangan << " - " << head->tujuan << endl;
    cout << "Yakin hapus? (y/n): ";
    char konfirmasi;
    cin >> konfirmasi;
    
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        JadwalPenerbangan* temp = head;
        head = head->next;
        delete temp;
        jumlahJadwal--;
        cout << "Jadwal berhasil dihapus!" << endl;
    } else {
        cout << "Penghapusan dibatalkan!" << endl;
    }
}

// 4. Edit Data - Update status penerbangan (sesuai modul)
void editData() {
    if (isEmpty()) {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    
    string kodeInput;
    cout << "Masukkan Kode Penerbangan: ";
    cin >> kodeInput;
    
    JadwalPenerbangan* temp = head;
    int posisi = 1;
    
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kodeInput) {
            cout << "Data ditemukan pada posisi: " << posisi << endl;
            cout << "Kode: " << temp->kodePenerbangan << endl;
            cout << "Tujuan: " << temp->tujuan << endl;
            cout << "Data lama: " << temp->status << endl;
            
            string statusBaru;
            cout << "Masukkan Status Baru: ";
            cin.ignore();
            getline(cin, statusBaru);
            
            cout << "Update dari '" << temp->status << "' ke '" << statusBaru << "'? (y/n): ";
            char konfirmasi;
            cin >> konfirmasi;
            
            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                temp->status = statusBaru;
                cout << "Data berhasil diubah menjadi: " << temp->status << endl;
            } else {
                cout << "Update dibatalkan!" << endl;
            }
            return;
        }
        temp = temp->next;
        posisi++;
    }
    
    cout << ">> Posisi tidak valid <<" << endl;
    cout << "Jadwal dengan kode " << kodeInput << " tidak ditemukan!" << endl;
}

// Fungsi tambahan: Cari jadwal berdasarkan tujuan
void cariJadwal() {
    if (isEmpty()) {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    
    string tujuanCari;
    cout << "Masukkan Tujuan yang dicari: ";
    cin.ignore();
    getline(cin, tujuanCari);
    
    JadwalPenerbangan* temp = head;
    int posisi = 1;
    bool ditemukan = false;
    
    while (temp != nullptr) {
        if (temp->tujuan.find(tujuanCari) != string::npos) {
            cout << "Ditemukan: " << temp->kodePenerbangan << " | " 
                 << temp->tujuan << " | " << temp->status 
                 << " (Posisi: " << posisi << ")" << endl;
            ditemukan = true;
        }
        temp = temp->next;
        posisi++;
    }
    
    if (!ditemukan) {
        cout << "Tidak ada jadwal ke " << tujuanCari << endl;
    }
}

// Fungsi tambahan: Hitung statistik status
void hitungStatus() {
    if (isEmpty()) {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    
    int tepatWaktu = 0, terlambat = 0, naikPesawat = 0;
    JadwalPenerbangan* temp = head;
    
    while (temp != nullptr) {
        if (temp->status == "Tepat Waktu") tepatWaktu++;
        else if (temp->status == "Terlambat") terlambat++;
        else if (temp->status == "Naik Pesawat") naikPesawat++;
        temp = temp->next;
    }
    
    cout << "=== STATISTIK STATUS ===" << endl;
    cout << "Tepat Waktu: " << tepatWaktu << endl;
    cout << "Terlambat: " << terlambat << endl;
    cout << "Naik Pesawat: " << naikPesawat << endl;
}

// Fungsi clear list (sesuai modul)
void clearList() {
    JadwalPenerbangan* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    jumlahJadwal = 0;
    cout << "Linked list berhasil dikosongkan." << endl;
}

void tampilkanMenu(string nama, string nim) {
    cout << "\n====================================\n";
    cout << "    FLIGHT SCHEDULE SYSTEM\n";
    cout << "    " << nama << " - " << nim << "\n";
    cout << "====================================\n";
    cout << "1. Tambah Jadwal Penerbangan\n";
    cout << "2. Sisipkan Jadwal Penerbangan\n";
    cout << "3. Hapus Jadwal Paling Awal\n";
    cout << "4. Update Status Penerbangan\n";
    cout << "5. Tampilkan Semua Jadwal\n";
    cout << "6. Cari Jadwal\n";
    cout << "7. Statistik Status\n";
    cout << "0. Keluar\n";
    cout << "====================================\n";
    cout << "Pilihan: ";
}

int main() {
    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);
    
    if (nim.length() < 3) {
        cout << "NIM harus minimal 3 digit!" << endl;
        return 1;
    }
    
    // Inisialisasi variabel global berdasarkan NIM
    nimTerakhir = nim.substr(nim.length() - 3);
    posisiSisip = (nim.back() - '0') + 1;
    
    cout << "\nSistem berhasil dibuat!" << endl;
    cout << "3 digit terakhir NIM: " << nimTerakhir << endl;
    cout << "Posisi sisip: " << posisiSisip << endl;
    
    int pilihan;
    do {
        tampilkanMenu(nama, nim);
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: 
                addLast(); 
                break;
            case 2: 
                addMiddle(); 
                break;
            case 3: 
                deleteFirst(); 
                break;
            case 4: 
                editData(); 
                break;
            case 5: 
                transversal(); 
                break;
            case 6: 
                cariJadwal(); 
                break;
            case 7: 
                hitungStatus(); 
                break;
            case 0: 
                clearList();
                cout << "Terima kasih!" << endl; 
                break;
            default: 
                cout << "Pilihan tidak valid!" << endl; 
                break;
        }
        
        if (pilihan != 0) {
            cout << "\nTekan Enter...";
            cin.ignore();
            cin.get();
        }
        
    } while (pilihan != 0);
    
    return 0;
}