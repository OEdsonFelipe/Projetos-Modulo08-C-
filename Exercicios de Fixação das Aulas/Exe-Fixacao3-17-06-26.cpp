#include<iostream>
#include<string>

using namespace std;

class Produto{
    protected:
        string nome;
        int preco;

    public:
    Produto (string n, double p) : nome(n), preco(p){}

    virtual void mostrarSalario (){
        
    
    }
};