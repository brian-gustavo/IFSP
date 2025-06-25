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
