#include <iostream>

using namespace std;

// Atividade 2
struct nodeBinario 
{
    int chave;
    nodeBinario* esq;
    nodeBinario* dir;
};

struct nodeNario
{
    int chave;
    nodeNario* primeiroFilho;
    nodeNario* proximoIrmao;
};

struct nodeAVL
{
    int chave;
    int bal;
    nodeAVL* esq;
    nodeAVL* dir;
};

// Atividade 1
struct listaDuplamenteEncadeada
{
    int valor;
    listaDuplamenteEncadeada* proximo;
    listaDuplamenteEncadeada* anterior;
};

void inserirFila(listaDuplamenteEncadeada*& cabeca, int valor) 
{
    listaDuplamenteEncadeada* novaEntrada = new listaDuplamenteEncadeada{valor, nullptr, nullptr};

    if (cabeca == nullptr)
    {
        cabeca = novaEntrada;
    } else {
        listaDuplamenteEncadeada* temp = cabeca;
        while (temp->proximo != nullptr) 
        {
            temp->anterior = temp;
            temp = temp->proximo;
        }
        temp->proximo = novaEntrada;
    }
}

void exibirFila(const listaDuplamenteEncadeada* cabeca)
{
    if (cabeca == nullptr)
    {
        cout << "Fila vazia!";
    } else {
        const listaDuplamenteEncadeada* temp = cabeca;
        while (temp != nullptr) 
        {
            cout << temp->valor << " ";
            temp = temp->proximo;
        }
        cout << endl;
    }
}

void removerFila(listaDuplamenteEncadeada*& cabeca)
{
    if (cabeca == nullptr)
    {
        cout << "Fila vazia!";
    } else {
        cabeca = cabeca->proximo;
    }
}

void inserirPilha(listaDuplamenteEncadeada*& topo, int valor) 
{
    listaDuplamenteEncadeada* temp = new listaDuplamenteEncadeada;
    temp->valor = valor;
    temp->proximo = topo;
    temp->anterior = nullptr;

    if (topo != nullptr) {
        topo->anterior = temp;
    }

    topo = temp;
}

void exibirPilha(const listaDuplamenteEncadeada* topo)
{
    if (topo == nullptr)
    {
        cout << "Pilha vazia!";
    } else {
        const listaDuplamenteEncadeada* temp = topo;
        while (temp != nullptr) {
            cout << temp->valor << " ";
            temp = temp->proximo;
        }
        cout << endl;
    }
}

void removerPilha(listaDuplamenteEncadeada*& topo)
{
    if (topo == nullptr)
    {
        cout << "Pilha vazia!";
    } else {
        listaDuplamenteEncadeada* temp = topo;
        topo = topo->proximo;

        if (topo != nullptr) {
            topo->anterior = nullptr;
        }

        delete temp;
    }
}

// Atividade 3
void atividadeTres()
{
    int raiz, segundo, terceiro;

    cout << "----- ATIVIDADE 3 -----" << endl;
    cout << "Insira o valor raiz: "; cin >> raiz;
    cout << endl;
    cout << "Insira o segundo valor: "; cin >> segundo;
    cout << endl;
    cout << "Insira o terceiro valor: "; cin >> terceiro;
    cout << endl;

    if ((segundo > raiz and terceiro < raiz) or (segundo < raiz and terceiro > raiz))
    {
        cout << "Balanceado, sem rotacionamento.";
    } else if (segundo < raiz and terceiro < segundo) {
        cout << "Necessita-se de rotacionamento LL.";
    } else if (segundo > raiz and terceiro > segundo) {
        cout << "Necessita-se de rotacionamento RR.";
    } else if (segundo < raiz and (terceiro > segundo and terceiro < raiz)) {
        cout << "Necessita-se de rotacionamento LR.";
    } else if (segundo > raiz and (terceiro < segundo and terceiro > raiz)) {
        cout << "Necessita-se de rotacionamento RL.";
    } else {
        cout << "Incorreto, tente novamente.";
    }
}

int main()
{
    // Começo das funções referentes à atividade 1
    listaDuplamenteEncadeada* cabeca = nullptr;
    inserirFila(cabeca, 10);
    inserirFila(cabeca, 20);
    inserirFila(cabeca, 30);
    exibirFila(cabeca);
    removerFila(cabeca);
    exibirFila(cabeca);
    
    listaDuplamenteEncadeada* topo = nullptr;
    inserirPilha(topo, 10);
    inserirPilha(topo, 20);
    inserirPilha(topo, 30);
    exibirPilha(topo);
    removerPilha(topo);
    exibirPilha(topo);
    // Fim das funções referentes à atividade 1

    atividadeTres();

    return 0;
}
