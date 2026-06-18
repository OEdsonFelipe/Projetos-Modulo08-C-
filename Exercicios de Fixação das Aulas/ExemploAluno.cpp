#include<iostream>
#include<string>

class Aluno{
    private:
    std::string nome;
    float nota1, nota2;

    public:
    Aluno(std::string nome, float nota1, float nota2){
        this -> nome = nome;
        this -> nota1 = nota1;
        this -> nota2 = nota2;
    }

    float media(){
        return (nota1+nota2)/2;
     }

    std::string situacao(){
        if (this->media() >= 7.0){
            return "Aprovado";
        }else{
            return "Reprovado";
        }
       }


    void exibirDados() {
        std::cout << "\nAluno: " << nome << std::endl;
        std::cout << "\nMedia: " << media() << std::endl;
        std::cout << "\nSituacao: " << situacao() << std::endl;
    }
};

int main(){
    Aluno aluno1 ("Edson", 7.8, 8.9);
    Aluno aluno2 ("Felipe",9.0,8.5);

    aluno1.exibirDados();
    aluno2.exibirDados();

    return 0;
}