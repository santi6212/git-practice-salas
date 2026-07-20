#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int valor) {
        dato = valor;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

//examen 3

int contarNodos(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return 1 + contarNodos(nodo->izquierdo) + contarNodos(nodo->derecho);
}

void insertarMenorArriba(Nodo*& nodo, int valor) {
    if (nodo == nullptr) {
        nodo = new Nodo(valor);
        return;
    }

    if (valor < nodo->dato) {
        int temporal = nodo->dato;
        nodo->dato = valor;
        valor = temporal;
    }

    if (contarNodos(nodo->izquierdo) <= contarNodos(nodo->derecho)) {
        insertarMenorArriba(nodo->izquierdo, valor);
    } else {
        insertarMenorArriba(nodo->derecho, valor);
    }
}

void mostrarArbolPuro(Nodo* nodo, int espacios) {
    if (nodo == nullptr) return;

    espacios += 5;

    mostrarArbolPuro(nodo->derecho, espacios);

    cout << "\n";
    for (int i = 5; i < espacios; i++) {
        cout << " ";
    }
    cout << "[" << nodo->dato << "]\n";

    mostrarArbolPuro(nodo->izquierdo, espacios);
}

//main
int main() {
    Nodo* root = nullptr;
	
    insertarMenorArriba(root, 11);
    insertarMenorArriba(root, 22);
    insertarMenorArriba(root, 33);
    insertarMenorArriba(root, 44);
    insertarMenorArriba(root, 55);
    insertarMenorArriba(root, 66);
    insertarMenorArriba(root, 77); 
    
    cout << "ESTRUCTURA DEL ARBOL (ejemplo)"<<endl;
    cout << "(La raiz esta a la izquierda [Nivel 0]; los niveles crecen hacia la derecha)"<<endl;
    
    mostrarArbolPuro(root, 0);

    return 0;
}
