#include <iostream>
#include <cmath>
using namespace std;

struct Kereta {
    int no;
    string nama, asal, tujuan;
    int harga;
};

void tampil(Kereta* arr, int n) {
    cout << "\nData Kereta:\n";
    for (int i = 0; i < n; i++) {
        cout << (arr+i)->no << " | "
             << (arr+i)->nama << " | "
             << (arr+i)->asal << " -> "
             << (arr+i)->tujuan << " | "
             << (arr+i)->harga << endl;
    }
}

void tambah(Kereta* arr, int &n) {
    cout << "\nTambah Data:\n";
    cout << "No kereta: "; cin >> arr[n].no;
    cout << "Nama penumpang: "; cin >> arr[n].nama;
    cout << "Asal kota: "; cin >> arr[n].asal;
    cout << "Tujuan kota: "; cin >> arr[n].tujuan;
    cout << "Harga kereta: "; cin >> arr[n].harga;
    n++;
}

void linear(Kereta* arr, int n, string asal, string tujuan) {
    bool ketemu = false;
    for (int i = 0; i < n; i++) {
        if ((arr+i)->asal == asal && (arr+i)->tujuan == tujuan) {
            cout << "Ketemu: " << (arr+i)->nama << endl;
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Tidak ada\n";
}

int jump(Kereta* arr, int n, int key) {
    int step = sqrt(n);
    int prev = 0;

    while ((arr + min(step, n) - 1)->no < key) {
        cout << "Cek index " << min(step, n)-1 << endl;
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    for (int i = prev; i < min(step, n); i++) {
        cout << "Cek index " << i << endl;
        if ((arr+i)->no == key) return i;
    }
    return -1;
}

void tukar(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void sortHarga(Kereta* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if ((arr+j)->harga < (arr+min)->harga)
                min = j;
        }
        tukar(arr+i, arr+min);
    }
}

void merge(Kereta* arr, int l, int m, int r) {
    Kereta temp[100];
    int i=l, j=m+1, k=l;

    while(i<=m && j<=r) {
        if ((arr+i)->nama < (arr+j)->nama)
            temp[k++] = *(arr+i++);
        else
            temp[k++] = *(arr+j++);
    }

    while(i<=m) temp[k++] = *(arr+i++);
    while(j<=r) temp[k++] = *(arr+j++);

    for(int x=l; x<=r; x++)
        *(arr+x) = temp[x];
}

void mergeSort(Kereta* arr, int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    Kereta data[100] = {
        {1,"Agus","JKT","BGD",300},
        {2,"Bagus","MALANG","SOLO",200},
        {3,"Cindy","SBY","MALANG",150}
    };

    int n = 3, pil;

    do {
        cout << "\n1.Tampilkan data kereta\n2.Tambah data kereta\n3.Cari Rute kereta\n4.Cari No kerata\n5.Sort Nama kereta\n6.Sort Harga kereta\n0.Keluar\nPilih: ";
        cin >> pil;

        if (pil == 1) tampil(data,n);

        else if (pil == 2) tambah(data,n);

        else if (pil == 3) {
            string a,t;
            cout << "Asal: "; cin >> a;
            cout << "Tujuan: "; cin >> t;
            linear(data,n,a,t);
        }

        else if (pil == 4) {
            int key;
            cout << "No: "; cin >> key;
            int hasil = jump(data,n,key);
            if (hasil != -1)
                cout << "Ketemu: " << data[hasil].nama << endl;
            else
                cout << "Tidak ada\n";
        }

        else if (pil == 5) {
            mergeSort(data,0,n-1);
            cout << "Urut nama selesai\n";
        }

        else if (pil == 6) {
            sortHarga(data,n);
            cout << "Urut harga selesai\n";
        }

    } while (pil != 0);

    return 0;
}
