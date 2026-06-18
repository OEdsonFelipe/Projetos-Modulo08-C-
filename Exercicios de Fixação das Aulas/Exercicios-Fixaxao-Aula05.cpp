#include<iostream>
using namespace std;
int main(){
    int numeros[5] = {10,20,30,40,50};
    cout << "Primeiro elemento: " << numeros[0] << endl;
    cout << "Ultimo elemento: " << numeros[4] << endl;
    cout << "Todos os elementos do array: " << endl;
    for(int i = 0; i < 5; i++){
        cout << numeros[i] << " ";
    }
    cout << endl;
    numeros[2] = 99; // Modificando o terceiro elemento
    cout << "Array após modificação." << numeros[2] << endl;
    return 0;
}