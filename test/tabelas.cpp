#include <iomanip>
#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct cidade {
    string nome;
    vector<string> vizinhos;
    vector<cidade*> cidades;
    vector<int> distancia;
};
void tabelas(vector<string> *nomesCidades, cidade*aux){
    if(aux != NULL){
        for(int j = 0; j < aux->vizinhos.size(); j++){
          if(find((*nomesCidades).begin(), (*nomesCidades).end(), aux->vizinhos[j]) == (*nomesCidades).end()){
                (*nomesCidades).push_back(aux->vizinhos[j]); 
            }
        }
        for(int i = 0; i < aux->vizinhos.size(); i++){
            tabelas(nomesCidades, aux->cidades[i]);
        } 
    } 
}

float verDistancia(cidade v, string val){
    for(int i = 0; i < v.vizinhos.size(); i++){
        if(v.vizinhos[i] == val){
            return (v.distancia[i]);
        }
    }
    return -1;
}
int main() {
    vector<string> nomesCidades;
    vector<cidade> cidades;
    cidade oradea, zerind, arad, sibiu;
    oradea.nome = "oradea";
    oradea.vizinhos.push_back("zerind");
    oradea.vizinhos.push_back("sibiu");
    oradea.cidades.push_back(&zerind);
    oradea.cidades.push_back(&sibiu);
    oradea.distancia.push_back(75);
    oradea.distancia.push_back(151);
    cidades.push_back(oradea);

    zerind.nome = "zerind";
    zerind.vizinhos.push_back("arad");
    zerind.cidades.push_back(&arad);
    zerind.distancia.push_back(75);
    cidades.push_back(zerind);
    arad.nome = "arad";
    arad.vizinhos.push_back("sibiu");
    arad.cidades.push_back(&sibiu);
    arad.distancia.push_back(140);
    cidades.push_back(arad);
    sibiu.nome = "sibiu";
    cidades.push_back(sibiu);
    cidade* aux = &oradea;
    int i = 1;
    nomesCidades.push_back(" ");
    nomesCidades.push_back(aux->nome);
    tabelas(&nomesCidades, aux);
    int numCidades = static_cast<int>(nomesCidades.size());
    vector<vector<string>> tabela(numCidades+1, vector<string>(numCidades));
    tabela[0] = nomesCidades;
    for(int i = 0; i < numCidades; i++){
        cout << i << endl;
        tabela[i][0] = nomesCidades[i];
    }
    for(int i = 1; i < numCidades; i++){
        for(int j = 1; j < numCidades; j++){
            if(tabela[i][0] == tabela[0][j]){
                tabela[i][j] = 'x';
            } else{
                float dist = verDistancia(cidades[i-1], tabela[0][j]);
                if(dist != -1){
                    tabela[i][j] = to_string(dist);
                } else{
                    tabela[i][j] = "N/A";
                }
            }
        }
    }
    int setTam = 10;
    for(int i = 0; i < numCidades; i++){
        for(int j = 0; j < numCidades; j++){
            cout << tabela[i][j] << setw(setTam) << " ";
        }
        setTam = 5;
        cout << setw(setTam) << endl;
    }
    
  return 0;
}
