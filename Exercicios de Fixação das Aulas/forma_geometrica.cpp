#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

// Classe abstrata (interface)
class Forma {
public:
    // Métodos virtuais puros -> tornam a classe abstrata
    virtual double calcular_area() const = 0;
    virtual double calcular_perimetro() const = 0;
    virtual void exibir() const = 0;
    
    // Destrutor virtual (importante para polimorfismo)
    virtual ~Forma() = default;
};

// Classe concreta: Círculo
class Circulo : public Forma {
private:
    double raio;
    
public:
    Circulo(double r) : raio(r) {}
    
    double calcular_area() const override {
        return M_PI * raio * raio;
    }
    
    double calcular_perimetro() const override {
        return 2 * M_PI * raio;
    }
    
    void exibir() const override {
        cout << "Círculo (raio=" << raio << ")" << endl;
        cout << "  Área: " << calcular_area() << endl;
        cout << "  Perímetro: " << calcular_perimetro() << endl;
    }
};

// Classe concreta: Retângulo
class Retangulo : public Forma {
private:
    double largura;
    double altura;
    
public:
    Retangulo(double l, double a) : largura(l), altura(a) {}
    
    double calcular_area() const override {
        return largura * altura;
    }
    
    double calcular_perimetro() const override {
        return 2 * (largura + altura);
    }
    
    void exibir() const override {
        cout << "Retângulo (largura=" << largura << ", altura=" << altura << ")" << endl;
        cout << "  Área: " << calcular_area() << endl;
        cout << "  Perímetro: " << calcular_perimetro() << endl;
    }
};

// Classe concreta: Triângulo
class Triangulo : public Forma {
private:
    double lado1, lado2, lado3;
    
public:
    Triangulo(double l1, double l2, double l3) : lado1(l1), lado2(l2), lado3(l3) {}
    
    double calcular_area() const override {
        // Fórmula de Herão
        double s = (lado1 + lado2 + lado3) / 2;
        return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }
    
    double calcular_perimetro() const override {
        return lado1 + lado2 + lado3;
    }
    
    void exibir() const override {
        cout << "Triângulo (lados=" << lado1 << ", " << lado2 << ", " << lado3 << ")" << endl;
        cout << "  Área: " << calcular_area() << endl;
        cout << "  Perímetro: " << calcular_perimetro() << endl;
    }
};

int main() {
    cout << "=== Exemplo de Classes Abstratas - Formas ===" << endl << endl;
    
    // Criando formas usando ponteiros para a classe base
    vector<unique_ptr<Forma>> formas;
    
    formas.push_back(make_unique<Circulo>(5.0));
    formas.push_back(make_unique<Retangulo>(4.0, 6.0));
    formas.push_back(make_unique<Triangulo>(3.0, 4.0, 5.0));
    
    // Polimorfismo: cada forma se comporta de acordo com sua implementação
    for (const auto& forma : formas) {
        forma->exibir();
        cout << endl;
    }
    
    return 0;
}