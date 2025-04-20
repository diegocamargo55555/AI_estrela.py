#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct cidade
{
    string nome;
    vector<string> vizinhos;
    vector<cidade *> cidades;
    vector<int> distancia;
    float reta;
};

void tabelas(vector<string> &visitadas, cidade *atual)
{
    if (atual == nullptr)
        return;

    // so ve se a cidade ja foi visitada, pra não virar um loop com os vizinhos
    if (find(visitadas.begin(), visitadas.end(), atual->nome) != visitadas.end())
        return;

    visitadas.push_back(atual->nome);

    // vai indo pros vizinhos para relacionar os ponteiros dieguinho
    for (cidade *viz : atual->cidades)
    {
        tabelas(visitadas, viz);
    }
}
    
float verDistancia(cidade &v, const string &val)
{
    for (int i = 0; i < v.vizinhos.size(); i++)
    {
        if (v.vizinhos[i] == val)
        {
            return v.distancia[i];
        }
    }
    return -1;
}

int findIndex(const vector<cidade> &v, const string &val)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].nome == val)
        {
            return i;
        }
    }
    return -1;
}

void montarTabela(const vector<cidade>& cidades, vector<string> &nomesCidades) {
    nomesCidades.clear();
    nomesCidades.push_back(" ");

    // ele vai por nome agora, ao inves de ir por link da cidade[0] (so mudei isso na sua função bea, ta de boa)
    for (const cidade& c : cidades) {
        nomesCidades.push_back(c.nome);
    }

    int numCidades = nomesCidades.size();
    vector<vector<string>> tabela(numCidades, vector<string>(numCidades));

    tabela[0] = nomesCidades;

    for (int i = 1; i < numCidades; i++) {
        tabela[i][0] = nomesCidades[i];
    }

    for (int i = 1; i < numCidades; i++) {
        for (int j = 1; j < numCidades; j++) {
            if (tabela[i][0] == tabela[0][j]) {
                tabela[i][j] = "x";
            } else {
                int linha = findIndex(cidades, tabela[i][0]);
                float dist = verDistancia(const_cast<cidade&>(cidades[linha]), tabela[0][j]);
                if (dist != -1) {
                    string aux = to_string(dist);
                    tabela[i][j] = aux.substr(0, aux.find(".")+3);
                } else {
                    tabela[i][j] = "N/A";
                }
            }
        }
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < numCidades; i++) {
        for (int j = 0; j < numCidades; j++) {
            cout << setw(10) << tabela[i][j] << "\t";
        }
        cout << endl;
    }
}

vector<cidade> linkCidades(vector<cidade> &cidades){

    for (int i = 0; i < cidades.size(); i++)
    {
        for (int j = 0; j < cidades[i].vizinhos.size(); j++)
        {
            for (int k = 0; k < cidades.size(); k++)
            {
                if (cidades[i].vizinhos[j] == cidades[k].nome)
                {
                    cidades[i].cidades.push_back(&cidades[k]);
                }
            }
        }
    }
    
    return cidades;
}

void OdysseyGPS()
{
    vector<string> nomesCidades;
    vector<cidade> cidades(9);
    string destino = "Itaca";

    cidades[0].nome = "Hisarlik";
    cidades[1].nome = "Esmirna";
    cidades[2].nome = "Chios";
    cidades[3].nome = "Potami";
    cidades[4].nome = "Legrena";
    cidades[5].nome = "Pireu";
    cidades[6].nome = "Corinto";
    cidades[7].nome = "Drepano";
    cidades[8].nome = "Itaca";

    cidades[0].vizinhos = {"Esmirna", "Chios"};
    cidades[0].distancia = {174, 81};
    cidades[0].reta = 380;

    cidades[1].vizinhos = {"Hisarlik", "Potami", "Chios"};
    cidades[1].distancia = {174, 449, 407};
    cidades[1].reta = 350;

    cidades[2].vizinhos = {"Esmirna", "Potami", "Legrena"};
    cidades[2].distancia = {407, 184, 347};
    cidades[2].reta = 320;

    cidades[3].vizinhos = {"Esmirna", "Chios", "Legrena"};
    cidades[3].distancia = {449, 347, 110};
    cidades[3].reta = 290;

    cidades[4].vizinhos = {"Potami", "Pireu", "Corinto", "Chios"};
    cidades[4].distancia = {110, 55, 125, 347};
    cidades[4].reta = 250;

    cidades[5].vizinhos = {"Legrena", "Drepano", "Corinto"};
    cidades[5].distancia = {55, 96, 567};
    cidades[5].reta = 220;

    cidades[6].vizinhos = {"Legrena", "Drepano", "Pireu"};
    cidades[6].distancia = {125, 57, 567};
    cidades[6].reta = 200;

    cidades[7].vizinhos = {"Pireu", "Corinto", "Itaca"};
    cidades[7].distancia = {96, 57, 128};
    cidades[7].reta = 160;

    cidades[8].vizinhos = {"Drepano"};
    cidades[8].distancia = {128};
    cidades[8].reta = 0;

    linkCidades(cidades);

    montarTabela(cidades, nomesCidades);
}

void abraaoGPS(){

    vector<string> nomesCidades;
    vector<cidade> cidades(9);
    string destino = "Bersaba";

    cidades[0].nome = "Ur";
    cidades[1].nome = "Ramadi";
    cidades[2].nome = "";
    cidades[3].nome = "Damasco";
    cidades[4].nome = "";
    cidades[5].nome = "Bersaba";

    cidades[0].vizinhos = {"Ramadi"};
    cidades[0].distancia = {};
    cidades[0].reta = ;

    cidades[1].vizinhos = {"Ur", "", "Damasco"};
    cidades[1].distancia = {};
    cidades[1].reta = ;

    cidades[2].vizinhos = {"Ramadi", "Ur", "Damasco"};
    cidades[2].distancia = {};
    cidades[2].reta = ;

    cidades[3].vizinhos = {"Ramadi", "", "Bersaba"};
    cidades[3].distancia = {};
    cidades[3].reta = ;

    cidades[4].vizinhos = {"Ramadi", "", "Bersaba"};
    cidades[4].distancia = {};
    cidades[4].reta = ;

    cidades[5].vizinhos = {"Damasco", ""};
    cidades[5].distancia = {};
    cidades[5].reta = 0;

    linkCidades(cidades);

    montarTabela(cidades, nomesCidades);
}

void moisesGPS(){

    vector<string> nomesCidades;
    vector<cidade> cidades(9);
    string destino = "Cisjordania";

    cidades[0].nome = "Tanis";
    cidades[1].nome = "Nekhel";
    cidades[2].nome = "Taba";
    cidades[3].nome = "Eilot";
    cidades[4].nome = "Feifa";
    cidades[5].nome = "Cisjordania";

    cidades[0].vizinhos = {"Nekhel"};
    cidades[0].distancia = {};
    cidades[0].reta = ;

    cidades[1].vizinhos = {"Tanis", "Taba", "Eliot"};
    cidades[1].distancia = {};
    cidades[1].reta = ;

    cidades[2].vizinhos = {"Nekhel", "Eilot"};
    cidades[2].distancia = {};
    cidades[2].reta = ;

    cidades[3].vizinhos = {"Taba", "Nekhel", "Feifa"};
    cidades[3].distancia = {};
    cidades[3].reta = ;

    cidades[4].vizinhos = {"Eilot", "Cisjordania"};
    cidades[4].distancia = {};
    cidades[4].reta = ;

    cidades[5].vizinhos = {"Feifa"};
    cidades[5].distancia = {};
    cidades[5].reta = 0;

    linkCidades(cidades);

    montarTabela(cidades, nomesCidades);
}



