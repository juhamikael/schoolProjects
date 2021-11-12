
#include <iostream>
using namespace std;
void taulukkoa(int values[], int size);
void taulukkob(int *values_ptr, int size);

int main() {
    int const size = 10;
    int values[size] = { 0 };
    cout << "Numerot ennen ensimmaista funktiokutsua:       ";

    //----------------------------------------------------
    //
    for (int i = 0; i < size; i++) {
        cout << values[i] << " ";
    }
    cout << endl;

    cout << "Numerot ensimmaisen funktiokutsun jalkeen:     ";
    taulukkoa(values, size);

    cout << endl;

    int* values_ptr = values;

    //-----------------------------------------------

    cout << "Numerot ennen toista funktiokutsua:            ";
    for (int i = 0; i < size; i++) {
        cout << *(values_ptr + i) << " ";
    }
    cout << endl;

    cout << "Numerot toisen funktiokutsun jalkeen:          ";
    taulukkob(values, size);

return 0;
}


void taulukkoa(int values[], int size) {
    for (int i = 0; i < 10; i++) {
        cout << values[i] + 1 << " ";
    }
}
void taulukkob(int* values_ptr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(values_ptr + i) +1 << " ";
    }
}
