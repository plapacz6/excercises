#include <iostream>
using namespace std;

int & return_refernce() {
    int y[9] = {29, 29, 29, 29, 29, 29, 29, 29, 29};
    for(int i = 0; i < 9; i++) {
        y[9] = 29;
    }
    int x = 9;
    int& ref_x = x;
    return ref_x;
}

int* return_pointer() {
    int x = 9;
    int*  p_x = &x;
    return p_x;
}

int nadpisz_stos(int x) {
    int a[10];
    for(int i = 0; i < 10; i++) {
        a[i] = x;
    }
    return x;
}

int main() {

    //funkcja przyjmuje x przez kopie (vartosc)
    cout << return_refernce() << endl;
    cout << (*(return_pointer())) << endl;

    int& rx = return_refernce();
    for(size_t i = 0; i < 10; i++) {
        nadpisz_stos(1019);
        cout << "... ";
    }
    cout << endl;

    int* px = return_pointer();
    for(size_t i = 0; i < 10; i++) {
        nadpisz_stos(1029);
        cout << "... ";
    }
    cout << endl;

    cout << (*px) << endl;//px wkazuje na adres w ktorym juz jest co innego
    cout << rx << endl; //rx referencja wskazujaca na zmienna ktora juz
    //nie istnije, a co innego jest w miejcu tej niejistniejacej zmiennej

    return 0;
}
