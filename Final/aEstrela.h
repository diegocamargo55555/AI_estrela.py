#include <iostream>
#include <vector>
#include <algorithm>
#include "Tabelas.h"
using namespace std;

void execucaoEstrela(vector<cidade> vetorCidades, string meta)
{
    vector<cidade> fechado;
    vector<cidade> aberto;
    bool achou = false;
    int dist_total = 0;

    aberto.push_back(vetorCidades[0]);
    fechado.push_back(aberto[0]);
    aberto.pop_back();

    for (int i = 0; i < fechado[0].cidades.size(); i++){
        aberto.push_back(*fechado[0].cidades[i]);
    }

    int passo = 0;
    while (!aberto.empty() && !achou){
        printf("\n---------------\nCidade atual:%s\nInicio abertos:", fechado[passo].nome.c_str());
       // printf("aberto.size: %d\n", aberto.size());
        for (int i = 0; i < aberto.size(); i++)
        {
            printf("%s, ", aberto[i].nome.c_str());
        }

        printf("\nPasso:%d", passo);
        
        int index;
        cidade prox_cidade = calcular_caminho(fechado[passo], dist_total, &index);
        int indice = findIndex(aberto, prox_cidade);
        
        printf("\nDestino escolhido: %s\n", prox_cidade.nome.c_str());
        printf("Distancia: %d\n", fechado[passo].distancia[index]);

        //Aqui, ele checa se a cidade ja esta no vetor fechado, se nao estiver ele coloca, se tiver ele nao coloca, pra n ter repeticao
        if(findIndex(fechado, aberto[indice]) == -1){
            fechado.push_back(aberto[indice]);
            passo++;
        }
        
        // mudei pro valor da distancia total ser somado aqui
        dist_total += fechado[passo].distancia[index];
        aberto.erase(aberto.begin() + indice);

        printf("Adicionara:");
        for (int i = 0; i < fechado[passo].cidades.size(); i++)
        {
            // ele ve se a cidade ja esta no abertos, e se nao estiver ele coloca, se estiver ele nao coloca, pra n ter cidade repetida
            if(findIndex(aberto, *fechado[passo].cidades[i]) == -1 && findIndex(fechado, *fechado[passo].cidades[i]) == -1){
                printf("%s, ", fechado[passo].cidades[i]->nome.c_str());
                aberto.push_back(*fechado[passo].cidades[i]);
            }
        }

        printf("\nFim abertos:");
        for (int i = 0; i < aberto.size(); i++)
        {
            printf(" %s,", aberto[i].nome.c_str());
        }
        printf("\nFim fechados:");
        for (int i = 0; i < fechado.size(); i++)
        {
            printf(" %s,", fechado[i].nome.c_str());
        }
        if (prox_cidade.nome.c_str() == meta)
        {
            achou = true;
            printf("\nCidade escolhida encontrada distancia total:%d\n", dist_total);
        }
    }
}