/* Bolão da Copa 2026 - Sistema com Classes, Vetores Estáticos e Dinâmicos! */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Classe para armazenar os placares
class Jogo {
public:
    int golsMandante;
    int golsVisitante;

    Jogo() : golsMandante(-1), golsVisitante(-1) {}

    // Retorna 1 (Mandante), -1 (Visitante) ou 0 (Empate)
    int vencedor() const {
        if (golsMandante > golsVisitante) return 1;
        if (golsMandante < golsVisitante) return -1;
        return 0;
    }
};

// Classe para representar o Apostador
class Apostador {
public:
    string nome;
    int pontuacao;
    Jogo* palpites; // Vetor dinâmico para os palpites

    Apostador() {
        nome = "";
        pontuacao = 0;
        // Alocação dinâmica exigida pelas regras
        palpites = new Jogo[4]; 
    }

    ~Apostador() {
        // Destruição correta da memória alocada
        delete[] palpites; 
    }
};

// Função auxiliar baseada na sua lógica para ler no formato "2x1"
Jogo lerPlacar(const string& prompt) {
    Jogo resultado;
    string linha;
    while (true) {
        cout << prompt;
        getline(cin, linha);
        replace(linha.begin(), linha.end(), 'x', ' ');
        replace(linha.begin(), linha.end(), 'X', ' ');
        replace(linha.begin(), linha.end(), '-', ' ');

        istringstream input(linha);
        if (input >> resultado.golsMandante >> resultado.golsVisitante) {
            return resultado;
        }
        cout << "Formato invalido. Digite no formato golsMandante x golsVisitante (por exemplo, 2x1).\n";
    }
}

// Função para exibir o menu
void exibirMenu() {
    cout << "\n======================================" << endl;
    cout << "        BOLAO DA COPA 2026            " << endl;
    cout << "======================================" << endl;
    cout << "1. Cadastrar resultados reais dos jogos" << endl;
    cout << "2. Cadastrar palpites dos apostadores" << endl;
    cout << "3. Calcular pontuacao" << endl;
    cout << "4. Exibir ranking final" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    const int NUM_JOGOS = 4;
    const int NUM_APOSTADORES = 3;

    string nomesJogos[NUM_JOGOS] = {
        "Brasil x Marrocos",
        "Brasil x Haiti",
        "Brasil x Escocia",
        "Brasil x Espanha" // Adicionado para fechar os 4 jogos exigidos
    };

    // Vetor ESTÁTICO para os jogos reais e para os apostadores
    Jogo jogosReais[NUM_JOGOS]; 
    Apostador apostadores[NUM_APOSTADORES]; 

    bool jogosCadastrados = false;
    bool palpitesCadastrados = false;
    bool pontuacaoCalculada = false;
    int opcao;

    do {
        exibirMenu();
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = -1;
        }
        cin.ignore(10000, '\n'); // Limpa o buffer para o getline funcionar depois

        switch (opcao) {
            case 1: {
                cout << "\n--- RESULTADOS REAIS ---" << endl;
                for (int i = 0; i < NUM_JOGOS; i++) {
                    string prompt = "Resultado real de " + nomesJogos[i] + " (formato 2x1): ";
                    jogosReais[i] = lerPlacar(prompt);
                }
                jogosCadastrados = true;
                cout << "Resultados reais cadastrados com sucesso!\n";
                break;
            }
            case 2: {
                cout << "\n--- PALPITES DOS APOSTADORES ---" << endl;
                for (int i = 0; i < NUM_APOSTADORES; i++) {
                    cout << "\nNome do Apostador " << i + 1 << ": ";
                    getline(cin, apostadores[i].nome);
                    if (apostadores[i].nome.empty()) {
                        apostadores[i].nome = "Apostador " + to_string(i + 1);
                    }

                    for (int j = 0; j < NUM_JOGOS; j++) {
                        string prompt = "Palpite para " + nomesJogos[j] + " (formato 2x1): ";
                        apostadores[i].palpites[j] = lerPlacar(prompt);
                    }
                }
                palpitesCadastrados = true;
                cout << "Palpites cadastrados com sucesso!\n";
                break;
            }
            case 3: {
                if (!jogosCadastrados || !palpitesCadastrados) {
                    cout << "\n[!] ERRO: Cadastre os jogos reais e os palpites primeiro.\n";
                    break;
                }
                
                for (int i = 0; i < NUM_APOSTADORES; i++) {
                    apostadores[i].pontuacao = 0; 
                    
                    for (int j = 0; j < NUM_JOGOS; j++) {
                        int gM_Real = jogosReais[j].golsMandante;
                        int gV_Real = jogosReais[j].golsVisitante;
                        int gM_Palp = apostadores[i].palpites[j].golsMandante;
                        int gV_Palp = apostadores[i].palpites[j].golsVisitante;

                        if (gM_Real == gM_Palp && gV_Real == gV_Palp) {
                            apostadores[i].pontuacao += 10; // Placar exato
                        } 
                        else if (jogosReais[j].vencedor() == apostadores[i].palpites[j].vencedor()) {
                            apostadores[i].pontuacao += 5; // Acertou vencedor/empate
                        }
                    }
                }
                pontuacaoCalculada = true;
                cout << "\nPontuacoes calculadas com sucesso!\n";
                break;
            }
            case 4: {
                if (!pontuacaoCalculada) {
                    cout << "\n[!] ERRO: Calcule a pontuacao (Opcao 3) antes de exibir o ranking.\n";
                    break;
                }

                // Array de ponteiros para ordenar sem mover os objetos brutos na memória
                Apostador* ranking[NUM_APOSTADORES];
                for (int i = 0; i < NUM_APOSTADORES; i++) {
                    ranking[i] = &apostadores[i];
                }

                // Bubble Sort manual via ponteiros (ordem decrescente)
                for (int i = 0; i < NUM_APOSTADORES - 1; i++) {
                    for (int j = 0; j < NUM_APOSTADORES - i - 1; j++) {
                        if (ranking[j]->pontuacao < ranking[j + 1]->pontuacao) {
                            swap(ranking[j], ranking[j + 1]);
                        }
                    }
                }

                cout << "\n--- RANKING FINAL ---" << endl;
                for (int i = 0; i < NUM_APOSTADORES; i++) {
                    cout << i + 1 << "o Lugar: " << ranking[i]->nome 
                         << " | " << ranking[i]->pontuacao << " pontos\n";
                }

                cout << "\n--- DETALHES POR PARTICIPANTE ---" << endl;
                for (int i = 0; i < NUM_APOSTADORES; i++) {
                    cout << "\n" << apostadores[i].nome << ": " << apostadores[i].pontuacao << " pontos\n";
                    for (int j = 0; j < NUM_JOGOS; j++) {
                        cout << "  " << nomesJogos[j] 
                             << " | Palpite: " << apostadores[i].palpites[j].golsMandante << "x" << apostadores[i].palpites[j].golsVisitante
                             << " | Real: " << jogosReais[j].golsMandante << "x" << jogosReais[j].golsVisitante << "\n";
                    }
                }
                break;
            }
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}