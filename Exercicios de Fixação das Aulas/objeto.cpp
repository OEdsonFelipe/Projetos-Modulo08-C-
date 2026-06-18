#include <iostream>
#include <string>

class Pessoa
{
private:
    std::string nome;
    int idade;

public:
    Pessoa(std::string nome, int idade)
    {
        this->nome = nome;
        this->idade = idade;
    }

    void apresentar()
    {
        std::cout << "\nMeu nome e: " << this->nome << "\nMinha idade e: " << this->idade << std::endl;
    }
};

int main()
{

    Pessoa p1("Edson", 32);
    Pessoa p2("Joana", 25);

    p1.apresentar();
    p2.apresentar();

    return 0;
}