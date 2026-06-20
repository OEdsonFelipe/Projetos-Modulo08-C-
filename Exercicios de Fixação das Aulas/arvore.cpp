#include <iostream>
#include <vector>
#include <memory>
#include <optional>

using namespace std;

// Classe Nó
class No {
public:
    int valor;
    optional<int> indice_esquerda;  // referência lógica (índice)
    optional<int> indice_direita;   // referência lógica (índice)
    
    // Construtor
    No(int valor, optional<int> esquerda = nullopt, optional<int> direita = nullopt)
        : valor(valor), indice_esquerda(esquerda), indice_direita(direita) {}
};

// Classe Árvore Binária
class ArvoreBinaria {
private:
    vector<No> nos;  // lista de nós
    
public:
    // Adicionar nó
    void adicionar_no(int valor, optional<int> indice_esquerda = nullopt, 
                      optional<int> indice_direita = nullopt) {
        No no(valor, indice_esquerda, indice_direita);
        nos.push_back(no);
    }
    
    // Exibir estrutura da árvore
    void exibir() const {
        for (size_t i = 0; i < nos.size(); i++) {
            cout << "Nó " << i << ": valor=" << nos[i].valor;
            
            if (nos[i].indice_esquerda.has_value()) {
                cout << ", esquerda=" << nos[i].indice_esquerda.value();
            } else {
                cout << ", esquerda=None";
            }
            
            if (nos[i].indice_direita.has_value()) {
                cout << ", direita=" << nos[i].indice_direita.value();
            } else {
                cout << ", direita=None";
            }
            
            cout << endl;
        }
    }
    
    // Percorrer em ordem (in-order traversal)
    void percorrer_em_ordem(optional<int> indice = 0) {
        if (!indice.has_value()) {
            return;
        }
        
        int idx = indice.value();
        
        // Verifica se o índice é válido
        if (idx < 0 || idx >= static_cast<int>(nos.size())) {
            return;
        }
        
        // Percorre subárvore esquerda
        percorrer_em_ordem(nos[idx].indice_esquerda);
        
        // Visita o nó atual
        cout << nos[idx].valor << " ";
        
        // Percorre subárvore direita
        percorrer_em_ordem(nos[idx].indice_direita);
    }
};

int main() {
    // Criando a árvore binária
    ArvoreBinaria arvore;
    
    // Adicionando nós
    arvore.adicionar_no(10, 1, 2);        // nó raiz (esquerda=1, direita=2)
    arvore.adicionar_no(5, 3, 4);         // nó esquerdo da raiz (direita=3)
    arvore.adicionar_no(15, nullopt, 5);  // nó direito da raiz
    arvore.adicionar_no(4);               // nó direito da raiz
    arvore.adicionar_no(7);               // nó direito do nó 5
    arvore.adicionar_no(16);              // nó direito do nó 15
    
    // Exibindo estrutura da árvore
    cout << "Estrutura da Árvore:" << endl;
    arvore.exibir();
    
    // Percorrendo em ordem
    cout << "\nPercorrendo em ordem:" << endl;
    arvore.percorrer_em_ordem(0);
    cout << endl;
    
    return 0;
}