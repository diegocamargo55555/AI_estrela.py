#include <iostream>
#include <cstdlib>
#include "Tebelas.h"
using namespace std;

int main()
{
    int escolha = 1;
    while (escolha <= 3 && escolha > 0)
    {
        
        cout << "Escolha qual Viagem deseja comparar os percursos:\n1. Odysseia \n2. Exodo de Moiseis \n3. Viagem de Abraão\nEscolha: ";
        cin >> escolha;
        system("cls");
        switch (escolha)
        {
        case 1:
            cout << "Escolha: Odysseia.\nDados em tabela, Original:\n";
            Odyssey();
            cout << "\n\nCom GPS:\n";
            OdysseyGPS();
            cout <<"\n\n";
            break;
        case 2:
            cout << "Escolha: Exodo de Moises.\nDados em tabela, Original:\n";
            moises();
            cout << "\n\nCom GPS:\n";
            moisesGPS();
            cout <<"\n\n";
            break;
        case 3:
            cout << "Escolha: Viagem de Abraão.\nDados em tabela, Original:\n";
            abraao();
            cout << "\n\nCom GPS:\n";
            abraaoGPS();
            cout <<"\n\n";
            break;
        default:
            cout << "Resposta invalida, programa sera encerrado.";
            return 0;
            break;
        }
    }
    
}