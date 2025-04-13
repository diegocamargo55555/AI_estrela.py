#include <iomanip>
#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct cidade {
    std::string nome;
    std::vector<std::string> vizinhos;
    std::vector<cidade*> cidades;
    std::vector<int> distancia;
    float reta;

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

int findIndex(vector<cidade> v, string val) {
    for (int i = 0; i < v.size(); i++) {
              if (v[i].nome == val) {
            return i;
        }
    }
}
int main() {
    vector<string> nomesCidades;
    vector<cidade> cidades;
    cidade oradea, zerind, arad, sibiu, fagaras, rimnieu, craiova, pitesti, timisoara, logoj, mehadia, dobreta;
    oradea.nome = "oradea";
    oradea.vizinhos.push_back("zerind");
    oradea.vizinhos.push_back("sibiu");
    oradea.cidades.push_back(&zerind);
    oradea.reta = 380;
    oradea.cidades.push_back(&sibiu);
    oradea.distancia.push_back(71);
    oradea.distancia.push_back(151);
    cidades.push_back(oradea);

    zerind.nome = "zerind";
    zerind.vizinhos.push_back("arad");
    zerind.cidades.push_back(&arad);
    zerind.distancia.push_back(75);
    zerind.reta = 374;
    cidades.push_back(zerind);

    arad.nome = "arad";
    arad.vizinhos.push_back("sibiu");
    arad.cidades.push_back(&sibiu);
    arad.distancia.push_back(140);
    arad.vizinhos.push_back("timisoara");
    arad.cidades.push_back(&timisoara);
    arad.distancia.push_back(118);
    arad.reta = 366;
    cidades.push_back(arad);

    sibiu.nome = "sibiu";
    sibiu.vizinhos.push_back("fagaras");
    sibiu.cidades.push_back(&fagaras);
    sibiu.distancia.push_back(99);
    sibiu.vizinhos.push_back("rimnieu");
    sibiu.cidades.push_back(&rimnieu);
    sibiu.distancia.push_back(80);
    sibiu.reta = 353;
    cidades.push_back(sibiu);

    fagaras.nome = "fagaras";
    fagaras.reta = 178;
    cidades.push_back(fagaras);
    
    rimnieu.nome = "rimnieu";
    rimnieu.vizinhos.push_back("craiova");
    rimnieu.cidades.push_back(&craiova);
    rimnieu.distancia.push_back(146);
    rimnieu.vizinhos.push_back("pitesti");
    rimnieu.cidades.push_back(&pitesti);
    rimnieu.distancia.push_back(97);
    rimnieu.reta = 193;
    cidades.push_back(rimnieu);

    pitesti.nome = "pitesti";
    pitesti.vizinhos.push_back("craiova");
    pitesti.cidades.push_back(&craiova);
    pitesti.distancia.push_back(138);
    pitesti.reta = 198;
    cidades.push_back(pitesti);

    craiova.nome = "craiova";
    craiova.reta = 100;
    cidades.push_back(craiova);

    timisoara.nome = "timisoara";
    timisoara.vizinhos.push_back("logoj");
    timisoara.cidades.push_back(&logoj);
    timisoara.distancia.push_back(111);
    timisoara.reta = 329;
    cidades.push_back(timisoara);

    logoj.nome = "logoj";
    logoj.reta = 111;
    cidades.push_back(logoj);

    mehadia.nome = "mehadia";
    mehadia.reta = 100;
    cidades.push_back(mehadia);

    dobreta.nome = "dobreta";
    dobreta.reta = 222;
    cidades.push_back(dobreta);


    cidade* aux = &oradea;
    int i = 1;
    nomesCidades.push_back(" ");
    nomesCidades.push_back(aux->nome);
    tabelas(&nomesCidades, aux);
    int numCidades = static_cast<int>(nomesCidades.size());
    vector<vector<string>> tabela(numCidades+1, vector<string>(numCidades));
    tabela[0] = nomesCidades;
    for(int i = 0; i < numCidades; i++){
        tabela[i][0] = nomesCidades[i];
    }
    int setTam;

    for(int i = 1; i < numCidades; i++){
        for(int j = 1; j < numCidades; j++){
            if(tabela[i][0] == tabela[0][j]){
                tabela[i][j] = 'x';
            } else{
                float dist = verDistancia(cidades[findIndex(cidades, tabela[i][0])], tabela[0][j]);
                if(dist != -1){
                    tabela[i][j] = to_string(dist);
                } else{
                    tabela[i][j] = "N/A";
                }
            }
        }
    }
    setTam = 5;
    for(int i = 0; i < numCidades; i++){
        for(int j = 0; j < numCidades; j++){
            cout << tabela[i][j] << setw(setTam) << " ";
        }
        setTam = 5;
        cout << setw(setTam) << endl;
    }
    
  return 0;
}
