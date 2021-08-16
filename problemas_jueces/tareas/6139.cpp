#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

int main () {
    input;
    int arrlength;
    int commands;
    while(cin >> arrlength && arrlength){
        cin >> commands;
        int arr[arrlength];
        for(int i = 0; i < arrlength; i++){
            cin >> arr[i];
        }

        for(int i = 0; i < commands; i++)   {
            string command;
            int firstInt;
            int secondInt;
            cin >> command;
            cin >> firstInt;
            firstInt -= 1;
            cin >> secondInt;

            if(command == "C"){
                arr[firstInt] = secondInt;
            }else if(command == "P"){
                bool itsZero = false;
                int negatives = 0;
                for(int j = firstInt; j < secondInt; j++){
                    if(arr[j] == 0){
                        itsZero = true;
                        cout << "0";
                        j = secondInt;
                    }else if(arr[j] < 0){
                        negatives = (negatives+1) % 2;
                    }
                }
                if(!itsZero && negatives == 0){
                    cout << "+";
                }else if(!itsZero){
                    cout << "-";
                }
            }
        }
        cout << endl;
    }

    return 0;
}

//[0,1,2,3]