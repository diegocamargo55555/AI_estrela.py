#include <iostream>
#include <vector>
#include <cstdlib>
#include "aEstrela.h"
using namespace std;

int main(){
    //mudancas feitas: aqui: utilizacao do vetor cidadesUsadas pra receber as cidades feitas na tabela.
    vector<cidade> cidadesUsadas;
    int escolha = 1;
    while (escolha <= 3 && escolha > 0)
    {
        cout << "Escolha qual Viagem deseja comparar os percursos:\n1. Odysseia \n2. Exodo de Moiseis \n3. Viagem de Abraao\nEscolha: ";
        cin >> escolha;
        system("cls");
        switch (escolha){
        case 1:
            cout << "Escolha: Odysseia.\nDados em tabela, Original:\n";
            Odyssey();
            cout << "\n\nCom GPS:\n";
            cidadesUsadas = OdysseyGPS();
            cout <<"\n\n";
            cout << "Utilizacao A*: ";
            execucaoEstrela(cidadesUsadas, "Itaca");
            break;
        case 2:
            cout << "Escolha: Exodo de Moises.\nDados em tabela, Original:\n";
            moises();
            cout << "\n\nCom GPS:\n";
            cidadesUsadas = moisesGPS();
            cout <<"\n\n";
            cout << "Utilizacao A*";
            execucaoEstrela(cidadesUsadas, "Cisjordania");
            break;
        case 3:
            cout << "Escolha: Viagem de Abraão.\nDados em tabela, Original:\n";
            abraao();
            cout << "\n\nCom GPS:\n";
            cidadesUsadas = abraaoGPS();
            cout <<"\n\n";
            cout << "Utilizacao A*";
            execucaoEstrela(cidadesUsadas, "Bersaba");
            break;
        default:
            cout << "Resposta invalida, programa sera encerrado.";
            return 0;
            break;
        }
    }
    
}