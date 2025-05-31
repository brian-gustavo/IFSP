#include <iostream>
#include <cstdlib>

#define MAX_VERTICES 5

struct Grafo {
    int adjacencias[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
};

struct Grafo* criarGrafo(int V) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));

    if (grafo == NULL) {
        std::cout << "Erro de alocacao de memoria!" << std::endl;
        exit(1);
    }

    grafo->numVertices = V;

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            grafo->adjacencias[i][j] = 0;
        }
    }

    return grafo;
}

void adicionarAresta(struct Grafo* grafo, int origem, int destino, int direcionado) {
    if (origem < 0 || origem >= grafo->numVertices || destino < 0 || destino >= grafo->numVertices) {
        std::cout << "Erro: Vertice invalido." << std::endl;
        return;
    }

    grafo->adjacencias[origem][destino] = 1;

    if (!direcionado) {
        grafo->adjacencias[destino][origem] = 1;
    }
}

void imprimirGrafo(struct Grafo* grafo) {
    std::cout << "Representacao do Grafo (Matriz de Adjacencia):" << std::endl;

    std::cout << "  ";
    for (int i = 0; i < grafo->numVertices; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "----";
    for (int i = 0; i < grafo->numVertices; ++i) {
        std::cout << "--";
    }
    std::cout << std::endl;

    for (int i = 0; i < grafo->numVertices; ++i) {
        std::cout << i << " | ";
        for (int j = 0; j < grafo->numVertices; ++j) {
            std::cout << grafo->adjacencias[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void DFS_Recursivo(struct Grafo* grafo, int verticeAtual, bool visitado[]) {
    visitado[verticeAtual] = true;
    std::cout << verticeAtual << " ";

    for (int i = 0; i < grafo->numVertices; ++i) {
        if (grafo->adjacencias[verticeAtual][i] == 1 && !visitado[i]) {
            DFS_Recursivo(grafo, i, visitado);
        }
    }
}

void buscaProfundidade(struct Grafo* grafo, int verticeInicial) {
    bool* visitado = (bool*)malloc(grafo->numVertices * sizeof(bool));
    if (visitado == NULL) {
        std::cout << "Erro de alocacao de memoria para 'visitado'!" << std::endl;
        exit(1);
    }

    for (int i = 0; i < grafo->numVertices; ++i) {
        visitado[i] = false;
    }

    std::cout << "\nBusca em Profundidade (DFS) a partir do vertice " << verticeInicial << ":" << std::endl;
    DFS_Recursivo(grafo, verticeInicial, visitado);
    std::cout << std::endl;

    free(visitado);
}

void liberarGrafo(struct Grafo* grafo) {
    free(grafo);
}

int main() {
    int numVertices = 5;
    struct Grafo* grafo = criarGrafo(numVertices);

    adicionarAresta(grafo, 0, 1, 0);
    adicionarAresta(grafo, 0, 4, 0);
    adicionarAresta(grafo, 1, 2, 0);
    adicionarAresta(grafo, 1, 3, 0);
    adicionarAresta(grafo, 1, 4, 0);
    adicionarAresta(grafo, 2, 3, 0);
    adicionarAresta(grafo, 3, 4, 0);

    imprimirGrafo(grafo);

    buscaProfundidade(grafo, 0);
    
    liberarGrafo(grafo);

    return 0;
}
