#include <iostream>

int main(){
    cidade oradea, zerind, arad, sibiu;
    oradea.lugares[0] = &zerind;
    oradea.distancia[0] = 71;
    oradea.lugares[1] = &sibiu;
    oradea.distancia[1] = 151;
    zerind.lugares[0] = &arad;
    zerind.distancia[0] = 75;
    arad.lugares[0] = &sibiu;
    arad.distancia[0] = 140;

    cidade abertas[100], fechadas[100];

    
    int g = 0;
    int h = heuristica();
    int f = g+h;



}

int heuristica(){
    return 5
}

struct cidade
{
    
    cidade *lugares[100];
    int distancia[100];

};
