#include <bits/stdc++.h> 

using namespace std; 
int numberOfNodes = 0;
struct node {
    char caracter;       
    bool finDePalabra = false;                
    struct node *hijos[27];  // [null,null,null,......,null]
}*trie; 

// Inicializar 

void init() {
    trie = new node();  // Instanciar el objeto trie
    numberOfNodes++;
}

void insertWord(string word) {   // alba 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) { // alba
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->hijos[character] == NULL ) {
            currentNode->hijos[character] = new node();
            numberOfNodes++;
        }
        currentNode = currentNode->hijos[character];
        currentNode->caracter = word[i];
    }
    currentNode->finDePalabra = true;
}

int main() { 
    int numberOfWords; 
    cin >> numberOfWords;
    while(numberOfWords--) {
        string word;
        cin>>word;

    }
    cout<<numberOfNodes++<<endl;
    return 0;
}