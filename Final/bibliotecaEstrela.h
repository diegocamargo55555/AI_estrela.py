#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;
struct cidade
{
    std::string nome;
    std::vector<std::string> vizinhos;
    std::vector<cidade *> cidades;
    std::vector<int> distancia;
    float reta;
};

/*cidade calcular_caminho(std::vector<cidade> aberto, int dist_total, int *index){
    int menor = INT_MAX;
    cidade aux = aberto[0];
    *index = 0;
    for (int i = 0; i < aberto.size(); i++){
        for (int k = 0; k < aberto[i].distancia.size(); k++)
        {
            if (menor >dist_total + aberto[i].distancia[k] + aberto[i].reta)
            {
                menor = dist_total + aberto[i].distancia[k] + aberto[i].reta;
                aux = aberto[i];
                *index = k;
            }
        }
    }
    return aux;
}*/

cidade calcular_caminho(cidade atual, int dist_total, int *index)
{
    int menor = INT_MAX;
    cidade aux = *atual.cidades[0];
    *index = 0;
    for (int i = 0; i < atual.cidades.size(); i++)
    {
        
        if (menor > dist_total + atual.cidades[i]->distancia[i] + atual.cidades[i]->reta)
        {
            menor = dist_total + atual.cidades[i]->distancia[i] + atual.cidades[i]->reta;
            aux = *atual.cidades[i];
            *index = i;
        }
    }
    return aux;
}

int findIndex(std::vector<cidade> v, cidade val)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].nome == val.nome)
        {
            return i;
        }
    }
    return -1;
}