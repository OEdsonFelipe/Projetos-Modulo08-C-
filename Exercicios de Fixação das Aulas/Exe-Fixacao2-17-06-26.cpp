#include<iostream>
#include<string>

using namespace std;

class Funcionario{
    protected:
        string nome;
        double salario_base;

    public:
        Funcionario(string n , double s) : nome(n), salario_base(s){}
        
    virtual void mostrarSalario() {
        cout << "Funcionario: " << nome << " | Salario base: R$ " << salario_base << endl;
    }

};

class Gerente : public Funcionario{
    private:
    string nome;

    public:
        Gerente(string n, double s) : Funcionario(n,s){}

    void mostrarSalario (){
        double salario_comBonus = salario_base * 1.20;
        cout << "Gerente: " << nome << " | Salario com Bonus: R$ " << salario_comBonus << endl;
    }

};

int main(){
    Funcionario f1("Jose",5000.00);
    f1.mostrarSalario();

    Gerente g1("Ana Flavia", 3500.00);
    g1.mostrarSalario();
}