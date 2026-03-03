#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];

    for (int i = 0; i < 5; i++) {
        cout << "\nMahasiswa yang ke-" << i+1 << endl;
        cout << "Nama dari Mahasiswa: ";
        cin >> mhs[i].nama;
        cout << "NIM dari Mahasiswa  : ";
        cin >> mhs[i].nim;
        cout << "IPK dari Mahasiswa : ";
        cin >> mhs[i].ipk;
    }

    float maxIPK = mhs[0].ipk;
    int index = 0;

    for (int i = 1; i < 5; i++) {
        if (mhs[i].ipk > maxIPK) {
            maxIPK = mhs[i].ipk;
            index = i;
        }
    }

    cout << "\nMahasiswa dengan IPK Tertinggi:\n";
    cout << "Nama dari Mahasiswa : " << mhs[index].nama << endl;
    cout << "NIM dari Mahasiswa : " << mhs[index].nim << endl;
    cout << "IPK dari Mahasiswa : " << mhs[index].ipk << endl;

    return 0;
}
