#include <iostream>
#include <vector>
#include "biblioteca.h++"
using namespace std;
int main(){
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

    std::vector<cidade> fechado;
    std::vector<cidade> aberto;
    bool achou = false;
    int dist_total = 0;
    //int f = g+h;



    aberto.push_back(oradea);
    fechado.push_back(aberto[0]);
    aberto.pop_back();

    for (int i = 0; i < aberto.size(); i++)
    {
        cout << "a: " << fechado[0].cidades[i]->nome << endl;
        aberto.push_back(*fechado[0].cidades[i]);
    }
    aberto.push_back(oradea);


    
    while (!aberto.empty() )
    {
        
        for (int i = 0; i < aberto.size(); i++)
        {
            printf("começo abertos: %s\n", aberto[i].nome.c_str());
        }

        printf("\nola\n");
        int* h = heuristica(aberto);
        printf("h = %d\n", *h);

        fechado.push_back(aberto[h[0]]);
        aberto.erase(aberto.begin()+h[0]);

        for (int i = 0; i < aberto.size(); i++)
        {
            printf("fim abertos: %s\n", aberto[i].nome.c_str());
        }

        for (int i = 0; i < fechado.size(); i++)
        {
            printf("fim fechados: %s\n", aberto[i].nome.c_str());
        }
    }  


}