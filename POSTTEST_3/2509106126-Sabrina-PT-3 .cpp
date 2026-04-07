#include <iostream>
#include <string>
using namespace std;

struct Tiket {
    string namaPenumpang;
    string rute;
};

Tiket queueTiket[100];
int front = 0, rear = -1;

Tiket stackRiwayat[100];
int top = -1;

void enqueue(string nama, string rute) {
    rear++;
    queueTiket[rear].namaPenumpang = nama;
    queueTiket[rear].rute = rute;
    cout << "Penumpang masuk antrian!\n";
}

void dequeue() {
    if (front > rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    Tiket t = queueTiket[front];
    front++;

    cout << "Memproses tiket:\n";
    cout << "Nama: " << t.namaPenumpang << endl;
    cout << "Rute: " << t.rute << endl;

    top++;
    stackRiwayat[top] = t;
}

void peek() {
    if (front <= rear) {
        cout << "Antrian terdepan: " 
             << queueTiket[front].namaPenumpang << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (top >= 0) {
        cout << "Transaksi terakhir: " 
             << stackRiwayat[top].namaPenumpang << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

void popRiwayat() {
    if (top < 0) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Menghapus riwayat: "
         << stackRiwayat[top].namaPenumpang << endl;
    top--;
}

void tampilAntrian() {
    if (front > rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "=== DAFTAR ANTRIAN ===\n";
    for (Tiket* p = &queueTiket[front]; p <= &queueTiket[rear]; p++) {
        cout << "Nama: " << p->namaPenumpang 
             << " | Rute: " << p->rute << endl;
    }
}

void tampilRiwayat() {
    if (top < 0) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "=== RIWAYAT TRANSAKSI ===\n";
    for (Tiket* p = &stackRiwayat[0]; p <= &stackRiwayat[top]; p++) {
        cout << "Nama: " << p->namaPenumpang 
             << " | Rute: " << p->rute << endl;
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
