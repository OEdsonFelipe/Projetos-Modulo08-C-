/*Bolão da Copa 2026 - Jogos do Brasil!*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Score
{
    int brasil;
    int opponent;
};

struct User
{
    string name;
    vector<Score> predictions;
    int points = 0;
};

Score readScore(const string &prompt)
{
    Score result{0, 0};
    string line;
    while (true)
    {
        cout << prompt;
        getline(cin, line);
        replace(line.begin(), line.end(), 'x', ' ');
        replace(line.begin(), line.end(), 'X', ' ');
        replace(line.begin(), line.end(), '-', ' ');

        istringstream input(line);
        if (input >> result.brasil >> result.opponent)
        {
            return result;
        }
        cout << "Formato inválido. Digite no formato golsBrasil x golsAdversario (por exemplo, 2x1).\n";
    }
}

int outcome(const Score &score)
{
    if (score.brasil > score.opponent)
        return 1;
    if (score.brasil < score.opponent)
        return -1;
    return 0;
}

int calculatePoints(const Score &prediction, const Score &actual)
{
    if (prediction.brasil == actual.brasil && prediction.opponent == actual.opponent)
    {
        return 10;
    }
    if (outcome(prediction) == outcome(actual))
    {
        return 5;
    }
    return 0;
}

int main()
{
    vector<string> matches = {
        "Brasil x Marrocos",
        "Brasil x Haiti",
        "Brasil x Escocia",
    };

    int numUsers;
    cout << "Quantos participantes vão dar palpites? ";
    while (!(cin >> numUsers) || numUsers <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Por favor, informe um número inteiro positivo de participantes: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<User> users;
    users.reserve(numUsers);

    for (int i = 0; i < numUsers; i++)
    {
        User user;
        cout << "\nNome do participante " << i + 1 << ": ";
        getline(cin, user.name);
        if (user.name.empty())
        {
            user.name = "Participante " + to_string(i + 1);
        }

        for (int j = 0; j < static_cast<int>(matches.size()); j++)
        {
            string prompt = "Digite o palpite do placar para " + matches[j];
            user.predictions.push_back(readScore(prompt));
        }

        users.push_back(move(user));
    }

    cout << "\nAgora digite os resultados reais dos jogos do Brasil:\n";
    vector<Score> actualResults;
    actualResults.reserve(matches.size());
    for (const auto &match : matches)
    {
        string prompt = "Resultado real de " + match + " (formato 2x1): ";
        actualResults.push_back(readScore(prompt));
    }

    for (auto &user : users)
    {
        int total = 0;
        for (size_t i = 0; i < matches.size(); i++)
        {
            total += calculatePoints(user.predictions[i], actualResults[i]);
        }
        user.points = total;
    }

    sort(users.begin(), users.end(), [](const User &a, const User &b)
         { return a.points > b.points; });

    cout << "\nRanking final de pontos:\n";
    for (size_t i = 0; i < users.size(); i++)
    {
        cout << i + 1 << ". " << users[i].name << " - " << users[i].points << " pontos\n";
    }

    cout << "\nDetalhes por participante:\n";
    for (const auto &user : users)
    {
        cout << "\n"
             << user.name << ": " << user.points << " pontos\n";
        for (size_t i = 0; i < matches.size(); i++)
        {
            cout << "  " << matches[i] << " | Palpite: " << user.predictions[i].brasil << "x" << user.predictions[i].opponent
                 << " | Real: " << actualResults[i].brasil << "x" << actualResults[i].opponent << "\n";
        }
    }

    return 0;
}