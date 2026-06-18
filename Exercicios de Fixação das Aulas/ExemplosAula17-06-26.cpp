#include<iostream>


using namespace std;

// //Classe base (pai)
// class Animal {
//     protected:
//     string nome;

//     public:
//     Animal(string n) : nome(n) {}

//     void falar(){
//         cout << "O Animal faz um som." << endl;
//     }

// };

// class Cachorro : public Animal {
//     public:
//     Cachorro(string n) : Animal(n) {}
//     //Não precisa redefinir falar() - herda de classe pai
// };

// int main(){
//     Cachorro rex("Rex");
//     rex.falar();
//     return 0;
// }

class Pessoa{
    protected:
        string nome;
    public:
        Pessoa(string n) : nome(n){}

    virtual void falar(){
        cout << nome << " está falando." << endl;
    }

    

};

class Professor : public Pessoa{
    private: 
        string disciplina;

    public: 
        Professor(string n, string d) : Pessoa(n), disciplina(d) {}

        void falar() override {
            cout << "Professor(a) " << nome << " está ensinando " << disciplina << "." << endl;
        }
};

class Aluno : public Pessoa{
    private: 
        int matricula;

    public:
        Aluno(string n, int m) : Pessoa(n), matricula(m) {}

    void falar() override {
        cout << "Aluno(a) " << nome << "{matricula: " << matricula << "} está  aprendendo." << endl;
    }    

    void exibir() {
        cout << "Nome: " << nome << ", Matricula: " << matricula << endl;
    }

};


    void fazerFalar (Pessoa* p){
        p->falar();
    }

int main(){
    Pessoa* p1 = new Pessoa("João");
    Pessoa* p2 = new Professor("Ricardo","Fisica");
    Pessoa* p3 = new Aluno("Marina", 202);

   fazerFalar(p1);
   fazerFalar(p2);
   fazerFalar(p3);

   delete p1;
   delete p2;
   delete p3;

    return 0;
}