// Merge Sort
/* #include <iostream>
#include <vector>
#include <algorithm> // Para std::copy

// Função para mesclar dois subarranjos de forma decrescente
void mergeDecrescente(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Criar vetores temporários
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Copiar dados para os vetores temporários L[] e R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Mesclar os vetores temporários de volta em arr[left..right]
    // AQUI ESTÁ A MUDANÇA PRINCIPAL PARA ORDENAÇÃO DECRESCENTE
    int i = 0; // Índice inicial do primeiro subarranjo
    int j = 0; // Índice inicial do segundo subarranjo
    int k = left; // Índice inicial do subarranjo mesclado

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) { // Comparação para ordem decrescente (maior ou igual)
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort
void mergeSortDecrescente(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Encontrar o ponto médio
        int mid = left + (right - left) / 2;

        // Chamar recursivamente para as duas metades
        mergeSortDecrescente(arr, left, mid);
        mergeSortDecrescente(arr, mid + 1, right);

        // Mesclar as metades ordenadas
        mergeDecrescente(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7, 25, 1, 99, 0};
    int n = arr.size();

    std::cout << "Array original:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    mergeSortDecrescente(arr, 0, n - 1);

    std::cout << "\nArray ordenado decrescentemente:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
} */

// Selection Sort
/* #include <iostream>
#include <vector>
#include <algorithm> // Para std::swap

void selectionSortDecrescente(std::vector<int>& arr) {
    int n = arr.size();

    // Um por um, move o limite do subarranjo não classificado
    for (int i = 0; i < n - 1; i++) {
        // Encontra o índice do maior elemento no subarranjo não classificado
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) { // AQUI ESTÁ A MUDANÇA PRINCIPAL PARA ORDENAÇÃO DECRESCENTE
                max_idx = j;
            }
        }

        // Troca o maior elemento encontrado com o primeiro elemento
        // da parte não classificada
        std::swap(arr[max_idx], arr[i]);
    }
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11, 88, 5, 30};
    int n = arr.size();

    std::cout << "Array original:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    selectionSortDecrescente(arr);

    std::cout << "\nArray ordenado decrescentemente:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
} */

// Insertion Sort
/* #include <iostream>
#include <vector>
#include <algorithm> // Não estritamente necessário para Insertion Sort, mas útil para outras operações

void insertionSortDecrescente(std::vector<int>& arr) {
    int n = arr.size();

    // Começa do segundo elemento, pois o primeiro é considerado "ordenado"
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // O elemento a ser inserido na parte ordenada
        int j = i - 1;    // Índice do último elemento da parte ordenada

        // Move os elementos de arr[0...i-1] que são MENORES que key
        // para uma posição à frente de sua posição atual.
        // AQUI ESTÁ A MUDANÇA PRINCIPAL PARA ORDENAÇÃO DECRESCENTE
        while (j >= 0 && arr[j] < key) { // Mudança de ">" para "<" para ordem decrescente
            arr[j + 1] = arr[j]; // Move o elemento para a direita
            j = j - 1;
        }
        arr[j + 1] = key; // Insere o key na sua posição correta
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7, 25, 1, 99, 0};
    int n = arr.size();

    std::cout << "Array original:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    insertionSortDecrescente(arr);

    std::cout << "\nArray ordenado decrescentemente:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
} */

// Quick Sort
/* #include <iostream>
#include <vector>
#include <algorithm> // Para std::swap

// Função de particionamento para ordenar de forma decrescente
int partitionDecrescente(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = (low - 1);     // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for MAIOR ou IGUAL ao pivô,
        // ele deve ir para a parte "esquerda" (maiores)
        if (arr[j] >= pivot) { // AQUI ESTÁ A MUDANÇA PRINCIPAL PARA ORDENAÇÃO DECRESCENTE
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    // Coloca o pivô na sua posição correta (entre os maiores e os menores)
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Função principal do Quick Sort
void quickSortDecrescente(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi é o índice de particionamento, arr[pi] está agora no lugar certo
        int pi = partitionDecrescente(arr, low, high);

        // Classifica recursivamente os elementos antes e depois da partição
        quickSortDecrescente(arr, low, pi - 1);
        quickSortDecrescente(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5, 20, 2};
    int n = arr.size();

    std::cout << "Array original:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    quickSortDecrescente(arr, 0, n - 1);

    std::cout << "\nArray ordenado decrescentemente:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
} */

// Counting Sort
/* #include <iostream>
#include <vector>
#include <algorithm> // Para std::max_element

void countingSortDecrescente(std::vector<int>& arr) {
    if (arr.empty()) {
        return; // Não faz nada se o array estiver vazio
    }

    // 1. Encontrar o maior elemento no array de entrada
    int max_val = *std::max_element(arr.begin(), arr.end());

    // Criar o array de contagem (tamanho max_val + 1) e inicializar com zeros
    // Este array armazenará a frequência de cada número
    std::vector<int> count(max_val + 1, 0);

    // 2. Contar a frequência de cada elemento no array de entrada
    for (int x : arr) {
        count[x]++;
    }

    // 3. Modificar o array de contagem para conter a soma cumulativa
    // Para ordenação decrescente, o array de contagem se torna um pouco diferente.
    // Ele armazenará a contagem cumulativa *a partir do maior valor para o menor*.
    // Ou seja, count[i] vai representar o número de elementos MAIORES OU IGUAIS a i.
    for (int i = max_val - 1; i >= 0; --i) {
        count[i] += count[i + 1];
    }

    // Criar o array de saída para armazenar os elementos ordenados
    std::vector<int> output(arr.size());

    // 4. Construir o array de saída
    // Iterar o array de entrada DE FRENTE PARA TRÁS. Isso é crucial para estabilidade.
    // AQUI ESTÁ A MUDANÇA PRINCIPAL PARA ORDENAÇÃO DECRESCENTE e ESTABILIDADE
    for (int i = arr.size() - 1; i >= 0; --i) {
        // A posição correta para arr[i] no array de saída é count[arr[i]] - 1
        output[count[arr[i]] - 1] = arr[i];
        // Decrementar a contagem para este elemento
        count[arr[i]]--;
    }

    // Copiar os elementos do array de saída de volta para o array original
    arr = output;
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    // Exemplo com um range maior
    // std::vector<int> arr = {12, 11, 13, 5, 6, 7, 25, 1, 99, 0};
    int n = arr.size();

    std::cout << "Array original:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    countingSortDecrescente(arr);

    std::cout << "\nArray ordenado decrescentemente:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
} */

// Heap Sort
/* #include <iostream>
#include <vector>
#include <algorithm> // Para std::swap

// Função para "heapificar" um sub-árvore com raiz no índice 'i'
// em um array que representa um max-heap
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;       // Inicializa largest como raiz
    int left = 2 * i + 1;  // Índice do filho esquerdo
    int right = 2 * i + 2; // Índice do filho direito

    // Se o filho esquerdo é maior que a raiz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Se o filho direito é maior que o maior até agora
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Se largest não é a raiz
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // Recursivamente heapify a sub-árvore afetada
        heapify(arr, n, largest);
    }
}

// Função principal do Heap Sort para ordenar decrescentemente
void heapSortDecrescente(std::vector<int>& arr) {
    int n = arr.size();

    // 1. Construir o max-heap (reorganizar o array)
    // O loop começa de (n/2 - 1) para processar os nós que não são folhas
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 2. Extrair elementos do heap um por um
    // AQUI ESTÁ A MUDANÇA PRINCIPAL PARA ORDENAÇÃO DECRESCENTE
    // Vamos extrair o maior elemento (raiz) e colocá-lo no final
    // A cada passo, o array se torna menor (n-1, n-2, ...)
    for (int i = n - 1; i >= 0; i--) {
        // Mover a raiz atual (maior elemento) para o final do array
        // (que se tornará a primeira posição na ordem decrescente quando o array for invertido ou lido ao contrário)
        std::swap(arr[0], arr[i]);

        // Chamar heapify no heap reduzido
        heapify(arr, i, 0); // 'i' agora representa o tamanho do heap
    }

    // Após o loop, o array estará ordenado de forma crescente (maiores no final).
    // Para torná-lo decrescente, simplesmente invertemos o array.
    std::reverse(arr.begin(), arr.end());
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7, 25, 1, 99, 0};
    int n = arr.size();

    std::cout << "Array original:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    heapSortDecrescente(arr);

    std::cout << "\nArray ordenado decrescentemente:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
} */

// Bucket Sort 
/* #include <iostream>
#include <vector>
#include <algorithm> // Para std::sort e std::reverse
#include <cmath>     // Para std::floor

// Uma função auxiliar para ordenar baldes (usando Insertion Sort decrescente)
// Poderíamos usar std::sort com um comparador lambda, mas vamos manter a função explícita.
void insertionSortDecrescente(std::vector<double>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) { // Comparação para ordem decrescente
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucketSortDecrescente(std::vector<double>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return; // Nada para ordenar ou já ordenado
    }

    // Determine o número de baldes. Geralmente, sqrt(n) ou n/k para algum k.
    // Para este exemplo, vamos usar n baldes.
    int num_buckets = n;
    std::vector<std::vector<double>> buckets(num_buckets);

    // 1. Distribuir elementos nos baldes
    // Assumimos que os elementos estão no intervalo [0, 1)
    // O índice do balde é calculado multiplicando o elemento por num_buckets
    // e pegando a parte inteira (floor).
    for (int i = 0; i < n; i++) {
        int bucket_idx = static_cast<int>(num_buckets * arr[i]);
        // Garante que o último valor (1.0) vá para o último balde, se necessário,
        // embora o exemplo com double seja para [0, 1) exclusivo no 1.
        if (bucket_idx == num_buckets) { // Lida com o caso de valor ser 1.0 (se permitido)
            bucket_idx--;
        }
        buckets[bucket_idx].push_back(arr[i]);
    }

    // 2. Classificar individualmente cada balde de forma DECRESCENTE
    // AQUI ESTÁ UMA DAS MUDANÇAS CHAVE PARA ORDENAÇÃO DECRESCENTE
    for (int i = 0; i < num_buckets; i++) {
        // Usamos nossa função customizada de Insertion Sort decrescente
        // ou um std::sort com um lambda para ordem decrescente:
        // std::sort(buckets[i].begin(), buckets[i].end(), std::greater<double>());
        insertionSortDecrescente(buckets[i]);
    }

    // 3. Concatenar os baldes de volta no array original
    // PARA ORDENAÇÃO DECRESCENTE, ITEIRAMOS DOS ÚLTIMOS BALDES PARA OS PRIMEIROS
    int index = 0;
    for (int i = num_buckets - 1; i >= 0; i--) { // Itera pelos baldes de TRÁS PARA FRENTE
        for (double val : buckets[i]) { // Os elementos dentro do balde já estão decrescentes
            arr[index++] = val;
        }
    }
}

int main() {
    // Exemplo com números no intervalo [0, 1)
    std::vector<double> arr = {0.897, 0.565, 0.656, 0.123, 0.665, 0.343, 0.001, 0.999};
    int n = arr.size();

    std::cout << "Array original:" << std::endl;
    for (double x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    bucketSortDecrescente(arr);

    std::cout << "\nArray ordenado decrescentemente:" << std::endl;
    for (double x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
} */

// Radix Sort
#include <iostream>
#include <vector>
#include <algorithm> // Para std::max_element

// Função auxiliar para obter o dígito em uma posição específica (exp)
// Ex: Se num=123 e exp=1, retorna 3 (unidades)
// Ex: Se num=123 e exp=10, retorna 2 (dezenas)
// Ex: Se num=123 e exp=100, retorna 1 (centenas)
int getDigit(int num, int exp) {
    return (num / exp) % 10;
}

// Sub-rotina de Counting Sort adaptada para ordenar DECRESCENTEMENTE
// com base no dígito especificado por 'exp'
void countingSortDecrescenteForRadix(std::vector<int>& arr, int n, int exp) {
    std::vector<int> output(n);
    // O range para dígitos é de 0 a 9
    std::vector<int> count(10, 0);

    // Contar a frequência dos dígitos
    for (int i = 0; i < n; i++) {
        count[getDigit(arr[i], exp)]++;
    }

    // Modificar o array de contagem para conter a soma cumulativa
    // Para ordenação decrescente: A soma cumulativa é feita de 9 para 0.
    // count[d] vai armazenar o número de elementos cujo dígito atual é >= d.
    for (int i = 8; i >= 0; i--) { // Começa de 8 para ir até 0
        count[i] += count[i + 1];
    }

    // Construir o array de saída (iterando o array original de TRÁS PARA FRENTE
    // para garantir estabilidade)
    for (int i = n - 1; i >= 0; i--) {
        // A posição correta para arr[i] no array de saída é count[getDigit(arr[i], exp)] - 1
        output[count[getDigit(arr[i], exp)] - 1] = arr[i];
        count[getDigit(arr[i], exp)]--;
    }

    // Copiar os elementos do array de saída de volta para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Função principal do Radix Sort para ordenar decrescentemente
void radixSortDecrescente(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return; // Nada para ordenar ou já ordenado
    }

    // Encontrar o maior número para saber o número máximo de dígitos
    int max_val = *std::max_element(arr.begin(), arr.end());

    // Fazer o Counting Sort para cada dígito.
    // 'exp' é 10^i onde i é o número do dígito atual (unidades, dezenas, centenas, etc.)
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        countingSortDecrescenteForRadix(arr, n, exp);
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = arr.size();

    std::cout << "Array original:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    radixSortDecrescente(arr);

    std::cout << "\nArray ordenado decrescentemente:" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
