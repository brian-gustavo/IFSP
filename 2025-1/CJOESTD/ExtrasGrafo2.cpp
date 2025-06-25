// Busca A*
/* #include <iostream>
#include <vector>
#include <queue>
#include <map> // Para armazenar os custos g(n) e os predecessores
#include <cmath> // Para abs()

// Definição de um ponto (coordenadas)
struct Point {
    int x, y;

    bool operator<(const Point& other) const {
        // Necessário para usar Point como chave em std::map
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
};

// Estrutura para representar o estado na fila de prioridade
struct State {
    int f_cost; // g(n) + h(n)
    int g_cost; // Custo do início até o nó atual
    Point point;

    // Comparador para a priority_queue (min-heap)
    bool operator<(const State& other) const {
        return f_cost > other.f_cost; // Queremos o menor f_cost no topo
    }
};

// Função heurística (distância de Manhattan)
int heuristic(Point a, Point b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

// Direções possíveis (cima, baixo, esquerda, direita)
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

std::vector<Point> aStarSearch(Point start, Point goal, int rows, int cols, const std::vector<std::vector<int>>& grid) {
    // grid[r][c] == 0 significa célula livre, 1 significa obstáculo

    std::priority_queue<State> openSet;
    std::map<Point, int> g_costs; // Custo do início até cada ponto
    std::map<Point, Point> cameFrom; // Para reconstruir o caminho

    g_costs[start] = 0;
    openSet.push({heuristic(start, goal), 0, start});

    while (!openSet.empty()) {
        State current = openSet.top();
        openSet.pop();

        Point current_point = current.point;

        if (current_point == goal) {
            // Caminho encontrado, reconstruir e retornar
            std::vector<Point> path;
            Point temp = goal;
            while (temp != start) {
                path.push_back(temp);
                temp = cameFrom[temp];
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return path;
        }

        // Explora vizinhos
        for (int i = 0; i < 4; ++i) {
            Point neighbor = {current_point.x + dx[i], current_point.y + dy[i]};

            // Verifica limites da grade
            if (neighbor.x < 0 || neighbor.x >= rows || neighbor.y < 0 || neighbor.y >= cols) {
                continue;
            }
            // Verifica obstáculos
            if (grid[neighbor.x][neighbor.y] == 1) {
                continue;
            }

            // Custo da origem para o vizinho (assumindo custo 1 por movimento)
            int tentative_g_cost = g_costs[current_point] + 1;

            // Se o novo custo g(n) é menor OU se o vizinho ainda não foi visitado
            if (g_costs.find(neighbor) == g_costs.end() || tentative_g_cost < g_costs[neighbor]) {
                g_costs[neighbor] = tentative_g_cost;
                cameFrom[neighbor] = current_point;
                int f_cost = tentative_g_cost + heuristic(neighbor, goal);
                openSet.push({f_cost, tentative_g_cost, neighbor});
            }
        }
    }

    return {}; // Caminho não encontrado
}

int main() {
    // Exemplo de um grid: 0 = livre, 1 = obstáculo
    // 5x5 grid
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    Point start = {0, 0};
    Point goal = {4, 4};
    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<Point> path = aStarSearch(start, goal, rows, cols, grid);

    if (!path.empty()) {
        std::cout << "Caminho encontrado:" << std::endl;
        for (const auto& p : path) {
            std::cout << "(" << p.x << ", " << p.y << ") -> ";
        }
        std::cout << "Fim" << std::endl;
    } else {
        std::cout << "Caminho não encontrado!" << std::endl;
    }

    // Exemplo com obstáculo bloqueando o caminho
    grid[3][4] = 1; // Coloca um obstáculo no caminho anterior
    grid[4][3] = 1; // E outro

    std::cout << "\nTentando novamente com mais obstáculos:" << std::endl;
    path = aStarSearch(start, goal, rows, cols, grid);

    if (!path.empty()) {
        std::cout << "Caminho encontrado:" << std::endl;
        for (const auto& p : path) {
            std::cout << "(" << p.x << ", " << p.y << ") -> ";
        }
        std::cout << "Fim" << std::endl;
    } else {
        std::cout << "Caminho não encontrado!" << std::endl;
    }

    return 0;
} */

// Busca IDDFS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // Para std::reverse

// Definição de um ponto (coordenadas)
struct Point {
    int x, y;

    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
};

// Direções possíveis (cima, baixo, esquerda, direita)
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

// Função auxiliar para DFS com limite de profundidade
// Retorna true se o objetivo for encontrado dentro do limite
// O 'path' é preenchido recursivamente de trás para frente
bool dfs_limited(Point current_point, Point goal, int depth_limit, int current_depth,
                 int rows, int cols, const std::vector<std::vector<int>>& grid,
                 std::map<Point, bool>& visited, std::vector<Point>& path) {

    // Se a profundidade atual exceder o limite, pare a busca neste caminho
    if (current_depth > depth_limit) {
        return false;
    }

    // Se o ponto atual é o objetivo, adiciona ao caminho e retorna verdadeiro
    if (current_point == goal) {
        path.push_back(current_point);
        return true;
    }

    // Marca o ponto atual como visitado para evitar ciclos na busca atual
    visited[current_point] = true;

    // Explora vizinhos
    for (int i = 0; i < 4; ++i) {
        Point neighbor = {current_point.x + dx[i], current_point.y + dy[i]};

        // Verifica limites da grade
        if (neighbor.x < 0 || neighbor.x >= rows || neighbor.y < 0 || neighbor.y >= cols) {
            continue;
        }
        // Verifica obstáculos
        if (grid[neighbor.x][neighbor.y] == 1) {
            continue;
        }
        // Verifica se o vizinho já foi visitado NESTA iteração DFS
        if (visited[neighbor]) {
            continue;
        }

        // Chamada recursiva para o vizinho com profundidade aumentada
        if (dfs_limited(neighbor, goal, depth_limit, current_depth + 1, rows, cols, grid, visited, path)) {
            // Se o objetivo foi encontrado por um caminho abaixo deste vizinho,
            // adiciona o ponto atual ao caminho e propaga o sucesso
            path.push_back(current_point);
            return true;
        }
    }

    // Se o objetivo não foi encontrado a partir deste nó, desmarca como visitado
    // para permitir que futuras iterações (com profundidades maiores) o visitem.
    visited[current_point] = false;
    return false;
}

// Função principal de Busca em Profundidade Iterativa (IDDFS)
std::vector<Point> iterativeDeepeningDFS(Point start, Point goal, int rows, int cols, const std::vector<std::vector<int>>& grid) {
    // Itera através dos limites de profundidade
    // Um limite máximo "razoável" pode ser a área total do grid, para garantir que todos os caminhos sejam explorados
    // ou um limite maior se o grafo puder ter ciclos longos.
    int max_depth_limit = rows * cols;

    for (int depth_limit = 0; depth_limit <= max_depth_limit; ++depth_limit) {
        std::map<Point, bool> visited; // Resetar 'visitados' para cada nova iteração de DFS
        std::vector<Point> path;
        
        std::cout << "Tentando com profundidade limite: " << depth_limit << std::endl;

        if (dfs_limited(start, goal, depth_limit, 0, rows, cols, grid, visited, path)) {
            // Se o objetivo foi encontrado, o caminho está na ordem inversa, então inverte e retorna
            std::reverse(path.begin(), path.end());
            return path;
        }
    }

    return {}; // Caminho não encontrado após esgotar todos os limites de profundidade
}

int main() {
    // Exemplo de um grid: 0 = livre, 1 = obstáculo
    // 5x5 grid
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    Point start = {0, 0};
    Point goal = {4, 4};
    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<Point> path = iterativeDeepeningDFS(start, goal, rows, cols, grid);

    if (!path.empty()) {
        std::cout << "\nCaminho encontrado:" << std::endl;
        for (const auto& p : path) {
            std::cout << "(" << p.x << ", " << p.y << ") -> ";
        }
        std::cout << "Fim" << std::endl;
    } else {
        std::cout << "\nCaminho não encontrado!" << std::endl;
    }

    // Exemplo com obstáculo bloqueando o caminho
    grid[3][4] = 1; // Coloca um obstáculo no caminho anterior
    grid[4][3] = 1; // E outro

    std::cout << "\n--- Tentando novamente com mais obstáculos ---" << std::endl;
    path = iterativeDeepeningDFS(start, goal, rows, cols, grid);

    if (!path.empty()) {
        std::cout << "\nCaminho encontrado:" << std::endl;
        for (const auto& p : path) {
            std::cout << "(" << p.x << ", " << p.y << ") -> ";
        }
        std::cout << "Fim" << std::endl;
    } else {
        std::cout << "\nCaminho não encontrado!" << std::endl;
    }

    return 0;
}
