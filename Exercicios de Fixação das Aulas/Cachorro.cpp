#include <iostream>
#include <string>

class Cachorro {
    private:
    std::string nome;
    std::string raca;

    public:
    Cachorro(std::string nome, std::string raca){
        this->nome = nome;
        this->raca = raca;
    }

    void latir(){
        std::cout << "Au, Au!\n" << this->nome << this->raca << std::endl;
    }

};

int main(){
    Cachorro c1("Sirius","Golden Retrivier");
    Cachorro c2("Aruk", "Vira-Lata");

    c1.latir();
    c2.latir();

    return 0;
}