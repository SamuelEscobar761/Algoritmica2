def esValido(tablero , x , y):
    fila = tablero[x] != tablero[y]
    diagonal = abs(tablero[x] - tablero[y]) == abs( x - y)
    return fila and diagonal

def eightQueens (tot , tablero ):

    if (tot == 8):
        return print(tablero)
    
    for i in range(len(tablero[0])) :
        for j in range(len(tablero)):
            if (tablero[i][j] == 0):
                tablero[i][j] = 1
                if (esValido(tablero , i,j)):
                    eightQueens(tablero+1 , tablero)
                else:
                    tablero[i][j] = 0