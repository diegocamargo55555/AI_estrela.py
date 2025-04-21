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

void montarTabela(const vector<cidade> &cidades, vector<string> &nomesCidades)
{
    nomesCidades.clear();
    nomesCidades.push_back(" ");

    // ele vai por nome agora, ao inves de ir por link da cidade[0] (so mudei isso na sua função bea, ta de boa)
    for (const cidade &c : cidades)
    {
        nomesCidades.push_back(c.nome);
    }

    int numCidades = nomesCidades.size();
    vector<vector<string>> tabela(numCidades, vector<string>(numCidades));

    tabela[0] = nomesCidades;

    for (int i = 1; i < numCidades; i++)
    {
        tabela[i][0] = nomesCidades[i];
    }

    for (int i = 1; i < numCidades; i++)
    {
        for (int j = 1; j < numCidades; j++)
        {
            if (tabela[i][0] == tabela[0][j])
            {
                tabela[i][j] = "x";
            }
            else
            {
                int linha = findIndex(cidades, tabela[i][0]);
                float dist = verDistancia(const_cast<cidade &>(cidades[linha]), tabela[0][j]);
                if (dist != -1)
                {
                    string aux = to_string(dist);
                    tabela[i][j] = aux.substr(0, aux.find(".") + 3);
                }
                else
                {
                    tabela[i][j] = "N/A";
                }
            }
        }
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < numCidades; i++)
    {
        for (int j = 0; j < numCidades; j++)
        {
            cout << setw(10) << tabela[i][j] << "\t";
        }
        cout << endl;
    }
}

vector<cidade> linkCidades(vector<cidade> &cidades)
{

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

void Odyssey()
{
    vector<string> nomesCidades;
    vector<cidade> cidades(9);
    string destino = "Itaca";

    cidades[0].nome = "Troia";
    cidades[1].nome = "Djorba";
    cidades[2].nome = "Sicilia";
    cidades[3].nome = "Cerveti";
    cidades[4].nome = "Punta Falcone";
    cidades[5].nome = "Monaco";
    cidades[6].nome = "Sorrento";
    cidades[7].nome = "Foret de Chebba";
    cidades[8].nome = "Itaca";

    cidades[0].vizinhos = {"Djorba"};
    cidades[0].distancia = {135};
    cidades[0].reta = 2000;

    cidades[1].vizinhos = {"Troia", "Sicilia"};
    cidades[1].distancia = {135, 1842};
    cidades[1].reta = 1800;

    cidades[2].vizinhos = {"Djorba", "Cerveti"};
    cidades[2].distancia = {1842, 500};
    cidades[2].reta = 1400;

    cidades[3].vizinhos = {"Sicilia", "Punta Falcone"};
    cidades[3].distancia = {500, 1013};
    cidades[3].reta = 1000;

    cidades[4].vizinhos = {"Proximo de Cerveti", "Monaco", "Sorrento"};
    cidades[4].distancia = {1013, 246, 430};
    cidades[4].reta = 850;

    cidades[5].vizinhos = {"Punta Falcone"};
    cidades[5].distancia = {246};
    cidades[5].reta = 780;

    cidades[6].vizinhos = {"Punta Falcone", "Foret de Chebba"};
    cidades[6].distancia = {430, 978};
    cidades[6].reta = 500;

    cidades[7].vizinhos = {"Sorrento", "Itaca"};
    cidades[7].distancia = {978, 120};
    cidades[7].reta = 200;

    cidades[8].vizinhos = {"Foret de Chebba"};
    cidades[8].distancia = {120};
    cidades[8].reta = 0;

    linkCidades(cidades);
    montarTabela(cidades, nomesCidades);
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
    cidades[0].reta = 800;

    cidades[1].vizinhos = {"Hisarlik", "Potami", "Chios"};
    cidades[1].distancia = {174, 449, 407};
    cidades[1].reta = 750;

    cidades[2].vizinhos = {"Esmirna", "Potami", "Legrena"};
    cidades[2].distancia = {407, 184, 347};
    cidades[2].reta = 700;

    cidades[3].vizinhos = {"Esmirna", "Chios", "Legrena"};
    cidades[3].distancia = {449, 347, 110};
    cidades[3].reta = 550;

    cidades[4].vizinhos = {"Potami", "Pireu", "Corinto", "Chios"};
    cidades[4].distancia = {110, 55, 125, 347};
    cidades[4].reta = 400;

    cidades[5].vizinhos = {"Legrena", "Drepano", "Corinto"};
    cidades[5].distancia = {55, 96, 567};
    cidades[5].reta = 320;

    cidades[6].vizinhos = {"Legrena", "Drepano", "Pireu"};
    cidades[6].distancia = {125, 57, 567};
    cidades[6].reta = 300;

    cidades[7].vizinhos = {"Pireu", "Corinto", "Itaca"};
    cidades[7].distancia = {96, 57, 128};
    cidades[7].reta = 130;

    cidades[8].vizinhos = {"Drepano"};
    cidades[8].distancia = {128};
    cidades[8].reta = 0;

    linkCidades(cidades);

    montarTabela(cidades, nomesCidades);
}

void abraao()
{
    vector<string> nomesCidades;
    vector<cidade> cidades(9);
    string destino = "Berseba";

    cidades[0].nome = "Ur";
    cidades[1].nome = "Babilonia";
    cidades[2].nome = "Hara";
    cidades[3].nome = "Carquemis";
    cidades[4].nome = "Alepo";
    cidades[5].nome = "Siquem";
    cidades[6].nome = "Gaza";
    cidades[7].nome = "Zoa";
    cidades[8].nome = "Berseba";

    cidades[0].vizinhos = {"Babilonia"};
    cidades[0].distancia = {236};
    cidades[0].reta = 2380;

    cidades[1].vizinhos = {"Ur", "Hara"};
    cidades[1].distancia = {236, 676};
    cidades[1].reta = 2150;

    cidades[2].vizinhos = {"Babilonia", "Carquemis"};
    cidades[2].distancia = {676, 91};
    cidades[2].reta = 1470;

    cidades[3].vizinhos = {"Hara", "Alepo"};
    cidades[3].distancia = {91, 103};
    cidades[3].reta = 1380;

    cidades[4].vizinhos = {"Carquemis", "Siquem"};
    cidades[4].distancia = {103, 482};
    cidades[4].reta = 1270;

    cidades[5].vizinhos = {"Alepo", "Gaza"};
    cidades[5].distancia = {482, 218};
    cidades[5].reta = 790;

    cidades[6].vizinhos = {"Siquem", "Zoa"};
    cidades[6].distancia = {218, 263};
    cidades[6].reta = 570;

    cidades[7].vizinhos = {"Gaza", "Berseba"};
    cidades[7].distancia = {263, 283};
    cidades[7].reta = 300;

    cidades[8].vizinhos = {"Zoa"};
    cidades[8].distancia = {283};
    cidades[8].reta = 0;

    linkCidades(cidades);
    montarTabela(cidades, nomesCidades);
}

void abraaoGPS()
{

    vector<string> nomesCidades;
    vector<cidade> cidades(5);
    string destino = "Bersaba";

    cidades[0].nome = "Ur";
    cidades[1].nome = "Ramadi";
    cidades[2].nome = "Ar-Rutba";
    cidades[3].nome = "Damasco";
    cidades[4].nome = "Bersaba";

    cidades[0].vizinhos = {"Ramadi"};
    cidades[0].distancia = {443};
    cidades[0].reta = 1400;

    cidades[1].vizinhos = {"Ur", "Ar-Rutba", "Damasco"};
    cidades[1].distancia = {443, 420, 721};
    cidades[1].reta = 1100;

    cidades[2].vizinhos = {"Ramadi", "Ur", "Damasco"};
    cidades[2].distancia = {301, 727, 420};
    cidades[2].reta = 1050;

    cidades[3].vizinhos = {"Ramadi", "Ar-Rutba", "Bersaba"};
    cidades[3].distancia = {721, 420, 361};
    cidades[3].reta = 600;

    cidades[4].vizinhos = {"Damasco"};
    cidades[4].distancia = {361};
    cidades[4].reta = 0;

    linkCidades(cidades);
    montarTabela(cidades, nomesCidades);
}

void moises()
{
    vector<string> nomesCidades;
    vector<cidade> cidades(9);
    string destino = "Jerico";

    cidades[0].nome = "Tanis";
    cidades[1].nome = "Sucote";
    cidades[2].nome = "Mara";
    cidades[3].nome = "MonteSinai";
    cidades[4].nome = "CadesBarnea";
    cidades[5].nome = "Arnom";
    cidades[6].nome = "PontoRio";
    cidades[7].nome = "RioJordao";
    cidades[8].nome = "Jerico";

    cidades[0].vizinhos = {"Sucote"};
    cidades[0].distancia = {134};
    cidades[0].reta = 1343;

    cidades[1].vizinhos = {"Tanis", "Mara"};
    cidades[1].distancia = {134, 363};
    cidades[1].reta = 1200;

    cidades[2].vizinhos = {"Sucote", "MonteSinai"};
    cidades[2].distancia = {363, 147};
    cidades[2].reta = 850;

    cidades[3].vizinhos = {"Mara", "CadesBarnea", "Arnom"};
    cidades[3].distancia = {147, 153, 242};
    cidades[3].reta = 700;

    cidades[4].vizinhos = {"MonteSinai"};
    cidades[4].distancia = {181}; // L - K
    cidades[4].reta = 550;

    cidades[5].vizinhos = {"MonteSinai", "PontoRio"};
    cidades[5].distancia = {242, 47};
    cidades[5].reta = 470;

    cidades[6].vizinhos = {"Arnom", "RioJordao", "Jerico"};
    cidades[6].distancia = {47, 78, 18};
    cidades[6].reta = 200;

    cidades[7].vizinhos = {"PontoRio"};
    cidades[7].distancia = {78};
    cidades[7].reta = 100;

    cidades[8].vizinhos = {"PontoRio"};
    cidades[8].distancia = {18};
    cidades[8].reta = 0;

    linkCidades(cidades);
    montarTabela(cidades, nomesCidades);
}

void moisesGPS()
{

    vector<string> nomesCidades;
    vector<cidade> cidades(6);
    string destino = "Cisjordania";

    cidades[0].nome = "Tanis";
    cidades[1].nome = "Nekhel";
    cidades[2].nome = "Taba";
    cidades[3].nome = "Eilot";
    cidades[4].nome = "Feifa";
    cidades[5].nome = "Cisjordania";

    cidades[0].vizinhos = {"Nekhel"};
    cidades[0].distancia = {255};
    cidades[0].reta = 500;

    cidades[1].vizinhos = {"Tanis", "Taba", "Eliot"};
    cidades[1].distancia = {255, 149, 159};
    cidades[1].reta = 380;

    cidades[2].vizinhos = {"Nekhel", "Eilot"};
    cidades[2].distancia = {149, 79};
    cidades[2].reta = 350;

    cidades[3].vizinhos = {"Taba", "Nekhel", "Feifa"};
    cidades[3].distancia = {79, 159, 182};
    cidades[3].reta = 270;

    cidades[4].vizinhos = {"Eilot", "Cisjordania"};
    cidades[4].distancia = {182, 165};
    cidades[4].reta = 150;

    cidades[5].vizinhos = {"Feifa"};
    cidades[5].distancia = {165};
    cidades[5].reta = 0;

    linkCidades(cidades);
    montarTabela(cidades, nomesCidades);
}
