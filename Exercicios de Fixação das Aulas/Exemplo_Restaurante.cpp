#include<iomanip>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Restaurante{
private:
    string nome;
    vector<string> cardapio;
    vector<float> valor_prato;
    
public:
    Restaurante(string nome){
        this -> nome = nome;
    }

    void adicionarPrato(string nome_prato, float preco_prato){
        cardapio.push_back(nome_prato);
        valor_prato.push_back(preco_prato);
        cout << "[+]Adicionar um prato: " << nome_prato << "adicionado ao cardapio!" << endl;

    }

    

    string get_nome(){
        return nome;
    }

    void set_nome (string novo_nome){
        nome = novo_nome;
         cout << "Nome do restaurante aalterado! " << novo_nome << endl;
    }

    void listarCardapio(){
        cout << "======== Cardapio do " << nome << "==========" << endl;
        for (int i=0; i<cardapio.size();i++) {
            cout << "Prato " << i+1 << ": " << cardapio[i] << "Valor: R$ " << valor_prato[i] << endl;
        }
        
    }

    void atenderCliente(string nome_cliente, string prato){
        cout << "O(a) " << nome_cliente << endl; 
        cout << "Pediu: " << prato << endl;

    }
};

int main(){
    Restaurante meu_restaurante ("Sabor Caseiro");

    meu_restaurante.adicionarPrato("Bife acebolado.", 20.00);
    meu_restaurante.adicionarPrato("Lasanha de carne para 4 pessoas!", 50.00);
    meu_restaurante.adicionarPrato("Macarrão ao molho bolonhesa", 35.00);

    meu_restaurante.listarCardapio();

    meu_restaurante.set_nome("Raizes do Norte.");

    meu_restaurante.listarCardapio();

    return 0;
}
