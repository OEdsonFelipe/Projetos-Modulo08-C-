#include<iostream>
#include<string>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;

class Aluno{
    private:
    string nome;
    double nota;

    public:
    Aluno(string nome, double nota){
        this -> nome = nome;
        if (nota >= 0 && nota <= 10){
            this -> nota = nota;
        }else{
            this -> nota = 0;
            cout << "Nota inicial invalida! Definida como 0." << endl;
        }
    }

    string get_nome(){
        return nome;
    }

    double get_nota(){
        return nota;
    }


    void set_nota(double nova_nota) {
        if (nova_nota >= 0 && nova_nota <= 10){
            nota = nova_nota;
            cout << "Nota atualizada para " << nova_nota << endl;
        }else{
            cout << "Nota inválida! Digite um valor entre 0 e 10." << endl;
        }
    }
    void exibir_informacoes(){
        cout << "Aluno: " << nome << " | Nota: " << nota << endl;
    }
};

int main(){
    //testando o código!
    Aluno a("Carlos", 8.5);
    a.exibir_informacoes();

    a.set_nota(12); //Deve mostrar um erro, porque o valor maior que intervalo definido!
    a.exibir_informacoes();

    a.set_nota(9.5);
    a.exibir_informacoes();

    return 0;


}
