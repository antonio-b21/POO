#include <iostream>
#include "Complex.h"
#include "Vector.h"
#include "Stiva.h"
#include "Coada.h"

using namespace std;

void myterminate() {
    cerr << "Memorie insuficienta";
    exit(1);
}

int main()
{
    set_terminate(myterminate);
    int n;

    ////  n obiecte Complex
    //cin >> n;
    //Complex* complexe = new Complex[n];
    //for (int i = 0; i < n; i++) {
    //    cin >> complexe[i];
    //}
    //for (int i = 0; i < n; i++) {
    //    cout << complexe[i] << " ";
    //}

    ////  n obiecte Vector
    //cin >> n;
    //Vector* vectori = new Vector[n];
    //for (int i = 0; i < n; i++) {
    //    cin >> vectori[i];
    //}
    //for (int i = 0; i < n; i++) {
    //    cout << vectori[i] << " ";
    //}

    ////  n obiecte Stiva
    //cin >> n;
    //Stiva* stive = new Stiva[n];
    //for (int i = 0; i < n; i++) {
    //    cin >> stive[i];
    //}
    //for (int i = 0; i < n; i++) {
    //    cout << stive[i] << " ";
    //}

    ////  n obiecte Coada
    //cin >> n;
    //Coada* cozi = new Coada[n];
    //for (int i = 0; i < n; i++) {
    //    cin >> cozi[i];
    //}
    //for (int i = 0; i < n; i++) {
    //    cout << cozi[i] << " ";
    //}


    return 0;
}
