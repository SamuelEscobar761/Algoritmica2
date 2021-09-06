#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int numberOfNodes = 0;
struct node
{
    map<char, node*> mapero;
    bool isWord = false;
    int contadorPalabras = 0;                
} *trie;

void init()
{
    trie = new node();
}

void insertWord(string word)
{
    node *currentNode = trie;  
    for (int i = 0; i < word.length(); i++)
    {
        
        //    if (!currentNode->mapero[word[i]])
        if(currentNode->mapero.find(word[i]) == currentNode->mapero.end())
        {
            currentNode->mapero[word[i]] = new node();
        }
        currentNode = currentNode->mapero[word[i]];
        currentNode->contadorPalabras++;
    }
    currentNode->isWord=true;
}

string findPrefixCommon(){
    node *currentNode = trie;
    string prefix = "";
    while(currentNode->mapero.size() == 1 && !currentNode->isWord){
        prefix += currentNode->mapero.begin()->first;
        currentNode = currentNode->mapero.begin()->second;
    }
    return prefix;
}

int main() {
    string linea = "";
    input;
    init();
    while(cin >> linea && linea != ""){
        insertWord(linea);
    }
    
}