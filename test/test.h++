#include <iostream>
#include <vector>
struct cidade {
    std::string nome;
    std::vector<std::string> vizinhos;
    std::vector<cidade*> cidades;
    std::vector<int> distancia;
};
int* heuristica(std::vector<cidade> aberto){
    int* h = new int[2];

    int menor = aberto[0].distancia[0];
    printf("\nola\n");

    for (int i = 0; i < aberto.size(); i++)
    {
        for (int k = 0; k < aberto[i].distancia.size(); k++)
        {
            if (menor > aberto[i].distancia[k])
            {
                menor = aberto[i].distancia[k];
                h[0] = i;
                h[1] = k;
            }
        }       
    }

    return h;
    
}