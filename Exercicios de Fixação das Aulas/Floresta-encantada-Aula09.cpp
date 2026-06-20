#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Personagem {

    protected: 
        string nome;
        int nivel_poder;
        string tipo;
    
    public:
        Personagem(string n, int p, string t) : nome(n), nivel_poder(p), tipo(t){}

    virtual void exibir_info() const{
        cout << "[Poder: " << setw(3) << nivel_poder << "] Nome: " << nome << " | Tipo: " << tipo << endl;
    }

    int getPoder() const {
        return nivel_poder;
    }

}; 

class ChefeDaFloresta : public Personagem {
    private: 
    string reino;

    public: 
        ChefeDaFloresta(string n, int p, string t, string r) : Personagem(n, p, t), reino(r){}

        void exibir_info() const override {
            cout << "[Poder: " << setw(3) << nivel_poder << "] Nome: " << nome << " | Tipo: " << tipo << " | Reino: " << reino << " (CHEFE)" << endl;
        }

};
struct Nodo {
    Personagem* personagem; // Ponteiro para a classe base
    Nodo* esquerda;
    Nodo* direita;

    Nodo(Personagem* p) : personagem(p), esquerda(nullptr), direita(nullptr) {}
};

// 4. Estrutura da Árvore Binária de Busca
class ArvoreFloresta {
private:
    Nodo* raiz;

    void inserir_recursivo(Nodo*& nodo_atual, Personagem* p) {
        if (nodo_atual == nullptr) {
            nodo_atual = new Nodo(p);
        } else if (p->getPoder() < nodo_atual->personagem->getPoder()) {
            inserir_recursivo(nodo_atual->esquerda, p);
        } else {
            inserir_recursivo(nodo_atual->direita, p);
        }
    }

    void percorrer_recursivo(Nodo* nodo_atual) const {
        if (nodo_atual != nullptr) {
            percorrer_recursivo(nodo_atual->esquerda);
            nodo_atual->personagem->exibir_info();
            percorrer_recursivo(nodo_atual->direita);
        }
    }

    // Função para limpar a memória ao destruir a árvore
    void destruir_arvore(Nodo* nodo_atual) {
        if (nodo_atual != nullptr) {
            destruir_arvore(nodo_atual->esquerda);
            destruir_arvore(nodo_atual->direita);
            delete nodo_atual->personagem; // Libera o Personagem
            delete nodo_atual;             // Libera o Nó
        }
    }

public:
    ArvoreFloresta() : raiz(nullptr) {}

    ~ArvoreFloresta() {
        destruir_arvore(raiz);
    }

    void inserir(Personagem* p) {
        inserir_recursivo(raiz, p);
    }

    void percorrer_em_ordem() const {
        cout << string(65, '-') << endl;
        cout << "🌲 HABITANTES DA FLORESTA ENCANTADA (Do Menor p/ o Maior Poder) 🌲" << endl;
        cout << string(65, '-') << endl;
        percorrer_recursivo(raiz);
        cout << string(65, '-') << endl;
    }
};

// ==========================================
// TESTANDO O DESAFIO
// ==========================================
int main() {
    ArvoreFloresta floresta;

    // Criando e inserindo personagens normais
    floresta.inserir(new Personagem("Lupi", 30, "Animal"));
    floresta.inserir(new Personagem("Mago Merlin", 80, "Mago"));
    floresta.inserir(new Personagem("Fada Luminosa", 50, "Fada"));
    floresta.inserir(new Personagem("Sapo Zeca", 10, "Animal"));

    // Criando e inserindo os Chefes
    floresta.inserir(new ChefeDaFloresta("Rainha Elfa", 90, "Elfo", "Vale de Cristal"));
    floresta.inserir(new ChefeDaFloresta("Chefe Dragao", 150, "Dragao", "Montanhas de Fogo"));

    // Exibe os habitantes ordenados
    floresta.percorrer_em_ordem();

    return 0;
}