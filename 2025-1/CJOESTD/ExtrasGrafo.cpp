// Algoritmo de Tarjan (encontra componentes fortemente conexos em grafos direcionados)
/* #include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

namespace TarjanSCC {
    std::vector<std::vector<int>> adj;
    std::vector<int> discoveryTime;
    std::vector<int> lowLink;
    std::vector<bool> onStack;
    std::stack<int> s;
    int time;
    int sccCount;

    std::vector<std::vector<int>> sccs;

    void findSCCsDFS(int u) {
        discoveryTime[u] = lowLink[u] = time++;
        s.push(u);
        onStack[u] = true;

        for (int v : adj[u]) {
            if (discoveryTime[v] == -1) {
                findSCCsDFS(v);
                lowLink[u] = std::min(lowLink[u], lowLink[v]);
            } else if (onStack[v]) {
                lowLink[u] = std::min(lowLink[u], discoveryTime[v]);
            }
        }

        if (lowLink[u] == discoveryTime[u]) {
            std::vector<int> currentSCC;
            sccCount++;
            int node;
            do {
                node = s.top();
                s.pop();
                onStack[node] = false;
                currentSCC.push_back(node);
            } while (node != u);
            sccs.push_back(currentSCC);
        }
    }

    void runTarjan(int numVertices) {
        adj.assign(numVertices, std::vector<int>());
        discoveryTime.assign(numVertices, -1);
        lowLink.assign(numVertices, -1);
        onStack.assign(numVertices, false);
        time = 0;
        sccCount = 0;
        sccs.clear();

        for (int i = 0; i < numVertices; ++i) {
            if (discoveryTime[i] == -1) {
                findSCCsDFS(i);
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    int getSCCCount() {
        return sccCount;
    }

    const std::vector<std::vector<int>>& getSCCs() {
        return sccs;
    }
} // namespace TarjanSCC

int main() {
    int numVertices = 8;
  
    TarjanSCC::runTarjan(numVertices);

    TarjanSCC::addEdge(0, 1);
    TarjanSCC::addEdge(1, 2);
    TarjanSCC::addEdge(2, 0);

    TarjanSCC::addEdge(3, 4);
    TarjanSCC::addEdge(4, 5);
    TarjanSCC::addEdge(5, 3);

    TarjanSCC::addEdge(2, 3);
    TarjanSCC::addEdge(5, 6);

    TarjanSCC::addEdge(6, 7);
    TarjanSCC::addEdge(7, 6);

    std::cout << "---------------------------------" << std::endl;
    std::cout << "Exemplo 1: Grafo com 3 CFCs esperadas." << std::endl;
    std::cout << "---------------------------------" << std::endl;

    TarjanSCC::runTarjan(numVertices);
    TarjanSCC::addEdge(0, 1);
    TarjanSCC::addEdge(1, 2);
    TarjanSCC::addEdge(2, 0);
    TarjanSCC::addEdge(2, 3);
    TarjanSCC::addEdge(3, 4);
    TarjanSCC::addEdge(4, 5);
    TarjanSCC::addEdge(5, 3);
    TarjanSCC::addEdge(5, 6);
    TarjanSCC::addEdge(6, 7);
    TarjanSCC::addEdge(7, 6);

    std::cout << "\n--- Exemplo de Uso ---" << std::endl;
    int V = 8;
    TarjanSCC::adj.assign(V, std::vector<int>());
    TarjanSCC::addEdge(0, 1);
    TarjanSCC::addEdge(1, 2);
    TarjanSCC::addEdge(2, 0); 
    TarjanSCC::addEdge(2, 3); 
    TarjanSCC::addEdge(3, 4);
    TarjanSCC::addEdge(4, 5);
    TarjanSCC::addEdge(5, 3); 
    TarjanSCC::addEdge(5, 6); 
    TarjanSCC::addEdge(6, 7);
    TarjanSCC::addEdge(7, 6); 

    TarjanSCC::runTarjan(V);

    std::cout << "Numero de Componentes Fortemente Conectadas (CFCs): " << TarjanSCC::getSCCCount() << std::endl;
    std::cout << "CFCs encontradas:" << std::endl;
    int cfc_idx = 1;
    for (const auto& scc : TarjanSCC::getSCCs()) {
        std::cout << "CFC " << cfc_idx++ << ": { ";
        for (int node : scc) {
            std::cout << node << " ";
        }
        std::cout << "}" << std::endl;
    }

    std::cout << "\n--- Segundo Exemplo (Grafo Linear) ---" << std::endl;
    V = 4;
    TarjanSCC::adj.assign(V, std::vector<int>());
    TarjanSCC::addEdge(0, 1);
    TarjanSCC::addEdge(1, 2);
    TarjanSCC::addEdge(2, 3);

    TarjanSCC::runTarjan(V);
    std::cout << "Numero de Componentes Fortemente Conectadas (CFCs): " << TarjanSCC::getSCCCount() << std::endl;
    std::cout << "CFCs encontradas:" << std::endl;
    cfc_idx = 1;
    for (const auto& scc : TarjanSCC::getSCCs()) {
        std::cout << "CFC " << cfc_idx++ << ": { ";
        for (int node : scc) {
            std::cout << node << " ";
        }
        std::cout << "}" << std::endl;
    }

    std::cout << "\n--- Terceiro Exemplo (Grafo com um grande ciclo) ---" << std::endl;
    V = 5;
    TarjanSCC::adj.assign(V, std::vector<int>());
    TarjanSCC::addEdge(0, 1);
    TarjanSCC::addEdge(1, 2);
    TarjanSCC::addEdge(2, 3);
    TarjanSCC::addEdge(3, 4);
    TarjanSCC::addEdge(4, 0);

    TarjanSCC::runTarjan(V);
    std::cout << "Numero de Componentes Fortemente Conectadas (CFCs): " << TarjanSCC::getSCCCount() << std::endl;
    std::cout << "CFCs encontradas:" << std::endl;
    cfc_idx = 1;
    for (const auto& scc : TarjanSCC::getSCCs()) {
        std::cout << "CFC " << cfc_idx++ << ": { ";
        for (int node : scc) {
            std::cout << node << " ";
        }
        std::cout << "}" << std::endl;
    }

    return 0;
} */

// Algoritmo de Kosaraju (mesma função que o de Tarjan)
/* #include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

namespace KosarajuSCC {
    std::vector<std::vector<int>> adj;     
    std::vector<std::vector<int>> revAdj; 
    std::vector<bool> visited;             
    std::stack<int> orderStack;           
    std::vector<std::vector<int>> sccs;
    int sccCount;                         

    void dfs1(int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs1(v);
            }
        }
        orderStack.push(u);
    }

    void dfs2(int u, std::vector<int>& currentSCC) {
        visited[u] = true;
        currentSCC.push_back(u);
        for (int v : revAdj[u]) {
            if (!visited[v]) {
                dfs2(v, currentSCC);
            }
        }
    }

    void runKosaraju(int numVertices) {
        adj.assign(numVertices, std::vector<int>());
        revAdj.assign(numVertices, std::vector<int>());
 
        while (!orderStack.empty()) {
            orderStack.pop();
        }
        sccs.clear();
        sccCount = 0;
 
        visited.assign(numVertices, false); 

        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i]) {
                dfs1(i);
            }
        }

        visited.assign(numVertices, false); 

        while (!orderStack.empty()) {
            int u = orderStack.top();
            orderStack.pop();

            if (!visited[u]) {
                std::vector<int> currentSCC;
                dfs2(u, currentSCC);
                sccs.push_back(currentSCC);
                sccCount++;
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    int getSCCCount() {
        return sccCount;
    }

    const std::vector<std::vector<int>>& getSCCs() {
        return sccs;
    }
} // namespace KosarajuSCC

int main() {
    int numVertices;

    std::cout << "--- Exemplo de Uso do Kosaraju (Similar ao Exemplo do Tarjan) ---" << std::endl;
    numVertices = 8;
    
    KosarajuSCC::adj.assign(numVertices, std::vector<int>());
    KosarajuSCC::revAdj.assign(numVertices, std::vector<int>());

    KosarajuSCC::addEdge(0, 1);
    KosarajuSCC::addEdge(1, 2);
    KosarajuSCC::addEdge(2, 0);

    KosarajuSCC::addEdge(2, 3);

    KosarajuSCC::addEdge(3, 4);
    KosarajuSCC::addEdge(4, 5);
    KosarajuSCC::addEdge(5, 3);

    KosarajuSCC::addEdge(5, 6);

    KosarajuSCC::addEdge(6, 7);
    KosarajuSCC::addEdge(7, 6);

    KosarajuSCC::runKosaraju(numVertices);

    std::cout << "Numero de Componentes Fortemente Conectadas (CFCs): " << KosarajuSCC::getSCCCount() << std::endl;
    std::cout << "CFCs encontradas:" << std::endl;
    int cfc_idx = 1;
    for (const auto& scc : KosarajuSCC::getSCCs()) {
        std::cout << "CFC " << cfc_idx++ << ": { ";
        for (int node : scc) {
            std::cout << node << " ";
        }
        std::cout << "}" << std::endl;
    }

    std::cout << "\n--- Segundo Exemplo (Grafo Linear) ---" << std::endl;
    numVertices = 4;
    KosarajuSCC::adj.assign(numVertices, std::vector<int>());
    KosarajuSCC::revAdj.assign(numVertices, std::vector<int>());
    KosarajuSCC::addEdge(0, 1);
    KosarajuSCC::addEdge(1, 2);
    KosarajuSCC::addEdge(2, 3);

    KosarajuSCC::runKosaraju(numVertices);
    std::cout << "Numero de Componentes Fortemente Conectadas (CFCs): " << KosarajuSCC::getSCCCount() << std::endl;
    std::cout << "CFCs encontradas:" << std::endl;
    cfc_idx = 1;
    for (const auto& scc : KosarajuSCC::getSCCs()) {
        std::cout << "CFC " << cfc_idx++ << ": { ";
        for (int node : scc) {
            std::cout << node << " ";
        }
        std::cout << "}" << std::endl;
    }

    std::cout << "\n--- Terceiro Exemplo (Grafo com um grande ciclo) ---" << std::endl;
    numVertices = 5;
    KosarajuSCC::adj.assign(numVertices, std::vector<int>());
    KosarajuSCC::revAdj.assign(numVertices, std::vector<int>());
    KosarajuSCC::addEdge(0, 1);
    KosarajuSCC::addEdge(1, 2);
    KosarajuSCC::addEdge(2, 3);
    KosarajuSCC::addEdge(3, 4);
    KosarajuSCC::addEdge(4, 0);

    KosarajuSCC::runKosaraju(numVertices);
    std::cout << "Numero de Componentes Fortemente Conectadas (CFCs): " << KosarajuSCC::getSCCCount() << std::endl;
    std::cout << "CFCs encontradas:" << std::endl;
    cfc_idx = 1;
    for (const auto& scc : KosarajuSCC::getSCCs()) {
        std::cout << "CFC " << cfc_idx++ << ": { ";
        for (int node : scc) {
            std::cout << node << " ";
        }
        std::cout << "}" << std::endl;
    }

    return 0;
} */

// Algoritmo de Prim (encontra a árvore geradora mínima em um grafo ponderado e não direcionado)
/* #include <iostream>
#include <vector>
#include <queue>   // Para std::priority_queue
#include <limits>  // Para std::numeric_limits

// Usando um namespace para organizar o código do algoritmo
namespace PrimMST {

    // Representação do grafo: lista de adjacências para arestas ponderadas
    // pair<int, int> -> {peso, vizinho}
    std::vector<std::vector<std::pair<int, int>>> adj;

    // Vetores de controle do algoritmo de Prim
    std::vector<int> minWeight;  // menor peso para conectar à MST
    std::vector<int> parent;     // pai na MST (para reconstruir a MST)
    std::vector<bool> inMST;     // indica se o vértice já está na MST

    long long totalMSTWeight;    // Peso total da MST
    std::vector<std::pair<int, int>> mstEdges; // Arestas que formam a MST

    void runPrim(int numVertices, int startVertex = 0) {
        // Redimensiona e inicializa as estruturas de dados
        adj.assign(numVertices, std::vector<std::pair<int, int>>());
        minWeight.assign(numVertices, std::numeric_limits<int>::max()); // Inicializa com infinito
        parent.assign(numVertices, -1); // -1 indica nenhum pai
        inMST.assign(numVertices, false); // Nenhum vértice na MST inicialmente

        totalMSTWeight = 0;
        mstEdges.clear();

        // Fila de prioridade: pair<peso, vértice>
        // Usamos std::greater para que seja um min-heap (menor peso tem maior prioridade)
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>> pq;

        // Começa com o vértice inicial
        minWeight[startVertex] = 0;
        pq.push({0, startVertex}); // Adiciona {peso 0, vértice inicial} à fila de prioridade

        // Loop principal: executa V-1 vezes para adicionar V-1 arestas
        // Ou, mais robusto, enquanto a fila de prioridade não estiver vazia
        // e não tenhamos visitado todos os vértices
        int edgesCount = 0;
        while (!pq.empty() && edgesCount < numVertices) {
            int u_weight = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Se o vértice já está na MST, ou se já encontramos uma aresta de menor peso
            // para ele que já foi processada, ignore.
            // Isso acontece porque a PQ pode conter entradas desatualizadas para um vértice.
            if (inMST[u]) {
                continue;
            }

            // Adiciona o vértice 'u' à MST
            inMST[u] = true;
            totalMSTWeight += u_weight; // Adiciona o peso da aresta que trouxe 'u' para a MST
            if (parent[u] != -1) { // Se não for o vértice inicial
                mstEdges.push_back({parent[u], u});
            }
            edgesCount++; // Incrementa o contador de vértices na MST ou arestas adicionadas

            // Explora os vizinhos de 'u'
            for (auto& edge : adj[u]) {
                int v_weight = edge.first; // Peso da aresta (u, v)
                int v = edge.second;       // Vértice vizinho 'v'

                // Se 'v' ainda não está na MST e a aresta (u, v)
                // oferece um caminho de menor peso para 'v'
                if (!inMST[v] && v_weight < minWeight[v]) {
                    minWeight[v] = v_weight;
                    parent[v] = u;
                    pq.push({minWeight[v], v}); // Adiciona 'v' à fila de prioridade
                }
            }
        }
    }

    // Função para adicionar uma aresta (não direcionada)
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({weight, v});
        adj[v].push_back({weight, u}); // Para grafo não direcionado
    }

    // Retorna o peso total da MST
    long long getMSTWeight() {
        return totalMSTWeight;
    }

    // Retorna as arestas que formam a MST
    const std::vector<std::pair<int, int>>& getMSTEdges() {
        return mstEdges;
    }

} // namespace PrimMST

int main() {
    int numVertices;

    std::cout << "--- Exemplo de Uso do Algoritmo de Prim ---" << std::endl;
    numVertices = 7; // Exemplo de um grafo com 7 vértices

    // Para que o algoritmo funcione corretamente, é necessário inicializar o grafo
    // e depois adicionar as arestas ANTES de chamar runPrim.
    // As estruturas adj, minWeight, parent, inMST serão redimensionadas em runPrim.

    // Apenas inicializa as listas de adjacência antes de adicionar as arestas.
    PrimMST::adj.assign(numVertices, std::vector<std::pair<int, int>>());

    // Adiciona as arestas (peso, u, v)
    PrimMST::addEdge(0, 1, 7);
    PrimMST::addEdge(0, 3, 5);
    PrimMST::addEdge(1, 2, 8);
    PrimST::addEdge(1, 3, 9);
    PrimMST::addEdge(1, 4, 7);
    PrimMST::addEdge(2, 4, 5);
    PrimMST::addEdge(3, 4, 15);
    PrimMST::addEdge(3, 5, 6);
    PrimMST::addEdge(4, 5, 8);
    PrimMST::addEdge(4, 6, 9);
    PrimMST::addEdge(5, 6, 11);

    // Executa o algoritmo de Prim a partir do vértice 0
    PrimMST::runPrim(numVertices, 0);

    std::cout << "Peso total da MST: " << PrimMST::getMSTWeight() << std::endl;
    std::cout << "Arestas na MST:" << std::endl;
    for (const auto& edge : PrimMST::getMSTEdges()) {
        std::cout << "(" << edge.first << ", " << edge.second << ")" << std::endl;
    }

    std::cout << "\n--- Segundo Exemplo (Grafo menor) ---" << std::endl;
    numVertices = 4;
    PrimMST::adj.assign(numVertices, std::vector<std::pair<int, int>>());
    PrimMST::addEdge(0, 1, 10);
    PrimMST::addEdge(0, 2, 6);
    PrimMST::addEdge(0, 3, 5);
    PrimMST::addEdge(1, 3, 15);
    PrimMST::addEdge(2, 3, 4);

    PrimMST::runPrim(numVertices, 0);
    std::cout << "Peso total da MST: " << PrimMST::getMSTWeight() << std::endl;
    std::cout << "Arestas na MST:" << std::endl;
    for (const auto& edge : PrimMST::getMSTEdges()) {
        std::cout << "(" << edge.first << ", " << edge.second << ")" << std::endl;
    }

    return 0;
} */

// Algoritmo de Kruskal (mesma função que o de Prim)
/* #include <iostream>
#include <vector>
#include <algorithm> // Para std::sort
#include <numeric>   // Para std::iota

// Estrutura para representar uma aresta
struct Edge {
    int u, v, weight;

    // Operador para ordenar as arestas por peso
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Usando um namespace para organizar o código do algoritmo
namespace KruskalMST {

    std::vector<Edge> edges; // Todas as arestas do grafo

    // Implementação da estrutura Union-Find (Disjoint Set Union)
    std::vector<int> parent;
    std::vector<int> sz; // Para união por tamanho/rank

    // Inicializa a estrutura Union-Find
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    // Encontra o representante do conjunto ao qual 'v' pertence (com compressão de caminho)
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]); // Compressão de caminho
    }

    // Une dois conjuntos (com união por tamanho/rank)
    bool unite_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) { // Se não estiverem no mesmo conjunto (não forma ciclo)
            if (sz[a] < sz[b])
                std::swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            return true; // União bem-sucedida
        }
        return false; // Já estavam no mesmo conjunto (formaria ciclo)
    }

    long long totalMSTWeight;    // Peso total da MST
    std::vector<std::pair<int, int>> mstEdges; // Arestas que formam a MST

    void runKruskal(int numVertices) {
        // Inicializa as estruturas do Union-Find
        parent.assign(numVertices, 0); // O tamanho será definido por make_set
        std::iota(parent.begin(), parent.end(), 0); // parent[i] = i para todos i
        sz.assign(numVertices, 1); // Todos os conjuntos começam com tamanho 1

        // Alternativamente, podemos fazer:
        // parent.resize(numVertices);
        // sz.resize(numVertices);
        // for (int i = 0; i < numVertices; ++i) {
        //     make_set(i);
        // }

        totalMSTWeight = 0;
        mstEdges.clear();

        // 1. Ordena todas as arestas por peso
        std::sort(edges.begin(), edges.end());

        // 2. Itera sobre as arestas ordenadas
        int edgesInMST = 0;
        for (const auto& edge : edges) {
            // Verifica se adicionar esta aresta forma um ciclo
            if (unite_sets(edge.u, edge.v)) {
                // Se não forma ciclo, adiciona a aresta à MST
                totalMSTWeight += edge.weight;
                mstEdges.push_back({edge.u, edge.v});
                edgesInMST++;

                // Otimização: Se já adicionamos V-1 arestas, a MST está completa
                if (edgesInMST == numVertices - 1) {
                    break;
                }
            }
        }
        // Limpa as arestas para o próximo uso (se houver múltiplos testes)
        edges.clear();
    }

    // Função para adicionar uma aresta (não direcionada) ao grafo
    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    // Retorna o peso total da MST
    long long getMSTWeight() {
        return totalMSTWeight;
    }

    // Retorna as arestas que formam a MST
    const std::vector<std::pair<int, int>>& getMSTEdges() {
        return mstEdges;
    }

} // namespace KruskalMST

int main() {
    int numVertices;

    std::cout << "--- Exemplo de Uso do Algoritmo de Kruskal ---" << std::endl;
    numVertices = 7; // Exemplo de um grafo com 7 vértices

    // As arestas devem ser adicionadas ANTES de chamar runKruskal.
    // KruskalMST::edges será preenchido aqui.

    KruskalMST::addEdge(0, 1, 7);
    KruskalMST::addEdge(0, 3, 5);
    KruskalMST::addEdge(1, 2, 8);
    KruskalMST::addEdge(1, 3, 9);
    KruskalMST::addEdge(1, 4, 7);
    KruskalMST::addEdge(2, 4, 5);
    KruskalMST::addEdge(3, 4, 15);
    KruskalMST::addEdge(3, 5, 6);
    KruskalMST::addEdge(4, 5, 8);
    KruskalMST::addEdge(4, 6, 9);
    KruskalMST::addEdge(5, 6, 11);

    // Executa o algoritmo de Kruskal
    KruskalMST::runKruskal(numVertices);

    std::cout << "Peso total da MST: " << KruskalMST::getMSTWeight() << std::endl;
    std::cout << "Arestas na MST:" << std::endl;
    for (const auto& edge : KruskalMST::getMSTEdges()) {
        std::cout << "(" << edge.first << ", " << edge.second << ")" << std::endl;
    }

    std::cout << "\n--- Segundo Exemplo (Grafo menor) ---" << std::endl;
    numVertices = 4;
    KruskalMST::addEdge(0, 1, 10);
    KruskalMST::addEdge(0, 2, 6);
    KruskalMST::addEdge(0, 3, 5);
    KruskalMST::addEdge(1, 3, 15);
    KruskalMST::addEdge(2, 3, 4);

    KruskalMST::runKruskal(numVertices);
    std::cout << "Peso total da MST: " << KruskalMST::getMSTWeight() << std::endl;
    std::cout << "Arestas na MST:" << std::endl;
    for (const auto& edge : KruskalMST::getMSTEdges()) {
        std::cout << "(" << edge.first << ", " << edge.second << ")" << std::endl;
    }

    return 0;
} */

// Algoritmo de Bellman-Ford (similar ao de Dijkstra, mas pode ser usado para casos com arestas negativas)
/* #include <iostream>
#include <vector>
#include <limits> // Para std::numeric_limits

// Estrutura para representar uma aresta
struct Edge {
    int u, v, weight;
};

// Usando um namespace para organizar o código do algoritmo
namespace BellmanFord {

    int numVertices;             // Número de vértices no grafo
    std::vector<Edge> edges;     // Lista de todas as arestas
    std::vector<long long> dist; // Distâncias mínimas da origem para cada vértice
    std::vector<int> parent;     // Para reconstruir o caminho

    // Constante para representar infinito (maior valor possível para long long / 2 para evitar overflow em somas)
    const long long INF = std::numeric_limits<long long>::max() / 2;

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    // Função principal do Bellman-Ford
    // Retorna true se não houver ciclos negativos alcançáveis da origem, false caso contrário
    bool runBellmanFord(int startVertex, int V) {
        numVertices = V;
        dist.assign(numVertices, INF); // Inicializa todas as distâncias como infinito
        parent.assign(numVertices, -1); // Inicializa todos os pais como -1

        dist[startVertex] = 0; // Distância da origem para si mesma é 0

        // Fase 1: Relaxar todas as arestas V-1 vezes
        // Esta fase garante que os caminhos mais curtos sejam encontrados,
        // assumindo que não há ciclos negativos.
        for (int i = 0; i < numVertices - 1; ++i) {
            bool relaxed_in_this_iteration = false;
            for (const auto& edge : edges) {
                int u = edge.u;
                int v = edge.v;
                int weight = edge.weight;

                // Relaxamento da aresta (u, v)
                // Verifica se u é alcançável (dist[u] != INF) para evitar overflow com INF + weight
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    relaxed_in_this_iteration = true;
                }
            }
            // Otimização: Se nenhuma aresta foi relaxada nesta iteração,
            // significa que todos os caminhos mais curtos já foram encontrados.
            // Podemos sair mais cedo.
            if (!relaxed_in_this_iteration && i > 0) { // i > 0 para garantir que startVertex foi processado
                break;
            }
        }

        // Fase 2: Detectar ciclos de peso negativo
        // Se qualquer distância ainda puder ser relaxada, um ciclo negativo existe.
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                // Ciclo de peso negativo detectado!
                // Neste ponto, `dist[v]` pode ser configurado para -INF ou algum valor
                // especial para indicar que é parte de um ciclo negativo,
                // ou simplesmente retornar false.
                std::cout << "Grafo contem um ciclo de peso negativo!" << std::endl;
                return false; // Indica a presença de um ciclo negativo
            }
        }
        
        return true; // Não foram encontrados ciclos negativos
    }

    // Função para obter a distância mínima para um vértice
    long long getMinDistance(int v) {
        return dist[v];
    }

    // Função para reconstruir e imprimir o caminho mínimo para um vértice
    void printPath(int v) {
        if (dist[v] == INF) {
            std::cout << "Nao alcancavel." << std::endl;
            return;
        }
        std::vector<int> path;
        int curr = v;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        std::reverse(path.begin(), path.end()); // Inverte para ter a ordem correta

        std::cout << "Caminho: ";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i];
            if (i < path.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    }

    // Limpa as arestas para um novo teste
    void clearEdges() {
        edges.clear();
    }

} // namespace BellmanFord

int main() {
    int numVertices;
    int startVertex;

    // --- Exemplo 1: Grafo sem ciclos negativos ---
    std::cout << "--- Exemplo 1: Grafo sem ciclos negativos ---" << std::endl;
    numVertices = 5;
    startVertex = 0;

    BellmanFord::clearEdges(); // Limpa arestas de testes anteriores
    BellmanFord::addEdge(0, 1, -1);
    BellmanFord::addEdge(0, 2, 4);
    BellmanFord::addEdge(1, 2, 3);
    BellmanFord::addEdge(1, 3, 2);
    BellmanFord::addEdge(1, 4, 2);
    BellmanFord::addEdge(3, 2, 5);
    BellmanFord::addEdge(3, 1, 1);
    BellmanFord::addEdge(4, 3, -3);

    if (BellmanFord::runBellmanFord(startVertex, numVertices)) {
        std::cout << "Distancias minimas a partir do vertice " << startVertex << ":" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Distancia para " << i << ": ";
            if (BellmanFord::getMinDistance(i) == BellmanFord::INF) {
                std::cout << "INF" << std::endl;
            } else {
                std::cout << BellmanFord::getMinDistance(i) << std::endl;
                BellmanFord::printPath(i);
            }
        }
    }
    std::cout << "\n------------------------------------------------\n" << std::endl;

    // --- Exemplo 2: Grafo com ciclo negativo ---
    std::cout << "--- Exemplo 2: Grafo com ciclo negativo ---" << std::endl;
    numVertices = 4;
    startVertex = 0;

    BellmanFord::clearEdges();
    BellmanFord::addEdge(0, 1, 1);
    BellmanFord::addEdge(1, 2, -1);
    BellmanFord::addEdge(2, 3, -1);
    BellmanFord::addEdge(3, 1, -1); // Ciclo negativo: 1 -> 2 -> 3 -> 1 (total -3)

    if (BellmanFord::runBellmanFord(startVertex, numVertices)) {
        std::cout << "Distancias minimas a partir do vertice " << startVertex << ":" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Distancia para " << i << ": ";
            if (BellmanFord::getMinDistance(i) == BellmanFord::INF) {
                std::cout << "INF" << std::endl;
            } else {
                std::cout << BellmanFord::getMinDistance(i) << std::endl;
                BellmanFord::printPath(i);
            }
        }
    } else {
        std::cout << "Nao e possivel encontrar caminhos minimos devido a ciclos negativos." << std::endl;
    }
    std::cout << "\n------------------------------------------------\n" << std::endl;

    // --- Exemplo 3: Grafo desconectado com ciclo negativo (inacessível da origem) ---
    std::cout << "--- Exemplo 3: Grafo desconectado com ciclo negativo (inacessivel da origem) ---" << std::endl;
    numVertices = 6;
    startVertex = 0;

    BellmanFord::clearEdges();
    BellmanFord::addEdge(0, 1, 10);
    BellmanFord::addEdge(1, 2, 20);
    BellmanFord::addEdge(2, 0, 5); // Ciclo positivo: 0 -> 1 -> 2 -> 0 (total 35)

    // Outro componente com ciclo negativo
    BellmanFord::addEdge(3, 4, -1);
    BellmanFord::addEdge(4, 5, -1);
    BellmanFord::addEdge(5, 3, -1); // Ciclo negativo: 3 -> 4 -> 5 -> 3 (total -3)

    if (BellmanFord::runBellmanFord(startVertex, numVertices)) {
        std::cout << "Distancias minimas a partir do vertice " << startVertex << ":" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Distancia para " << i << ": ";
            if (BellmanFord::getMinDistance(i) == BellmanFord::INF) {
                std::cout << "INF" << std::endl;
            } else {
                std::cout << BellmanFord::getMinDistance(i) << std::endl;
                BellmanFord::printPath(i);
            }
        }
    } else {
        std::cout << "Nao e possivel encontrar caminhos minimos devido a ciclos negativos." << std::endl;
    }
    std::cout << "\n------------------------------------------------\n" << std::endl;

    return 0;
} */

// Algoritmo de Floyd-Warshall (encontra os caminhos mais curtos entre todos pares de vértices, contanto que o grafo esteja direcionado e ponderado)
/* #include <iostream>
#include <vector>
#include <limits> // Para std::numeric_limits
#include <iomanip> // Para std::setw para formatação da saída

// Usando um namespace para organizar o código do algoritmo
namespace FloydWarshall {

    int numVertices;                      // Número de vértices no grafo
    std::vector<std::vector<long long>> dist; // Matriz de distâncias
    std::vector<std::vector<int>> next;   // Matriz para reconstruir caminhos

    // Constante para representar infinito (maior valor possível para long long / 2 para evitar overflow em somas)
    const long long INF = std::numeric_limits<long long>::max() / 2;

    // Inicializa as matrizes de adjacência e distâncias
    void initGraph(int V) {
        numVertices = V;
        dist.assign(numVertices, std::vector<long long>(numVertices, INF));
        next.assign(numVertices, std::vector<int>(numVertices, -1)); // -1 indica nenhum intermediário

        // Distância de um vértice para ele mesmo é 0
        for (int i = 0; i < numVertices; ++i) {
            dist[i][i] = 0;
            next[i][i] = i; // O próximo nó para i->i é i
        }
    }

    // Adiciona uma aresta ao grafo
    void addEdge(int u, int v, int weight) {
        // Para arestas múltiplas, pega sempre a de menor peso
        if (weight < dist[u][v]) {
            dist[u][v] = weight;
            next[u][v] = v; // O próximo nó de u para v é v (direto)
        }
    }

    // Executa o algoritmo de Floyd-Warshall
    // Retorna true se não houver ciclos negativos, false caso contrário
    bool runFloydWarshall() {
        // K é o vértice intermediário
        for (int k = 0; k < numVertices; ++k) {
            // I é o vértice de origem
            for (int i = 0; i < numVertices; ++i) {
                // J é o vértice de destino
                for (int j = 0; j < numVertices; ++j) {
                    // Evita overflow se dist[i][k] ou dist[k][j] for INF
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        if (dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                            next[i][j] = next[i][k]; // O próximo de i para j passa por k
                        }
                    }
                }
            }
        }

        // Detecta ciclos de peso negativo
        // Se a distância de um vértice para ele mesmo for negativa, há um ciclo negativo.
        for (int i = 0; i < numVertices; ++i) {
            if (dist[i][i] < 0) {
                std::cout << "Ciclo de peso negativo detectado envolvendo o vertice " << i << "!" << std::endl;
                return false; // Indica a presença de um ciclo negativo
            }
        }

        return true; // Não foram encontrados ciclos negativos
    }

    // Imprime a matriz de distâncias
    void printDistances() {
        std::cout << "Matriz de Distancias Mais Curtas:" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (dist[i][j] == INF) {
                    std::cout << std::setw(6) << "INF";
                } else {
                    std::cout << std::setw(6) << dist[i][j];
                }
            }
            std::cout << std::endl;
        }
    }

    // Imprime o caminho mais curto entre dois vértices
    void printPath(int u, int v) {
        if (dist[u][v] == INF) {
            std::cout << "Caminho de " << u << " para " << v << ": Nao alcancavel." << std::endl;
            return;
        }
        if (dist[u][v] < 0) { // Indica que faz parte de um ciclo negativo
             std::cout << "Caminho de " << u << " para " << v << ": Atinge um ciclo negativo, distancia indefinida." << std::endl;
             return;
        }

        std::cout << "Caminho de " << u << " para " << v << ": ";
        std::vector<int> path;
        int curr = u;
        while (curr != v) {
            if (curr == -1) { // Isso pode acontecer se houver um erro na lógica ou ciclo negativo
                std::cout << "Erro na reconstrucao do caminho ou ciclo negativo." << std::endl;
                return;
            }
            path.push_back(curr);
            curr = next[curr][v]; // Pega o próximo vértice no caminho para v
        }
        path.push_back(v); // Adiciona o destino

        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i];
            if (i < path.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    }

} // namespace FloydWarshall

int main() {
    int numVertices;

    // --- Exemplo 1: Grafo com pesos negativos, sem ciclo negativo ---
    std::cout << "--- Exemplo 1: Grafo com pesos negativos, sem ciclo negativo ---" << std::endl;
    numVertices = 4;
    FloydWarshall::initGraph(numVertices);

    FloydWarshall::addEdge(0, 1, 3);
    FloydWarshall::addEdge(0, 3, 7);
    FloydWarshall::addEdge(1, 0, 8);
    FloydWarshall::addEdge(1, 2, 2);
    FloydWarshall::addEdge(2, 0, 5);
    FloydWarshall::addEdge(2, 3, 1);
    FloydWarshall::addEdge(3, 0, 2);
    // Adicionando uma aresta de peso negativo
    FloydWarshall::addEdge(1, 3, -4); 

    if (FloydWarshall::runFloydWarshall()) {
        FloydWarshall::printDistances();
        std::cout << std::endl;
        FloydWarshall::printPath(0, 3);
        FloydWarshall::printPath(1, 0);
        FloydWarshall::printPath(0, 2);
    }
    std::cout << "\n------------------------------------------------\n" << std::endl;

    // --- Exemplo 2: Grafo com ciclo de peso negativo ---
    std::cout << "--- Exemplo 2: Grafo com ciclo de peso negativo ---" << std::endl;
    numVertices = 3;
    FloydWarshall::initGraph(numVertices);

    FloydWarshall::addEdge(0, 1, 1);
    FloydWarshall::addEdge(1, 2, -1);
    FloydWarshall::addEdge(2, 0, -1); // Ciclo negativo: 0 -> 1 -> 2 -> 0 (peso total -1)

    if (FloydWarshall::runFloydWarshall()) {
        // Isso não será impresso se um ciclo negativo for detectado
        FloydWarshall::printDistances();
    } else {
        std::cout << "Nao e possivel determinar os caminhos mais curtos devido a ciclos negativos." << std::endl;
    }
    std::cout << "\n------------------------------------------------\n" << std::endl;

    // --- Exemplo 3: Grafo com múltiplos caminhos para o mesmo destino ---
    std::cout << "--- Exemplo 3: Grafo com multiplos caminhos ---" << std::endl;
    numVertices = 4;
    FloydWarshall::initGraph(numVertices);

    FloydWarshall::addEdge(0, 1, 1);
    FloydWarshall::addEdge(0, 2, 5);
    FloydWarshall::addEdge(1, 2, 2); // Caminho 0->1->2 (custo 3) é menor que 0->2 (custo 5)
    FloydWarshall::addEdge(1, 3, 4);
    FloydWarshall::addEdge(2, 3, 1); // Caminho 0->1->2->3 (custo 4) é menor que 0->1->3 (custo 5)

    if (FloydWarshall::runFloydWarshall()) {
        FloydWarshall::printDistances();
        std::cout << std::endl;
        FloydWarshall::printPath(0, 3);
    }

    return 0;
} */

// Resolve o problema da mochila 0/1, representando-o como um grafo
#include <iostream>
#include <vector>
#include <algorithm> // Para std::max

// Estrutura para representar um item
struct Item {
    int weight;
    int value;
};

class KnapsackSolver {
private:
    int numItems;
    int capacity;
    std::vector<Item> items;
    std::vector<int> dp; // dp[w] = valor máximo para capacidade 'w'

public:
    // Construtor
    KnapsackSolver(int N, int W, const std::vector<Item>& item_list) 
        : numItems(N), capacity(W), items(item_list) {
        // Inicializa dp com zeros. dp[w] representa o valor máximo
        // que pode ser alcançado com capacidade 'w'.
        // No contexto de caminho mais longo, é como as distâncias sendo 0 inicialmente.
        dp.assign(capacity + 1, 0); 
    }

    // Resolve o Problema da Mochila 0/1
    // A cada iteração (para cada item), estamos essencialmente explorando
    // as "arestas" do nosso DAG e atualizando as "distâncias" (valores)
    int solve() {
        // Iteramos sobre cada item
        for (int i = 0; i < numItems; ++i) {
            int current_item_weight = items[i].weight;
            int current_item_value = items[i].value;

            // Iteramos sobre a capacidade da mochila, de trás para frente.
            // Isso garante que cada item seja considerado apenas uma vez (comportamento 0/1).
            // Se iterássemos da frente para trás, um item poderia ser "pegado" múltiplas vezes
            // na mesma iteração, o que seria o problema da mochila ilimitada.
            for (int w = capacity; w >= current_item_weight; --w) {
                // Opção 1: Não pegar o item 'i'
                // O valor é o mesmo de dp[w] de antes (como se a aresta tivesse peso 0)
                // dp[w] = dp[w]; (implicitamente)

                // Opção 2: Pegar o item 'i'
                // O valor é o valor do item atual + o valor máximo para a capacidade restante
                int value_if_taken = current_item_value + dp[w - current_item_weight];

                // Escolhe o máximo entre não pegar e pegar o item
                dp[w] = std::max(dp[w], value_if_taken);
            }
        }

        // Após processar todos os itens, o valor máximo para a capacidade total 'W'
        // estará no maior elemento de dp, ou em dp[capacity] se for alcançável.
        // Já que estamos buscando o máximo para qualquer capacidade até 'W',
        // podemos simplesmente encontrar o máximo em todo o array dp.
        int max_total_value = 0;
        for (int w = 0; w <= capacity; ++w) {
            max_total_value = std::max(max_total_value, dp[w]);
        }
        return max_total_value;
    }

    // Função para imprimir a matriz DP final (opcional, para visualização)
    void printDPTable() {
        std::cout << "Tabela DP (valores maximos para cada capacidade):" << std::endl;
        for (int w = 0; w <= capacity; ++w) {
            std::cout << "Capacidade " << w << ": " << dp[w] << std::endl;
        }
    }
};

int main() {
    // Exemplo 1: Exemplo clássico
    int N1 = 3; // Numero de itens
    int W1 = 5; // Capacidade da mochila
    std::vector<Item> items1 = {
        {2, 3}, // peso 2, valor 3
        {3, 4}, // peso 3, valor 4
        {4, 5}  // peso 4, valor 5
    };
    // Item (p, v)
    // Itens: (2,3), (3,4), (4,5)
    // Mochila: 5
    // Solucao esperada: Pegar (2,3) e (3,4) -> peso 5, valor 7.
    // Ou (4,5) -> peso 4, valor 5. Melhor eh 7.

    std::cout << "--- Exemplo 1: Mochila 0/1 ---" << std::endl;
    KnapsackSolver solver1(N1, W1, items1);
    int max_value1 = solver1.solve();
    std::cout << "Valor maximo que pode ser obtido: " << max_value1 << std::endl; // Esperado: 7
    solver1.printDPTable();
    std::cout << "\n----------------------------------------\n" << std::endl;

    // Exemplo 2: Outro cenário
    int N2 = 4;
    int W2 = 7;
    std::vector<Item> items2 = {
        {1, 1},
        {3, 4},
        {4, 5},
        {5, 7}
    };
    // Solucao esperada: Pegar (1,1) e (5,7) -> peso 6, valor 8.
    // Ou (3,4) e (4,5) -> peso 7, valor 9. Melhor eh 9.

    std::cout << "--- Exemplo 2: Mochila 0/1 ---" << std::endl;
    KnapsackSolver solver2(N2, W2, items2);
    int max_value2 = solver2.solve();
    std::cout << "Valor maximo que pode ser obtido: " << max_value2 << std::endl; // Esperado: 9
    solver2.printDPTable();
    std::cout << "\n----------------------------------------\n" << std::endl;

    // Exemplo 3: Item muito pesado
    int N3 = 2;
    int W3 = 3;
    std::vector<Item> items3 = {
        {4, 10}, // Nao cabe
        {2, 5}
    };
    // Solucao esperada: Pegar (2,5) -> peso 2, valor 5.

    std::cout << "--- Exemplo 3: Mochila 0/1 ---" << std::endl;
    KnapsackSolver solver3(N3, W3, items3);
    int max_value3 = solver3.solve();
    std::cout << "Valor maximo que pode ser obtido: " << max_value3 << std::endl; // Esperado: 5
    solver3.printDPTable();
    std::cout << "\n----------------------------------------\n" << std::endl;

    return 0;
}
