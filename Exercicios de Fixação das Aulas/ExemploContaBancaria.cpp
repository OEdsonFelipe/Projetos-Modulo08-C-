#include <iostream>
#include <string>

class ContaBancaria
{
private:
    std::string titular;
    float saldo;

public:
    ContaBancaria(std::string titular, float saldo)
    {
        this->titular = titular;
        this->saldo = saldo;
    }

    void depositar(float valor)
    {

        this->saldo += valor;
        std::cout << "Deposito de R$ " << valor << " realizado com sucesso!" << std::endl;
    }

    void saque (float valor){
        this-> saldo -= valor;
        std::cout << "Um saque de: R$ " << valor << " foi realizado na sua conta!" << std::endl;
    }

    void exibirsaldo()
    {
        std::cout << "Titular: " << titular << "\nSeu saldo atual e: R$  " << saldo << std::endl;
    }
};

int main()
{

    ContaBancaria minhaconta1("Edson", 10500.00);
    minhaconta1.exibirsaldo();

    minhaconta1.depositar(1500);
    minhaconta1.exibirsaldo();
    minhaconta1.saque(500);
    minhaconta1.exibirsaldo();

    return 0;
}