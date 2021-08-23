#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int nums [];

struct node {
    int min;
    int max;
    int suma;
}segmentTree[1000000];

void init(int ini, int fin, int currentNode) {
    if(ini==fin) {
        segmentTree[currentNode].min = nums[ini];
        segmentTree[currentNode].max = nums[ini];
        segmentTree[currentNode].suma = nums[ini];
    } else {
        int medio = (ini + fin)/2;
        int izq =  2*currentNode+1;
        int der = 2*currentNode+2;
        init(ini, medio, izq);
        init(medio+1, fin, der);
        segmentTree[currentNode].min = min(segmentTree[izq].min, segmentTree[der].min);
        segmentTree[currentNode].max = max(segmentTree[izq].max, segmentTree[der].max);
        segmentTree[currentNode].suma = segmentTree[izq].suma + segmentTree[der].suma;
    }
}

node query(int ini, int fin, int currentNode, int i, int j) {
    if(ini >= i && fin<=j) {
        return segmentTree[currentNode];
    }else {
        int medio = (ini + fin)/2;
        int hijoIzquierda =  2*currentNode+1;
        int hijoDerecha = 2*currentNode+2;
        if(j<=medio) {
            return query(ini, medio, hijoIzquierda, i,j);
        } else if(i>medio) {
            return query(medio +1, fin, hijoDerecha, i,j);
        } else {
            node queryIzq = query(ini, medio, hijoIzquierda, i,j);
            node queryDer = query(medio+1, fin, hijoDerecha, i, j);
            node resultado;
            resultado.min = min(queryIzq.min, queryDer.min);
            resultado.max = max(queryIzq.max, queryDer.max);
            resultado.suma = queryIzq.suma + queryDer.suma;
            return resultado;
        }
    }
}


void update(int inicio, int fin, int nodoActual, int posicion, int valor) {
    if(posicion<inicio || posicion>fin) {
        return;
    }
    if(inicio==fin) {
        segmentTree[nodoActual].max = valor;
        segmentTree[nodoActual].min = valor;
        segmentTree[nodoActual].suma = valor;
    }else {
        int medio = (inicio + fin)/2
        int hijoIzquierda =  2*nodoActual+1;
        int hijoDerecha = 2*nodoActual+2;
        update(inicio, medio, hijoIzquierda, posicion, valor);
        update(medio+1, fin, hijoDerecha, posicion, valor);
        segmentTree[nodoActual].suma = segmentTree[hijoIzquierda].suma + segmentTree[hijoDerecha].suma;
        segmentTree[nodoActual].max = max(segmentTree[hijoIzquierda].max,  segmentTree[hijoDerecha].max);
        segmentTree[nodoActual].min = min(segmentTree[hijoIzquierda].min, segmentTree[hijoDerecha].min);
    }
}


int main() {
    int tamanhoArray;
    init(0,tamanhoArray-1,0);
    return 0;
}