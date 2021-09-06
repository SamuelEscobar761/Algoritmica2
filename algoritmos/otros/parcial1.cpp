#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

struct node {
    int contador = 0;
    char caracter;
    bool finDePalabra = false;
    struct node *hijos[27];
}*trie;


void init() {
    trie = new node();
    trie->finDePalabra = false;
    trie->contador = 0;
}

void insertarPalabra(string palabra) {
    node *currentNode = trie;
    for(int i = 0; i < palabra.length(); i++) {
        int caracter = palabra[i] - 'a';
        if(currentNode->hijos[caracter]==NULL) {
            currentNode -> hijos[caracter] = new node();
            currentNode -> hijos[caracter] -> contador = 0;
        }
        currentNode = currentNode->hijos[caracter];
        currentNode->caracter = palabra[i];
        currentNode->contador++;
    }
    currentNode->finDePalabra = true;
}


bool buscar(string palabra) {
    node *currentNode  = trie;
    for(int i = 0; i < palabra.length(); i++) {
        int caracter = palabra[i] - 'a';
        if(currentNode->hijos[caracter]==NULL) {
            return false;
        }
        currentNode = currentNode->hijos[caracter];
    }
    return currentNode->finDePalabra;
}


int palabrasConElMismoPrefijo(string prefijo) {
    node *currentNode =  trie;
    for (int i = 0; i< prefijo.length(); i++) {
        int caracter = prefijo[i] - 'a';  
        if(currentNode->hijos[caracter] == NULL ) {
           return 0;
        }
        currentNode = currentNode->hijos[caracter];
    }
    return currentNode->contador;
}


void borrar(string palabra) {
    node *currentNode = trie;
    for(int i = 0; i < palabra.size(); i++) {
        int caracter = palabra[i] - 'a';
        if(currentNode->hijos[caracter] == NULL) { 
            return;
        }
        currentNode = currentNode->hijos[caracter];
    }
    currentNode->finDePalabra = false;
}


bool tieneHijos(node* node) {
    for(int i = 0; i<26; i++) {
        if(node->hijos[i]) {
            return true;
        }
    }
    return false;
}


int main(){
    init();
    
}