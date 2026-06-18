#include<iostream>

using namespace std;

class Veiculo{
    protected:
        string marca;

    public:
        Veiculo(string n) : marca(n){}
};

class Carro : public Veiculo{
    private:
    string modelo;
    
    public:
        Carro(string n, string m): Veiculo(n), modelo(m){}

};

int main(){
    Veiculo carro("Toyota");
    Carro mod("Pick-up", "Hillux");

    return 0;



}