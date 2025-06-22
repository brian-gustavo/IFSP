// Exercício 1
/* #include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

struct Grafo {
    int numVertices;
    std::vector<std::vector<int>> adj;

    Grafo(int V) : numVertices(V) {
        adj.resize(V);
    }

    void adicionarAresta(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

std::vector<int> bfs(Grafo* grafo, int verticeInicial, int verticeDestino) {
    std::map<int, int> pai;
    std::vector<bool> visitado(grafo->numVertices, false);
    std::queue<int> q;

    q.push(verticeInicial);
    visitado[verticeInicial] = true;
    pai[verticeInicial] = -1;

    bool encontrado = false;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == verticeDestino) {
            encontrado = true;
            break;
        }

        for (int v : grafo->adj[u]) {
            if (!visitado[v]) {
                visitado[v] = true;
                pai[v] = u;
                q.push(v);
            }
        }
    }

    std::vector<int> caminho;
    if (encontrado) {
        int atual = verticeDestino;
        while (atual != -1) {
            caminho.push_back(atual);
            atual = pai[atual];
        }
        std::reverse(caminho.begin(), caminho.end());
    }
    return caminho;
}

int main() {
    Grafo* grafo = new Grafo(7);

    grafo->adicionarAresta(0, 1);
    grafo->adicionarAresta(0, 2);
    grafo->adicionarAresta(1, 3);
    grafo->adicionarAresta(2, 3);
    grafo->adicionarAresta(3, 4);
    grafo->adicionarAresta(4, 5);
    grafo->adicionarAresta(5, 6);
    grafo->adicionarAresta(0, 6);

    std::cout << "--- Teste 1: Caminho de 0 para 3 ---" << std::endl;
    std::vector<int> caminho1 = bfs(grafo, 0, 3);
    if (!caminho1.empty()) {
        std::cout << "Caminho mais curto de 0 para 3: ";
        for (size_t i = 0; i < caminho1.size(); ++i) {
            std::cout << caminho1[i];
            if (i < caminho1.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "Nao ha caminho de 0 para 3." << std::endl;
    }

    std::cout << "\n--- Teste 2: Caminho de 1 para 6 ---" << std::endl;
    std::vector<int> caminho2 = bfs(grafo, 1, 6);
    if (!caminho2.empty()) {
        std::cout << "Caminho mais curto de 1 para 6: ";
        for (size_t i = 0; i < caminho2.size(); ++i) {
            std::cout << caminho2[i];
            if (i < caminho2.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "Nao ha caminho de 1 para 6." << std::endl;
    }

    std::cout << "\n--- Teste 3: Caminho de 5 para 0 (sem caminho direto simples) ---" << std::endl;
    std::vector<int> caminho3 = bfs(grafo, 5, 0);
    if (!caminho3.empty()) {
        std::cout << "Caminho mais curto de 5 para 0: ";
        for (size_t i = 0; i < caminho3.size(); ++i) {
            std::cout << caminho3[i];
            if (i < caminho3.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "Nao ha caminho de 5 para 0." << std::endl;
    }

    delete grafo;

    return 0;
} */

// Exercício 2
/* #include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    const int TAMANHO_ARRAY = 1000;
    const int MAX_VALOR = 10000;

    std::vector<int> original_arr(TAMANHO_ARRAY);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, MAX_VALOR);

    for (int i = 0; i < TAMANHO_ARRAY; ++i) {
        original_arr[i] = distrib(gen);
    }

    std::vector<int> arr_selection_sort = original_arr;
    std::vector<int> arr_merge_sort = original_arr;

    std::cout << "Array Original (primeiros 20): [";
    for (int i = 0; i < std::min(20, TAMANHO_ARRAY); ++i) {
        std::cout << original_arr[i] << (i == std::min(20, TAMANHO_ARRAY) - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    std::cout << "\nSelection Sort:" << std::endl;
    auto start_selection = std::chrono::high_resolution_clock::now();
    selectionSort(arr_selection_sort.data(), TAMANHO_ARRAY);
    auto end_selection = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_selection = end_selection - start_selection;

    std::cout << "Array Ordenado (primeiros 20): [";
    for (int i = 0; i < std::min(20, TAMANHO_ARRAY); ++i) {
        std::cout << arr_selection_sort[i] << (i == std::min(20, TAMANHO_ARRAY) - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
    std::cout << "Tempo de execução: " << duration_selection.count() << " ms" << std::endl;

    std::cout << "\nMerge Sort:" << std::endl;
    auto start_merge = std::chrono::high_resolution_clock::now();
    mergeSort(arr_merge_sort.data(), 0, TAMANHO_ARRAY - 1);
    auto end_merge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_merge = end_merge - start_merge;

    std::cout << "Array Ordenado (primeiros 20): [";
    for (int i = 0; i < std::min(20, TAMANHO_ARRAY); ++i) {
        std::cout << arr_merge_sort[i] << (i == std::min(20, TAMANHO_ARRAY) - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
    std::cout << "Tempo de execução: " << duration_merge.count() << " ms" << std::endl;

    return 0;
} */

// Exercício 3
#include <iostream>
#include <vector>
#include <list>
#include <string>

class HashTable {
private:
    int capacity;
    std::vector<std::list<std::pair<std::string, int>>> table;

    int hashFunction(const std::string& key) {
        long long hash = 0;
        for (char c : key) {
            hash = (hash + static_cast<long long>(c));
        }
        return hash % capacity;
    }

public:
    HashTable(int cap) : capacity(cap) {
        table.resize(capacity);
    }

    void insert(const std::string& key, int value) {
        int index = hashFunction(key);

        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                std::cout << "Chave '" << key << "' atualizada." << std::endl;
                return;
            }
        }

        table[index].push_back({key, value});
        std::cout << "Chave '" << key << "' inserida no índice " << index << std::endl;
    }

    int search(const std::string& key) {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }

    void remove(const std::string& key) {
        int index = hashFunction(key);
        auto& bucket = table[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                std::cout << "Chave '" << key << "' removida do índice " << index << std::endl;
                return;
            }
        }
        std::cout << "Chave '" << key << "' nao encontrada para remocao." << std::endl;
    }

    void display() {
        std::cout << "\n--- Conteudo da Tabela Hash ---" << std::endl;
        for (int i = 0; i < capacity; ++i) {
            std::cout << "Balde " << i << ": ";
            if (table[i].empty()) {
                std::cout << "Vazio";
            } else {
                for (const auto& pair : table[i]) {
                    std::cout << "[" << pair.first << ": " << pair.second << "] ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "-------------------------------" << std::endl;
    }
};

int main() {
    HashTable myHashTable(10);

    std::cout << "--- Operacoes de Insercao ---" << std::endl;
    myHashTable.insert("apple", 10);
    myHashTable.insert("banana", 20);
    myHashTable.insert("cherry", 30);
    myHashTable.insert("grape", 40);
    myHashTable.insert("melon", 50);
    myHashTable.insert("lemon", 60);
    myHashTable.insert("apple", 15);

    myHashTable.display();

    std::cout << "\n--- Operacoes de Busca ---" << std::endl;
    std::string searchKey1 = "banana";
    int value1 = myHashTable.search(searchKey1);
    if (value1 != -1) {
        std::cout << "Valor de '" << searchKey1 << "': " << value1 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey1 << "' nao encontrada." << std::endl;
    }

    std::string searchKey2 = "grape";
    int value2 = myHashTable.search(searchKey2);
    if (value2 != -1) {
        std::cout << "Valor de '" << searchKey2 << "': " << value2 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey2 << "' nao encontrada." << std::endl;
    }

    std::string searchKey3 = "orange";
    int value3 = myHashTable.search(searchKey3);
    if (value3 != -1) {
        std::cout << "Valor de '" << searchKey3 << "': " << value3 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey3 << "' nao encontrada." << std::endl;
    }

    std::string searchKey4 = "apple";
    int value4 = myHashTable.search(searchKey4);
    if (value4 != -1) {
        std::cout << "Valor de '" << searchKey4 << "': " << value4 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey4 << "' nao encontrada." << std::endl;
    }


    myHashTable.display();

    std::cout << "\n--- Operacoes de Remocao ---" << std::endl;
    myHashTable.remove("banana");
    myHashTable.remove("grape");
    myHashTable.remove("kiwi");

    myHashTable.display();

    std::cout << "\n--- Busca apos remocao ---" << std::endl;
    std::string searchKey5 = "banana";
    int value5 = myHashTable.search(searchKey5);
    if (value5 != -1) {
        std::cout << "Valor de '" << searchKey5 << "': " << value5 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey5 << "' nao encontrada." << std::endl;
    }

    return 0;
}