// Arquivo temporário pra fins de consulta. Guarde em seu próprio repositório ou em outro local se precisar no futuro.

#include <iostream>
using namespace std;

struct No
{
    int valor;
    No* dir;
    No* esq;
};

No* inicializar()
{
    return nullptr;
}

void adicionar(No*& raiz, int valor)
{
    if (raiz == nullptr)
    {
        raiz = new No;
        raiz->valor = valor;
        raiz->esq = nullptr;
        raiz->dir = nullptr;
    }
    else if (valor < raiz->valor)
    {
        adicionar(raiz->esq, valor);
    }
    else if (valor > raiz->valor)
    {
        adicionar(raiz->dir, valor);
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
    No* raiz = inicializar();

    adicionar(raiz, 5);
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
