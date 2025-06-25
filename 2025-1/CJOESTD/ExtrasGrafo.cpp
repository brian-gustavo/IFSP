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
