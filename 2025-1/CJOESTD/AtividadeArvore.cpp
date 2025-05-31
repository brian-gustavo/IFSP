#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Trecho fornecido pelo professor como parte da atividade
struct Node
{
    int valor;
    Node* esquerda;
    Node* direita;
};

Node* iniciarArvore()
{
    return nullptr;
}

void adicionarItem(Node*& raiz, int novoValor)
{
    if (raiz == nullptr) {
        raiz = new Node;
        raiz->valor = novoValor;
        raiz->esquerda = nullptr;
        raiz->direita = nullptr;
        cout << raiz->valor << " adicionado!" << endl;
    } else if (raiz->valor > novoValor) {
        adicionarItem(raiz->esquerda, novoValor);
    } else if (raiz->valor < novoValor) {
        adicionarItem(raiz->direita, novoValor);
    }
}

void pesquisaIterativa(Node* raiz, int ondeValor)
{
    while (raiz != nullptr && raiz->valor != ondeValor)
    {
        if (raiz->valor > ondeValor)
        {
            raiz = raiz->esquerda;
        }
        else
        {
            raiz = raiz->direita;
        }
    }

    if (raiz == nullptr)
    {
        cout << "Valor não encontrado!" << endl;  
        return;  
    }
    else
    {
        cout << "Valor encontrado!" << endl;
    }
}

int contadorNodes(Node* raiz)
{
    if (raiz == nullptr)
    {
        return 0;
    }
    else
    {
        return contadorNodes(raiz->esquerda) + contadorNodes(raiz->direita) + 1;
    }
}

// Desafio 1; anteriormente fornecido pelo professor
void exibicaoEmOrdem(Node* raiz)
{
    if (raiz == nullptr)
    {
        return;
    }
    exibicaoEmOrdem(raiz->esquerda);
    cout << raiz->valor << " ";
    exibicaoEmOrdem(raiz->direita);
}

// Desafio 2
void exibicaoReversa(Node* raiz)
{
    if (raiz == nullptr)
    {
        return;
    }

    stack<Node*> NodeStack;
    Node* atual = raiz;

    while (!NodeStack.empty() || atual != nullptr)
    {
        while (atual != nullptr)
        {
            NodeStack.push(atual);
            atual = atual->direita;
        }

        atual = NodeStack.top();
        NodeStack.pop();
        cout << atual->valor << " ";
        atual = atual->esquerda;
    }
}

// Desafio 3
void exibicaoPreOrdem(Node* raiz)
{
    if (raiz == nullptr)
    {
        return;
    }
    cout << raiz->valor << " ";
    exibicaoPreOrdem(raiz->esquerda);
    exibicaoPreOrdem(raiz->direita);
}

// Desafio 4
void exibicaoPosOrdem(Node* raiz)
{
    if (raiz == nullptr)
    {
        return;
    }
    exibicaoPosOrdem(raiz->esquerda);
    exibicaoPosOrdem(raiz->direita);
    cout << raiz->valor << " ";
}

// Desafio 5
void exibicaoLargura(Node* raiz)
{
    if (raiz == nullptr)
    {
        return;
    }

    queue<Node*> NodeQueue;
    NodeQueue.push(raiz);

    while(!NodeQueue.empty())
    {
        Node* atual = NodeQueue.front();
        NodeQueue.pop();
        cout << atual->valor << " ";

        if(atual->esquerda != nullptr)
        {
            NodeQueue.push(atual->esquerda);
        }
        if(atual->direita != nullptr)
        {
            NodeQueue.push(atual->direita);
        }
    }
}

// Trecho fornecido pelo professor como parte da atividade (segundo slide)
void remocaoRecursiva(Node*& raiz, int valor)
{
    if (raiz == nullptr)
    {
        return;
    } else if (valor < raiz->valor) {
        remocaoRecursiva(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        remocaoRecursiva(raiz->direita, valor);
    }
    else
    {
        if (raiz->esquerda == nullptr && raiz->direita == nullptr)
        {
            delete raiz;
            raiz = nullptr;
        } else if(raiz->esquerda == nullptr) {
            Node* temp = raiz;
            raiz = raiz->direita;
            delete temp;
        } else if(raiz->direita == nullptr) {
            Node* temp = raiz;
            raiz = raiz->esquerda;
            delete temp;
        }
        else
        {
            Node* temp = raiz->direita;
            while(temp->esquerda != nullptr)
            {
                temp = temp->esquerda;
            }
            raiz->valor = temp->valor;
            remocaoRecursiva(raiz->direita, temp->valor);
        }
    }
}

// Desafio 6 (segundo slide)
void remocaoIterativa(Node*& raiz, int valor)
{
    Node* pai = nullptr;
    Node* atual = raiz;

    while (atual != nullptr && atual->valor != valor)
    {
        pai = atual;
        if (valor < atual->valor)
        {
            atual = atual->esquerda;
        }
        else
        {
            atual = atual->direita;
        }
    }

    if (atual == nullptr)
    {
        cout << "Valor não encontrado!" << endl;
        return;
    }

    if (atual->esquerda == nullptr && atual->direita == nullptr)
    {
        if (atual == raiz)
        {
            raiz = nullptr;
        }
        else if (pai->esquerda == atual)
        {
            pai->esquerda = nullptr;
        }
        else
        {
            pai->direita = nullptr;
        }
        delete atual;
    }
    
    else if (atual->esquerda == nullptr || atual->direita == nullptr)
    {
        Node* filho = (atual->esquerda != nullptr) ? atual->esquerda : atual->direita;

        if (atual == raiz)
        {
            raiz = filho;
        }
        else if (pai->esquerda == atual)
        {
            pai->esquerda = filho;
        }
        else
        {
            pai->direita = filho;
        }
        delete atual;
    }
    else
    {
        Node* sucessorPai = atual;
        Node* sucessor = atual->direita;

        while (sucessor->esquerda != nullptr)
        {
            sucessorPai = sucessor;
            sucessor = sucessor->esquerda;
        }

        atual->valor = sucessor->valor;

        if (sucessorPai->esquerda == sucessor)
        {
            sucessorPai->esquerda = sucessor->direita;
        }
        else
        {
            sucessorPai->direita = sucessor->direita;
        }
        delete sucessor;
    }
}

// Rotina principal para que sejam chamadas as subrotinas
int main()
{
    setlocale(LC_ALL, ".1252");

    Node* raiz = iniciarArvore();

    adicionarItem(raiz, 50);
    adicionarItem(raiz, 25);
    adicionarItem(raiz, 75);
    adicionarItem(raiz, 70);
    adicionarItem(raiz, 15);
    adicionarItem(raiz, 80);
    adicionarItem(raiz, 85);
    adicionarItem(raiz, 90);

    pesquisaIterativa(raiz, 70);
    pesquisaIterativa(raiz, 10);

    contadorNodes(raiz);
    cout << endl;

    cout << "Em ordem: ";
    exibicaoEmOrdem(raiz);
    cout << endl;
    cout << "Ordem reversa: ";
    exibicaoReversa(raiz);
    cout << endl;
    cout << "Pré-ordem: ";
    exibicaoPreOrdem(raiz);
    cout << endl;
    cout << "Pós-ordem: ";
    exibicaoPosOrdem(raiz);
    cout << endl;
    cout << "Exibição em largura: ";
    exibicaoLargura(raiz);
    cout << endl;
    cout << endl;

    cout << endl << "Removendo 50 recursivamente: ";
    remocaoRecursiva(raiz, 50);
    exibicaoPreOrdem(raiz);
    cout << endl << endl << "Removendo 85 iterativamente: ";
    remocaoIterativa(raiz, 85);
    exibicaoPreOrdem(raiz);
    cout << endl << endl;

    return 0;
}
