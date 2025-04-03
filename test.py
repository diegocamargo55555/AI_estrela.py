

from dataclasses import dataclass


def main():
    atenas_esparta = dist_Cidade(atena, esparta, 400)
    
    dist_percorrida, aresta_U = int
    f, g, pai, abertos, fechados = []
    achou = bool(False)
    no_inicial = 0
    g[no_inicial] = 0
    f[no_inicial] = g[no_inicial] + heuristica(no_inicial)
    pai[no_inicial] = None
    abertos.append(no_inicial)
    while abertos != None:
        v = melhor_certice(abertos)
    novo_f = g[v] + c(v,u) + heuristica(u)
    if (atenas_esparta.cidade_A in fechados or atenas_esparta.cidade_A in abertos) and (novo_f >= f[u]):
        print("ola")



def heuristica (a):
    return a+1 #so pra retornar algo

def melhor_certice(a):
    return 5

def c(u,v):
    return u+v

    
@dataclass
class dist_Cidade:
    cidade_A = str
    cidade_B = str
    distancia = int
    
    
@dataclass
class cidade:
    cidade_ligadas = Cidades_espec[]
    distancia = []
