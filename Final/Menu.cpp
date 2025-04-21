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
            cout <<
            "\n\n|----------------------------------------------------------------|\n"
            "                    1 - Troia                                   \n"
            "                        |                                       \n"
            "                        2 - Ismarus                             \n"
            "                        \\                                      \n"
            "                         \\                                     \n"
            "                          \\ ___                                \n"
            "                  3 Lotus-Eaters\\                              \n"
            "                                 \\                             \n"
            "                         4 Cyclops\\                            \n"
            "                                   \\                           \n"
            "                              5 Aeolia\\                        \n"
            "                                     6 Lestrigoes               \n"
            "                                         /                      \n"
            "                         Submundo 8     /                       \n"
            "                            /   \\   __/                        \n"
            "                       7 Circe ___\\/                           \n"
            "                          \\       \\                           \n"
            "                           \\       9 Sereias                   \n"
            "                             |      /                           \n"      
            "                        10 Cila _/                              \n"
            "                                  \\_____11 Calipso             \n"      
            "                                         /                      \n"
            "                                        /                       \n"
            "                                12 Caribdis                     \n"
            "                                     |                          \n"
            "                                 13 Itaca                       \n"
            "|----------------------------------------------------------------|\n";
            break;
        case 2:
            cout << "Escolha: Exodo de Moises.\nDados em tabela, Original:\n";
            moises();
            cout << "\n\nCom GPS:\n";
            cidadesUsadas = moisesGPS();
            cout <<"\n\n";
            cout << "Utilizacao A*";
            execucaoEstrela(cidadesUsadas, "Cisjordania");
            cout <<
            "\n\n|------------------------------------|\n"
            "                                    \n"
            "                              9     \n"
            " 1                           /      \n"
            " \\              ___        /       \n"
            "  2\\_          /  /       /        \n"
            "     \\        /_6/_      /8        \n"
            "      \\3        | \\    /          \n"
            "       \\_4      |  \\  /           \n"
            "         \\__    |   \\/            \n"
            "            \\  /      7            \n"
            "             \\/                    \n"
            "              5                     \n"
            "|------------------------------------|\n"
            "1 - Tanis\n"
            "2 - Sucote\n"
            "3 - Mara\n"
            "4 - Monte Hor\n"
            "5 - Horebe\n"
            "6 - Cades-Barneia\n"   
            "7 - Ezioom-Geber\n"
            "8 - Punom\n"
            "9 - Jerico\n"
            "---------------------------------------\n\n";
            break;
        case 3:
            cout << "Escolha: Viagem de Abraão.\nDados em tabela, Original:\n";
            abraao();
            cout << "\n\nCom GPS:\n";
            cidadesUsadas = abraaoGPS();
            cout <<"\n\n";
            cout << "Utilizacao A*";
            execucaoEstrela(cidadesUsadas, "Bersaba");
            cout <<
            "\n\n|------------------------------------|\n"
            "                                    \n"
            "              5 ____ 4              \n"
            "              /     |               \n"
            "             /       \\3            \n"
            "            /         \\_           \n"
            "         6_/            \\_         \n"
            "  7     /                  \\_2     \n"
            "  |\\__/ _                   \\_1   \n"
            "  \\____/9                          \n"
            "                                    \n"
            "|------------------------------------|\n"
            "1 - Ur\n"
            "2 - Babilonia\n"
            "3 - Mari\n"
            "4 - Hara\n"
            "5 - Alepo\n"
            "6 - Damasco\n"
            "7 - Siquem\n"
            "8 - Zoa\n"
            "9 - Bersaba\n"
            "---------------------------------------\n\n";
            break;
        default:
            cout << "Resposta invalida, programa sera encerrado.";
            return 0;
            break;
        }
    }
    
}