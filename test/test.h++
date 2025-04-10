#include <iostream>
#include <vector>
struct cidade {
    std::string nome;
    std::vector<std::string> vizinhos;
    std::vector<cidade*> cidades;
    std::vector<int> distancia;
    float reta;

};

cidade calcular_caminho(std::vector<cidade> aberto, int dist_total, int *index){
    int menor = aberto[0].distancia[0] + aberto[0].reta + dist_total;
    cidade aux = aberto[0];
    *index = 0;
    for (int i = 1; i < aberto.size(); i++){
        for (int k = 1; k < aberto[i].distancia.size(); k++)
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
}




int findIndex(std::vector<cidade> v, cidade val) {
    for (int i = 0; i < v.size(); i++) {
      
      	// When the element is found
        if (v[i].nome == val.nome) {
            return i;
        }
    }
  	
  	// When the element is not found
  	return -1;
}