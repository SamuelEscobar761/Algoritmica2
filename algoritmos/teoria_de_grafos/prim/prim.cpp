#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 
 
// Numero de vertices en el grafo
#define V 999
int vertices = 999;
 
// Encontrar el vertice con menor peso de arista
int pesoMinimo(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 
// Imprimir el MST
void imprimirMST(int parent[], int graph[V][V])
{
    int total = 0;
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < vertices; i++){
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
        total += graph[i][parent[i]];
    }
    cout << "Total: " << total << endl;   
}
 
// Construir e imprimir el MST
void prim(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
 
    // Empezamos con todos los pesos al infinito
    for (int i = 0; i < vertices; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    // Iniciamos con el primer vertice
    key[0] = 0;
    parent[0] = -1; // El primer nodo del MST es fantasma
 
    for (int count = 0; count < vertices - 1; count++)
    {
        //Conseguimos el peso minimo
        int u = pesoMinimo(key, mstSet);
        mstSet[u] = true;
 
        //Actualizamos los vertices relacionados con el vertice de peso minimo
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    // Imprimimos el MST
    imprimirMST(parent, graph);
}
 
// Driver code
int main()
{
    input;
    int numeroAristas;
    int graph[V][V];
    cin >> vertices >> numeroAristas;
    vertices = 999;

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            graph[i][j] = 0;
        }
    }
    
    for(int i = 0; i < numeroAristas; i++){
        int origen, destino;
        cin >> origen >> destino;
        graph[origen][destino] += 1;
    }
 
    // Print the solution
    prim(graph);
 
    return 0;
}