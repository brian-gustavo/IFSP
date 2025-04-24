#include <iostream>
using namespace std;

// Estrutura de um nó da árvore binária
struct No
{
    int valor;
    No* dir;
    No* esq;
};

No* inicializar()
{
    return nullptr; // Inicializa o nó da árvore binária como nulo
}

void adicionar(No*& raiz, int valor)
{
    if (raiz == nullptr) // Se a árvore estiver vazia
    {
        raiz = new No; // Cria um novo nó
        raiz->valor = valor; // Atribui o valor ao nó
        raiz->esq = nullptr; // Inicializa o filho esquerdo como nulo
        raiz->dir = nullptr; // Inicializa o filho direito como nulo
    }
    else if (valor < raiz->valor) // Se o valor for menor que o valor do nó atual
    {
        adicionar(raiz->esq, valor); // Adiciona à subárvore esquerda
    }
    else if (valor > raiz->valor) // Se o valor for maior que o valor do nó atual
    {
        adicionar(raiz->dir, valor); // Adiciona à subárvore direita
    }
}

void buscar(int valor, No* raiz) 
{
    if (raiz == nullptr)
    {
        cout << "Nada encontrado!" << endl;
        return;
    }

    if (valor == raiz->valor)
    {
        cout << "Valor encontrado!" << endl;
        return;
    } else if (valor < raiz->valor) {
        buscar(valor, raiz->esq);
    } else {
        buscar(valor, raiz->dir);
    }
}

int contagem(No* raiz)
{
    if (raiz == nullptr)
    {
        return 0;
    }
    return contagem(raiz->esq) + 1 + contagem(raiz->dir);
}

void emOrdem(No* raiz) 
{
    if (raiz == nullptr)
    {
        return;
    }
    emOrdem(raiz->esq);
    cout << raiz->valor << " ";
    emOrdem(raiz->dir);
}

int main() 
{
    No* raiz = inicializar(); // Inicializa o nó da árvore binária

    adicionar(raiz, 5); // Adiciona o valor 5 à árvore
    adicionar(raiz, 25);
    adicionar(raiz, 35);
    adicionar(raiz, 15);
    adicionar(raiz, 2);

    buscar(35, raiz);
    buscar(7, raiz);

    contagem(raiz);

    emOrdem(raiz);

    return 0;
}
