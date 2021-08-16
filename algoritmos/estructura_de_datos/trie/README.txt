Trie es un algorítmo de tipo estructura de datos que nos permite almacenar toda palabra que le pasemos en base a nodos. Cada nodo deberá corresponder a un caracter de la palabra. De esta forma podemos armar un arbol que se base en los prefijos de las palabras. Así mismo tenemos que tener en cuenta que hay que almacenar todo nodo que representa el fin de una palabra.

Operaciones:

insertar(word)
buscar(word)
borrar(word)

Complejidad:

Siendo n la cantidad de elementos en la estructura y k la longitud de una palabra a buscar.

insertar(word): O(k)
buscar(word): O(k)
borrar(word): O(k)