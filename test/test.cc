#include <iostream>
#include <vector>
#include "test.h++"
using namespace std;
int main()
{
    cidade oradea, zerind, arad, sibiu;
    oradea.nome = "oradea";
    oradea.vizinhos.push_back("zerind");
    oradea.vizinhos.push_back("sibiu");
    oradea.cidades.push_back(&zerind);
    oradea.cidades.push_back(&sibiu);
    oradea.distancia.push_back(75);
    oradea.distancia.push_back(151);

    zerind.nome = "zerind";
    zerind.vizinhos.push_back("arad");
    zerind.cidades.push_back(&arad);
    zerind.distancia.push_back(75);

    arad.nome = "arad";
    arad.vizinhos.push_back("sibiu");
    arad.cidades.push_back(&sibiu);
    arad.distancia.push_back(140);

    sibiu.nome = "sibiu";

    vector<cidade> fechado;
    vector<cidade> aberto;
    bool achou = false;

    int dist_total = 0;

    // int f = g+h;
    aberto.push_back(oradea);
    fechado.push_back(aberto[0]);
    aberto.pop_back();

    for (int i = 0; i < fechado[0].cidades.size(); i++)
    {
        aberto.push_back(*fechado[0].cidades[i]);
    }

    while (!aberto.empty())
    {
        cout << "\n---------------";

        cout << endl <<"inicio abertos:";

        for (int i = 0; i < aberto.size(); i++)
        {
            printf(" %s,", aberto[i].nome.c_str());
        }

        int *h = heuristica(aberto);

        printf("h = %d\n", h[0]);
        printf("cidade escolida: %s\n", aberto[h[0]].nome.c_str());
        printf("distancia: %d\n", aberto[h[0]].distancia[h[2]]);

        fechado.push_back(aberto[h[0]]);
        aberto.erase(aberto.begin() + h[0]);

        printf("fim abertos:");
        for (int i = 0; i < aberto.size(); i++)
        {
            printf(" %s,", aberto[i].nome.c_str());
        }

        printf("\nfim fechados:");
        for (int i = 0; i < fechado.size(); i++)
        {
            printf(" %s,", fechado[i].nome.c_str());
        }
    }
}