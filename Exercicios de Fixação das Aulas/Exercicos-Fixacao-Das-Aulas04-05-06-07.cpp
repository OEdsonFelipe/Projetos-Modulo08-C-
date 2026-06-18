#include <iostream>
#include <string>
#include <stdexcept> // Biblioteca necessária para as exceções padrão

using namespace std;

int main() {
    const string USUARIO_CORRETO = "admin";
    const string SENHA_CORRETA = "12345";
    
    int tentativasRestantes = 3;
    bool acessoLiberado = false;

    cout << "================================\n";
    cout << "    SISTEMA DE LOGIN SEGURO     \n";
    cout << "================================\n\n";

    // LAÇO: Repete enquanto houver tentativas e o acesso não for liberado
    while (tentativasRestantes > 0 && !acessoLiberado) {
        string usuarioDigitado, senhaDigitada;

        cout << "Usuario: ";
        cin >> usuarioDigitado;
        cout << "Senha: ";
        cin >> senhaDigitada;

        try {
            // CONDICIONAL: Verifica se as credenciais estão erradas
            if (usuarioDigitado != USUARIO_CORRETO || senhaDigitada != SENHA_CORRETA) {
                // EXCEÇÃO: Dispara um erro de argumento inválido caso a senha ou usuário não batam
                throw invalid_argument("Usuario ou senha incorretos.");
            }

            // Se o código chegar nesta linha (ou seja, não disparou a exceção acima), o login está correto
            acessoLiberado = true;
            cout << "\n[+] Sucesso! Bem-vindo ao sistema, " << usuarioDigitado << ".\n";

        } 
        catch (const invalid_argument& erro) {
            // Captura a exceção de credencial errada
            tentativasRestantes--;
            cout << "\n[!] EXCECAO CAPTURADA: " << erro.what() << "\n";
            
            // CONDICIONAL aninhada: Verifica se ainda tem tentativas ou se bloqueia de vez
            if (tentativasRestantes > 0) {
                cout << "-> Voce tem mais " << tentativasRestantes << " tentativa(s).\n\n";
            } else {
                try {
                    // EXCEÇÃO: Dispara um erro crítico de execução quando acabam as tentativas
                    throw runtime_error("Tentativas esgotadas. SISTEMA BLOQUEADO!");
                } 
                catch (const runtime_error& bloqueio) {
                    // Captura e exibe o bloqueio final
                    cout << "\n[XXX] ERRO CRITICO: " << bloqueio.what() << "\n";
                }
            }
        }
    }

    return 0;
}