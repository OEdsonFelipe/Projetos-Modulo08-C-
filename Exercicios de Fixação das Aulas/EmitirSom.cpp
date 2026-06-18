#include <iostream>
#include <string>

class Animal {
    private:
    std::string especie;
    std::string som;

    public:
    Animal(std::string especie, std::string som){
        this->som = som;
        this->especie = especie;
    }

    void emitir_som(){
        std::cout << "\nO(a) " << especie << " faz: "<< som << std::endl;
    }

};

int main(){
    Animal meumnimal1("Gato", "Miau!");
    Animal meuanimal2("Cachorro","Au,Au!");

    meumnimal1.emitir_som();
    meuanimal2.emitir_som();

}