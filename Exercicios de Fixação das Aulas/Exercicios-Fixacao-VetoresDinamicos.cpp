#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> valores; // Declaração de um vetor dinâmico de inteiros

    // Adicionando elementos ao vetor
    valores.push_back(10);
    valores.push_back(20);
    valores.push_back(30);

    // Exibindo os elementos do vetor
    cout << "Primeiro:" << valores[0] << endl; // Acessando o primeiro elemento do vetor
    cout << "Tamanho: " << valores.size() << endl; // Exibindo o tamanho do vetor
    cout << "Elementos do vetor: ";
    for (int i = 0; i < valores.size(); i++) {
        cout << valores[i] << " ";
    }
    cout << endl;

    // Modificando um elemento do vetor
    valores.pop_back(); // Removendo o último elemento do vetor

    cout << "Após remover o último elemento:" << endl;
    for (int x : valores) { // Usando um loop for-each para exibir os elementos do vetor
        cout << x << " ";
    }
    cout << endl;

    return 0;
}