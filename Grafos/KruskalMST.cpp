//MST 
/*
Kruskal

El algoritmo de Kruskal es un algoritmo del tipo greedy en el cual lo que haremos es ordenar las aristas por sus costos de menor 
a mayor, esto nos garantiza que al tomar una arista esta sea mínima, el algoritmo no termina ahí, debido a que estamos buscando 
un árbol utilizamos la estructura de datos Union-Find para excluir aquellas aristas que creen ciclos.*/

#include <bits/stdc++.h>

using namespace std;

class edge{ //arista
    public:
    int x,y,c; // extremo 1, extremo 2, costo
    
    edge (int a, int b, int d){
        x=a; y=b; c=d; 
    }

    bool operator < (const edge &other) const{ //sobrecargamos el operador menor
        return c < other.c; 
    }
};

vector <edge> v;

int Kruskal(){
    sort(v.begin(),v.end());
    int costo=0;
    for (int i=0;i<v.size();++i){
        int x = v[i].x;
        int y = v[i].y;
        if ( Find(x) == Find(y) ) continue;  //misma componente formarian un ciclo
        
            Union(x,y);
            costo+=v[i].c;
    }

    return costo; 
} 

// este algoritmo tiene una poda importante, cual creen que pueda ser?
// O(Elog(E))
