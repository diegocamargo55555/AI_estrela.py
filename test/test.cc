#include <iostream>
#include <vector>
#include <algorithm>
#include "test.h++"
using namespace std;
int main()
{
    cidade oradea, zerind, arad, sibiu, fagaras, rimnieu, craiova, pitesti, timisoara, logoj, mehadia, dobreta, bucharest;
    oradea.nome = "oradea";
    oradea.vizinhos.push_back("zerind");
    oradea.vizinhos.push_back("sibiu");
    oradea.cidades.push_back(&zerind);
    oradea.reta = 380;
    oradea.cidades.push_back(&sibiu);
    oradea.distancia.push_back(71);
    oradea.distancia.push_back(151);

    zerind.nome = "zerind";
    zerind.vizinhos.push_back("arad");
    zerind.cidades.push_back(&arad);
    zerind.distancia.push_back(75);
    zerind.reta = 374;

    arad.nome = "arad";
    arad.vizinhos.push_back("sibiu");
    arad.cidades.push_back(&sibiu);
    arad.distancia.push_back(140);
    arad.vizinhos.push_back("timisoara");
    arad.cidades.push_back(&timisoara);
    arad.distancia.push_back(118);
    arad.reta = 366;

    sibiu.nome = "sibiu";
    sibiu.vizinhos.push_back("fagaras");
    sibiu.cidades.push_back(&fagaras);
    sibiu.distancia.push_back(99);
    sibiu.vizinhos.push_back("rimnieu");
    sibiu.cidades.push_back(&rimnieu);
    sibiu.distancia.push_back(80);
    sibiu.reta = 353;

    fagaras.nome = "fagaras";
    fagaras.vizinhos.push_back("bucharest");
    fagaras.cidades.push_back(&bucharest);
    fagaras.reta = 178;

    rimnieu.nome = "rimnieu";
    rimnieu.vizinhos.push_back("craiova");
    rimnieu.cidades.push_back(&craiova);
    rimnieu.distancia.push_back(146);
    rimnieu.vizinhos.push_back("pitesti");
    rimnieu.cidades.push_back(&pitesti);
    rimnieu.distancia.push_back(97);
    rimnieu.reta = 193;

    pitesti.nome = "pitesti";
    pitesti.vizinhos.push_back("craiova");
    pitesti.cidades.push_back(&craiova);
    pitesti.distancia.push_back(138);
    pitesti.vizinhos.push_back("bucharest");
    pitesti.cidades.push_back(&bucharest);
    pitesti.distancia.push_back(101);
    pitesti.reta = 98;    

    timisoara.nome = "timisoara";
    timisoara.vizinhos.push_back("logoj");
    timisoara.cidades.push_back(&logoj);
    timisoara.distancia.push_back(111);
    timisoara.reta = 329;

    bucharest.nome = "bucharest";
    bucharest.vizinhos.push_back("none");
    bucharest.cidades.push_back(nullptr);
    bucharest.distancia.push_back(0);
    bucharest.reta = 0;

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

    int passo = 0;
    string meta = "bucharest";
    while (!aberto.empty() && !achou)
    {

        printf("\n---------------\nCidade atual:%s \ninicio abertos:", fechado[passo].nome.c_str());

        for (int i = 0; i < aberto.size(); i++)
        {
            printf("%s, ", aberto[i].nome.c_str());
        }
        printf("\npasso:%d", passo);

        int index;
        cidade prox_cidade = calcular_caminho(aberto, dist_total, &index);
        int indice = findIndex(aberto, prox_cidade);


        printf("\ndestino escolida: %s\n", prox_cidade.nome.c_str());
        fechado.push_back(aberto[indice]);

        printf("distancia: %d\n", fechado[passo].distancia[index]);
        aberto.erase(aberto.begin() + indice);
        passo++;

        printf("adicionara:");
        for (int i = 0; i < fechado[passo].cidades.size(); i++)
        {
            printf("%s, ", fechado[passo].cidades[i]->nome.c_str());

            aberto.push_back(*fechado[passo].cidades[i]);
        }
        printf("\nfim abertos:");
        for (int i = 0; i < aberto.size(); i++)
        {
            printf(" %s,", aberto[i].nome.c_str());
        }

        printf("\nfim fechados:");
        for (int i = 0; i < fechado.size(); i++)
        {
            printf(" %s,", fechado[i].nome.c_str());
        }

        if (prox_cidade.nome.c_str() == meta)
        {
            achou = true;
            printf("\nCidade escolida encontrada distancia total:%d\n", dist_total);
        }

    }
}