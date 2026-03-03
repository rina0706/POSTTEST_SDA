#include <iostream>
using namespace std;

void menukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    cout << "Memasukkan variabel x: ";
    cin >> x;
    cout << "Memasukkan variabel y: ";
    cin >> y;

    cout << "\nSebelum variabelnya ditukar:\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    menukar(x, y);

    cout << "\nSesudah variabelnya ditukar:\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}
