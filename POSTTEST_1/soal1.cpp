#include <iostream>
using namespace std;

/*
Analisis Kompleksitas FindMin

Pseudocode:
min ? A[0]                ? 1 operasi
for i ? 1 to n-1          ? (n-1) iterasi
   if A[i] < min          ? (n-1) kali
      min ? A[i]          ? Bergantung kapada kondisi

Kondisi Minimal(n) (Best Case):
Apabila elemen pertama sudah menjadi minimum,
tidak terdapat assignment dalam if.
Kondisi Minmal(n) = 1 + (n-1)
        = n
Besar-O = O(n)

Kondisi Maximal(n) (Worst Case):
Jika array terurut menurun,
assignment terjadi setiap iterasi.
Kondisi Maximal(n) = 1 + (n-1) + (n-1)
        = 2n - 1
Besar-O = O(n)

Kesimpulan dari pseudocode diatas ini:
Best Case  = O(n)
Worst Case = O(n)
*/

void FindMin(int A[], int n) {
    int minimal = A[0];
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] < minimal) {
            minimal = A[i];
            index = i;
        }
    }

    cout << "Nilai minimum: " << minimal << endl;
    cout << "Indeks: " << index << endl;
}

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};

    FindMin(A, 8);

    return 0;
}
