#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

int BIT[10001];
int tamanhoVector;

void update(int posicion, int valor ) {
    for(;posicion <= tamanhoVector ;posicion += posicion&-posicion) {
        BIT[posicion] += valor;
    }
}

int query(int posicion){ // F(3)
    int result = 0;
    for(;posicion > 0 ;posicion -= posicion&-posicion) {
        result += BIT[posicion];
    }
    return result; 
}

int query2(int inicio, int final) {
    return query(final)-query(inicio);
}

int main(){
    input;
    int testCasesSize;
    
    cin >> tamanhoVector;
    
    int colony[tamanhoVector];
    int fights[tamanhoVector];
    int winnerNumber;

    for(int i = 0; i < tamanhoVector; i++){
        cin >> colony[i];
    }

    cin >> testCasesSize;
    int testCases[testCasesSize];

    for(int i =0 ;i<= tamanhoVector+2; i++){

        cout<<"["<< BIT[i]<<"]";
    }
    cout<<endl;

    for(int i = 0; i < testCasesSize; i++){
        int winner[tamanhoVector];
        int startIndex;
        int finalIndex;
        cin >> startIndex;
        cin >> finalIndex;

        for(int i = 0; i < tamanhoVector; i++){
            winner[i] = true;
        }

        for(int i = startIndex-1; i < finalIndex-1; i++){
            if(winner[i]){
                bool oneFightLost = false;
                for(int j = i+1; j < tamanhoVector; j++){
                    if(colony[j] % colony[i] != 0){
                        winner[i] = false;
                        update(i+1, 1);
                        
                        oneFightLost = true;
                        break;
                    }
                    else if(winner[j] && colony[i] % colony[j] != 0){
                        winner[j] = false;
                        update(j+1, 1);
                    }
                }
                if(!oneFightLost){
                    winnerNumber = colony[i];
                    for(int j = i; j < tamanhoVector; j++){
                        if(winner[j]){
                            if(colony[j] != winnerNumber){
                                winner[j] = false;
                                update(j+1, 1);
                            }else{
                                winner[j] = true;
                                update(j+1, -1);
                            }
                        }
                    }
                    i = tamanhoVector;
                }
            }
        }
        cout << query2(startIndex, finalIndex) << endl;
    }
}