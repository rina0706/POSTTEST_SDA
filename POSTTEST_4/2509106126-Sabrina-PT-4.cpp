#include <iostream>
#include <string>
using namespace std;

struct Tiket {
    string namaPenumpang;
    string rute;
    Tiket* next; 
};

Tiket* front = NULL;
Tiket* rear = NULL;

Tiket* top = NULL;

void enqueue(string nama, string rute) {
    Tiket* baru = new Tiket{nama, rute, NULL};

    if (rear == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Penumpang masuk antrian\n";
}

void push(Tiket* data) {
    Tiket* baru = new Tiket{data->namaPenumpang, data->rute, NULL};

    baru->next = top;
    top = baru;
}

void dequeue() {
    if (front == NULL) {
        cout << "Antrian kosong\n";
        return;
    }

    Tiket* hapus = front;

    cout << "Memproses tiket:\n";
    cout << "Nama: " << hapus->namaPenumpang << endl;
    cout << "Rute: " << hapus->rute << endl;

    push(hapus);

    front = front->next;
    if (front == NULL) rear = NULL;

    delete hapus;
}

void popRiwayat() {
    if (top == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }

    Tiket* hapus = top;
    cout << "Menghapus riwayat: " << hapus->namaPenumpang << endl;

    top = top->next;
    delete hapus;
}

void peek() {
    if (front != NULL) {
        cout << "Antrian terdepan: " << front->namaPenumpang << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (top != NULL) {
        cout << "Transaksi terakhir: " << top->namaPenumpang << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

void tampilAntrian() {
    if (front == NULL) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "=== DAFTAR ANTRIAN ===\n";
    Tiket* p = front;

    while (p != NULL) {
        cout << "Nama: " << p->namaPenumpang
             << " | Rute: " << p->rute << endl;
        p = p->next;
    }
}

void tampilRiwayat() {
    if (top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "=== RIWAYAT TRANSAKSI ===\n";
    Tiket* p = top;

    while (p != NULL) {
        cout << "Nama: " << p->namaPenumpang
             << " | Rute: " << p->rute << endl;
        p = p->next;
    }
}

int main() {
    int pilih;
    string nama, rute;

    do {
        cout << "\n=== MENU KERETA API ===\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Proses Tiket\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Tampilkan Riwayat\n";
        cout << "5. Pop Riwayat\n";
        cout << "6. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
        case 1:
            cout << "Nama: ";
            getline(cin, nama);
            cout << "Rute: ";
            getline(cin, rute);
            enqueue(nama, rute);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            tampilAntrian();
            break;

        case 4:
            tampilRiwayat();
            break;

        case 5:
            popRiwayat();
            break;

        case 6:
            peek();
            break;
        }

    } while (pilih != 0);

    return 0;
}
