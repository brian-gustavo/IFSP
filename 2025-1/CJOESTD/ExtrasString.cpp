// Bubble Sort
/* #include <iostream> // Para entrada e saída (cout, cin)
#include <vector>   // Para usar o tipo std::vector
#include <string>   // Para usar o tipo std::string
#include <algorithm> // Para a função std::swap

// Função para imprimir o vetor de strings
void imprimirVetor(const std::vector<std::string>& arr) {
    for (const std::string& s : arr) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

// Função que implementa o Bubble Sort para um vetor de strings
void bubbleSortStrings(std::vector<std::string>& arr) {
    int n = arr.size();
    bool trocou; // Flag para otimização: se nenhuma troca ocorrer em uma passagem, o vetor está ordenado

    for (int i = 0; i < n - 1; ++i) {
        trocou = false; // Reinicia a flag para cada passagem
        for (int j = 0; j < n - 1 - i; ++j) {
            // Compara strings lexicograficamente
            // Se a string atual for "maior" (vem depois na ordem alfabética) que a próxima
            if (arr[j] > arr[j + 1]) {
                // Troca as strings de posição
                std::swap(arr[j], arr[j + 1]);
                trocou = true; // Indica que uma troca ocorreu
            }
        }
        // Se nenhuma troca ocorreu nesta passagem, o vetor já está ordenado
        if (!trocou) {
            break;
        }
    }
}

int main() {
    // Exemplo de uso
    std::vector<std::string> palavras = {"uva", "banana", "maçã", "laranja", "abacaxi"};

    std::cout << "Vetor original: ";
    imprimirVetor(palavras);

    bubbleSortStrings(palavras); // Chama a função Bubble Sort

    std::cout << "Vetor ordenado: ";
    imprimirVetor(palavras);

    // Outro exemplo
    std::vector<std::string> nomes = {"Carlos", "Ana", "Bruno", "Daniela", "Eduardo"};

    std::cout << "\nVetor original de nomes: ";
    imprimirVetor(nomes);

    bubbleSortStrings(nomes);

    std::cout << "Vetor ordenado de nomes: ";
    imprimirVetor(nomes);

    return 0;
} */

// Merge Sort
/* #include <iostream> // Para entrada e saída (cout, cin)
#include <vector>   // Para usar o tipo std::vector
#include <string>   // Para usar o tipo std::string
#include <algorithm> // Para a função std::merge (usada implicitamente na lógica)

// Função para imprimir o vetor de strings
void imprimirVetor(const std::vector<std::string>& arr) {
    for (const std::string& s : arr) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

// Função de merge: combina duas sub-listas ordenadas em uma única lista ordenada
void merge(std::vector<std::string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria vetores temporários para armazenar as duas metades
    std::vector<std::string> leftArr(n1);
    std::vector<std::string> rightArr(n2);

    // Copia os dados para os vetores temporários
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    // Índices iniciais das sub-listas e do vetor principal
    int i = 0; // Índice da primeira sub-lista (leftArr)
    int j = 0; // Índice da segunda sub-lista (rightArr)
    int k = left; // Índice do vetor principal (arr)

    // Combina as duas sub-listas de volta no vetor original
    while (i < n1 && j < n2) {
        // Compara strings lexicograficamente
        if (leftArr[i] <= rightArr[j]) { // Note: <= para estabilidade
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de leftArr, se houver
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de rightArr, se houver
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort
void mergeSortStrings(std::vector<std::string>& arr, int left, int right) {
    if (left < right) {
        // Encontra o ponto médio para dividir o vetor em duas metades
        int mid = left + (right - left) / 2;

        // Ordena recursivamente a primeira metade
        mergeSortStrings(arr, left, mid);
        // Ordena recursivamente a segunda metade
        mergeSortStrings(arr, mid + 1, right);

        // Combina as duas metades ordenadas
        merge(arr, left, mid, right);
    }
}

int main() {
    // Exemplo de uso
    std::vector<std::string> palavras = {"uva", "banana", "maçã", "laranja", "abacaxi", "kiwi", "pêssego"};

    std::cout << "Vetor original: ";
    imprimirVetor(palavras);

    // Chama a função Merge Sort (passando o vetor e os índices inicial e final)
    mergeSortStrings(palavras, 0, palavras.size() - 1);

    std::cout << "Vetor ordenado: ";
    imprimirVetor(palavras);

    // Outro exemplo
    std::vector<std::string> nomes = {"Carlos", "Ana", "Bruno", "Daniela", "Eduardo", "Fernanda", "Gustavo"};

    std::cout << "\nVetor original de nomes: ";
    imprimirVetor(nomes);

    mergeSortStrings(nomes, 0, nomes.size() - 1);

    std::cout << "Vetor ordenado de nomes: ";
    imprimirVetor(nomes);

    return 0;
} */

// Selection Sort
/* #include <iostream> // Para entrada e saída (cout, cin)
#include <vector>   // Para usar o tipo std::vector
#include <string>   // Para usar o tipo std::string
#include <algorithm> // Para a função std::swap

// Função para imprimir o vetor de strings
void imprimirVetor(const std::vector<std::string>& arr) {
    for (const std::string& s : arr) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

// Função que implementa o Selection Sort para um vetor de strings
void selectionSortStrings(std::vector<std::string>& arr) {
    int n = arr.size();

    // Um por um, move o limite do sub-array não ordenado
    for (int i = 0; i < n - 1; ++i) {
        // Encontra o índice da string mínima no sub-array não ordenado
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            // Compara strings lexicograficamente
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Troca a string mínima encontrada com a primeira string do sub-array não ordenado
        // std::swap(arr[min_idx], arr[i]);
        // Uma troca manual é mostrada abaixo para ilustrar o conceito sem std::swap
        std::string temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    // Exemplo de uso
    std::vector<std::string> palavras = {"uva", "banana", "maçã", "laranja", "abacaxi"};

    std::cout << "Vetor original: ";
    imprimirVetor(palavras);

    selectionSortStrings(palavras); // Chama a função Selection Sort

    std::cout << "Vetor ordenado: ";
    imprimirVetor(palavras);

    // Outro exemplo
    std::vector<std::string> nomes = {"Carlos", "Ana", "Bruno", "Daniela", "Eduardo"};

    std::cout << "\nVetor original de nomes: ";
    imprimirVetor(nomes);

    selectionSortStrings(nomes);

    std::cout << "Vetor ordenado de nomes: ";
    imprimirVetor(nomes);

    return 0;
} */

// Insertion Sort
/* #include <iostream> // Para entrada e saída (cout, cin)
#include <vector>   // Para usar o tipo std::vector
#include <string>   // Para usar o tipo std::string

// Função para imprimir o vetor de strings
void imprimirVetor(const std::vector<std::string>& arr) {
    for (const std::string& s : arr) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

// Função que implementa o Insertion Sort para um vetor de strings
void insertionSortStrings(std::vector<std::string>& arr) {
    int n = arr.size();

    // Começa do segundo elemento, pois o primeiro (índice 0) é considerado já ordenado
    for (int i = 1; i < n; ++i) {
        std::string key = arr[i]; // String a ser inserida na sub-lista ordenada
        int j = i - 1;            // Índice do último elemento da sub-lista ordenada

        // Move os elementos de arr[0...i-1] que são maiores que key
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insere a string key na sua posição correta
    }
}

int main() {
    // Exemplo de uso
    std::vector<std::string> palavras = {"uva", "banana", "maçã", "laranja", "abacaxi"};

    std::cout << "Vetor original: ";
    imprimirVetor(palavras);

    insertionSortStrings(palavras); // Chama a função Insertion Sort

    std::cout << "Vetor ordenado: ";
    imprimirVetor(palavras);

    // Outro exemplo
    std::vector<std::string> nomes = {"Carlos", "Ana", "Bruno", "Daniela", "Eduardo"};

    std::cout << "\nVetor original de nomes: ";
    imprimirVetor(nomes);

    insertionSortStrings(nomes);

    std::cout << "Vetor ordenado de nomes: ";
    imprimirVetor(nomes);

    return 0;
} */

// Quick Sort
/* #include <iostream> // Para entrada e saída (cout, cin)
#include <vector>   // Para usar o tipo std::vector
#include <string>   // Para usar o tipo std::string
#include <algorithm> // Para a função std::swap

// Função para imprimir o vetor de strings
void imprimirVetor(const std::vector<std::string>& arr) {
    for (const std::string& s : arr) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

// Função de partição: escolhe um pivô e reorganiza o array
// de forma que todos os elementos menores que o pivô fiquem à sua esquerda,
// e todos os maiores, à sua direita. Retorna o índice do pivô.
int partition(std::vector<std::string>& arr, int low, int high) {
    std::string pivot = arr[high]; // Escolhe o último elemento como pivô (pode variar)
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j <= high - 1; ++j) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) { // Compara strings lexicograficamente
            i++; // Incrementa o índice do menor elemento
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]); // Coloca o pivô na sua posição correta
    return (i + 1);
}

// Função principal do Quick Sort
void quickSortStrings(std::vector<std::string>& arr, int low, int high) {
    if (low < high) {
        // pi é o índice de partição, arr[pi] está agora no lugar certo
        int pi = partition(arr, low, high);

        // Ordena recursivamente os elementos antes e depois da partição
        quickSortStrings(arr, low, pi - 1);
        quickSortStrings(arr, pi + 1, high);
    }
}

int main() {
    // Exemplo de uso
    std::vector<std::string> palavras = {"uva", "banana", "maçã", "laranja", "abacaxi", "kiwi", "pêssego"};

    std::cout << "Vetor original: ";
    imprimirVetor(palavras);

    // Chama a função Quick Sort (passando o vetor e os índices inicial e final)
    quickSortStrings(palavras, 0, palavras.size() - 1);

    std::cout << "Vetor ordenado: ";
    imprimirVetor(palavras);

    // Outro exemplo
    std::vector<std::string> nomes = {"Carlos", "Ana", "Bruno", "Daniela", "Eduardo", "Fernanda", "Gustavo"};

    std::cout << "\nVetor original de nomes: ";
    imprimirVetor(nomes);

    quickSortStrings(nomes, 0, nomes.size() - 1);

    std::cout << "Vetor ordenado de nomes: ";
    imprimirVetor(nomes);

    return 0;
} */

// Heap Sort
/* #include <iostream> // Para entrada e saída (cout, cin)
#include <vector>   // Para usar o tipo std::vector
#include <string>   // Para usar o tipo std::string
#include <algorithm> // Para a função std::swap

// Função para imprimir o vetor de strings
void imprimirVetor(const std::vector<std::string>& arr) {
    for (const std::string& s : arr) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

// Função para "heapificar" um subárvore enraizada em 'i'
// n é o tamanho do heap
void heapify(std::vector<std::string>& arr, int n, int i) {
    int largest = i;       // Inicializa 'largest' como a raiz
    int left = 2 * i + 1;  // Índice do filho esquerdo
    int right = 2 * i + 2; // Índice do filho direito

    // Se o filho esquerdo é maior que a raiz
    // Compara strings lexicograficamente
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Se o filho direito é maior que 'largest' até agora
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Se 'largest' não é a raiz
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Chama heapify recursivamente na subárvore afetada
        heapify(arr, n, largest);
    }
}

// Função principal do Heap Sort
void heapSortStrings(std::vector<std::string>& arr) {
    int n = arr.size();

    // Constrói um max-heap (reorganiza o array)
    // Começa do último nó pai e vai até a raiz
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extrai elementos um por um do heap
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual (maior elemento) para o final do array
        std::swap(arr[0], arr[i]);

        // Chama heapify no heap reduzido
        heapify(arr, i, 0);
    }
}

int main() {
    // Exemplo de uso
    std::vector<std::string> palavras = {"uva", "banana", "maçã", "laranja", "abacaxi", "kiwi", "pêssego"};

    std::cout << "Vetor original: ";
    imprimirVetor(palavras);

    // Chama a função Heap Sort
    heapSortStrings(palavras);

    std::cout << "Vetor ordenado: ";
    imprimirVetor(palavras);

    // Outro exemplo
    std::vector<std::string> nomes = {"Carlos", "Ana", "Bruno", "Daniela", "Eduardo", "Fernanda", "Gustavo"};

    std::cout << "\nVetor original de nomes: ";
    imprimirVetor(nomes);

    heapSortStrings(nomes);

    std::cout << "Vetor ordenado de nomes: ";
    imprimirVetor(nomes);

    return 0;
} */

// Bucket Sort
/* #include <iostream>  // Para entrada e saída (cout, cin)
#include <vector>    // Para usar o tipo std::vector
#include <string>    // Para usar o tipo std::string
#include <algorithm> // Para a função std::sort (usada para ordenar os buckets)

// Função para imprimir o vetor de strings
void imprimirVetor(const std::vector<std::string>& arr) {
    for (const std::string& s : arr) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

// Função que implementa o Bucket Sort para um vetor de strings
void bucketSortStrings(std::vector<std::string>& arr) {
    if (arr.empty()) {
        return; // Nada para ordenar se o vetor estiver vazio
    }

    // Determine o número de buckets.
    // Usaremos 26 buckets para as letras do alfabeto (a-z ou A-Z)
    // Se você tiver um conjunto de caracteres maior (ex: Unicode), precisará de mais buckets.
    const int NUM_BUCKETS = 26; // Para letras de 'a' a 'z'
    std::vector<std::vector<std::string>> buckets(NUM_BUCKETS);

    // 1. Distribua as strings nos buckets
    for (const std::string& s : arr) {
        if (!s.empty()) {
            // Converte o primeiro caractere para minúscula e calcula o índice do bucket.
            // Ex: 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
            // Ignoramos caracteres não alfabéticos ou strings vazias
            char firstCharLower = std::tolower(s[0]);
            if (firstCharLower >= 'a' && firstCharLower <= 'z') {
                int bucketIndex = firstCharLower - 'a';
                buckets[bucketIndex].push_back(s);
            } else {
                // Opcional: Trate strings que não começam com letras (ex: números, símbolos)
                // Para este exemplo, elas não serão ordenadas.
                std::cout << "Aviso: String '" << s << "' não começa com letra e será ignorada pelo Bucket Sort." << std::endl;
            }
        }
    }

    // 2. Ordene cada bucket individualmente
    // Usamos std::sort, que é geralmente uma implementação de Introsort (híbrido de QuickSort, HeapSort, InsertionSort)
    // para ordenar eficientemente os elementos dentro de cada bucket.
    for (int i = 0; i < NUM_BUCKETS; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // 3. Concatene os buckets ordenados de volta no vetor original
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; ++i) {
        for (const std::string& s : buckets[i]) {
            arr[index++] = s;
        }
    }
}

int main() {
    // Exemplo de uso
    std::vector<std::string> palavras = {"uva", "banana", "maçã", "laranja", "abacaxi", "kiwi", "pêssego", "zebra", "abelha", "árvore"};

    std::cout << "Vetor original: ";
    imprimirVetor(palavras);

    bucketSortStrings(palavras); // Chama a função Bucket Sort

    std::cout << "Vetor ordenado: ";
    imprimirVetor(palavras);

    // Outro exemplo com maiúsculas e minúsculas misturadas e uma string não alfabética
    std::vector<std::string> nomes = {"Carlos", "ana", "Bruno", "Daniela", "eduardo", "Fernanda", "Gustavo", "Ágata", "2pac"};

    std::cout << "\n--- Segundo Exemplo ---";
    std::cout << "\nVetor original de nomes: ";
    imprimirVetor(nomes);

    bucketSortStrings(nomes);

    std::cout << "Vetor ordenado de nomes: ";
    imprimirVetor(nomes);

    return 0;
} */

// Radix Sort
/* #include <iostream>   // Para entrada e saída (cout, cin)
#include <vector>     // Para usar o tipo std::vector
#include <string>     // Para usar o tipo std::string
#include <algorithm>  // Para std::max, std::sort (implícito no counting sort)

// Função para imprimir o vetor de strings
void imprimirVetor(const std::vector<std::string>& arr) {
    for (const std::string& s : arr) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

// Encontra o comprimento máximo das strings no vetor
int getMaxLen(const std::vector<std::string>& arr) {
    int maxLen = 0;
    for (const std::string& s : arr) {
        if (s.length() > maxLen) {
            maxLen = s.length();
        }
    }
    return maxLen;
}

// Função de Counting Sort para um caractere específico na posição 'pos'
// Assume que o 'paddingChar' é lexicograficamente o menor.
void countingSortByChar(std::vector<std::string>& arr, int n, int pos, int maxLen, char paddingChar = ' ') {
    const int ALPHABET_SIZE = 27; // 'a' - 'z' (26) + 1 para o paddingChar ou caracteres não alfabéticos
    std::vector<int> count(ALPHABET_SIZE, 0);
    std::vector<std::string> output(n);

    // 1. Contar a frequência de cada caractere na posição 'pos'
    for (int i = 0; i < n; ++i) {
        char ch;
        // Pega o caractere na posição 'pos'. Se a string for mais curta, usa o paddingChar.
        if (pos < arr[i].length()) {
            ch = std::tolower(arr[i][pos]); // Converte para minúscula para ordenação case-insensitive
        } else {
            ch = paddingChar; // Usa o caractere de preenchimento para strings mais curtas
        }

        // Mapeia o caractere para um índice: ' ' -> 0, 'a' -> 1, ..., 'z' -> 26
        int charIndex;
        if (ch == paddingChar) {
            charIndex = 0;
        } else if (ch >= 'a' && ch <= 'z') {
            charIndex = (ch - 'a') + 1; // +1 porque 0 é para paddingChar
        } else {
            // Se for um caractere não alfabético e não o paddingChar, coloca em um índice "genérico"
            // Para simplificar, vamos mapear outros caracteres para um índice específico.
            // Para uma solução robusta, poderia ser necessário um mapa ou mais buckets.
            charIndex = 0; // Ou outro índice para caracteres especiais
        }
        count[charIndex]++;
    }

    // 2. Acumular as contagens para obter as posições reais
    for (int i = 1; i < ALPHABET_SIZE; ++i) {
        count[i] += count[i - 1];
    }

    // 3. Construir o array de saída
    // Percorrer de trás para frente para manter a estabilidade
    for (int i = n - 1; i >= 0; --i) {
        char ch;
        if (pos < arr[i].length()) {
            ch = std::tolower(arr[i][pos]);
        } else {
            ch = paddingChar;
        }

        int charIndex;
        if (ch == paddingChar) {
            charIndex = 0;
        } else if (ch >= 'a' && ch <= 'z') {
            charIndex = (ch - 'a') + 1;
        } else {
            charIndex = 0; // Mesmo mapeamento para caracteres especiais
        }

        output[count[charIndex] - 1] = arr[i];
        count[charIndex]--;
    }

    // 4. Copiar o array de saída de volta para o array original
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Função principal do Radix Sort para strings (LSD)
void radixSortStrings(std::vector<std::string>& arr) {
    int n = arr.size();
    if (n == 0) {
        return;
    }

    int maxLen = getMaxLen(arr);

    // Percorre do último caractere (menos significativo) até o primeiro
    // Se maxLen é 5, processa pos 4, 3, 2, 1, 0
    for (int pos = maxLen - 1; pos >= 0; --pos) {
        countingSortByChar(arr, n, pos, maxLen);
    }
}

int main() {
    // Exemplo de uso
    std::vector<std::string> palavras = {"uva", "banana", "maçã", "laranja", "abacaxi", "kiwi", "pêssego", "abelha", "caju"};

    std::cout << "Vetor original: ";
    imprimirVetor(palavras);

    radixSortStrings(palavras); // Chama a função Radix Sort

    std::cout << "Vetor ordenado: ";
    imprimirVetor(palavras);

    // Outro exemplo com maiúsculas e minúsculas misturadas e diferentes comprimentos
    std::vector<std::string> nomes = {"Carlos", "ana", "Bruno", "Daniela", "eduardo", "Fernanda", "Gustavo", "Ágata", "Bob", "z", "Alexandre"};

    std::cout << "\n--- Segundo Exemplo ---";
    std::cout << "\nVetor original de nomes: ";
    imprimirVetor(nomes);

    radixSortStrings(nomes);

    std::cout << "Vetor ordenado de nomes: ";
    imprimirVetor(nomes);

    return 0;
} */

// Counting Sort
/* #include <iostream>  // Para entrada e saída (cout, cin)
#include <vector>    // Para usar o tipo std::vector
#include <string>    // Para usar o tipo std::string
#include <algorithm> // Para std::tolower

// Função para imprimir o vetor de strings
void imprimirVetor(const std::vector<std::string>& arr) {
    for (const std::string& s : arr) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

// Função que implementa o Counting Sort para um vetor de strings
// Ordena as strings baseando-se no PRIMEIRO CARACTERE (case-insensitive)
void countingSortStringsByFirstChar(std::vector<std::string>& arr) {
    int n = arr.size();
    if (n == 0) {
        return;
    }

    // Definimos um intervalo para os caracteres.
    // Usaremos 'a' a 'z', além de um slot para caracteres não alfabéticos/vazios.
    // O valor ASCII de 'a' é 97, 'z' é 122.
    // Para simplificar, vamos mapear ' ' -> 0, 'a' -> 1, ..., 'z' -> 26.
    const int RANGE = 27; // 26 letras + 1 para outros (ou para o menor caractere de padding, se houvesse)
    
    std::vector<int> count(RANGE, 0);
    std::vector<std::string> output(n);

    // 1. Contar a frequência de cada primeiro caractere
    for (int i = 0; i < n; ++i) {
        char firstChar = arr[i].empty() ? ' ' : std::tolower(arr[i][0]); // Pega o 1º char ou espaço se vazio

        int charIndex;
        if (firstChar >= 'a' && firstChar <= 'z') {
            charIndex = (firstChar - 'a') + 1; // Mapeia 'a' para 1, 'b' para 2, etc.
        } else {
            charIndex = 0; // Mapeia espaço e outros caracteres para 0 (o menor índice)
        }
        count[charIndex]++;
    }

    // 2. Acumular as contagens para obter as posições reais no array de saída
    for (int i = 1; i < RANGE; ++i) {
        count[i] += count[i - 1];
    }

    // 3. Construir o array de saída (output)
    // Percorrer de trás para frente para garantir a estabilidade
    for (int i = n - 1; i >= 0; --i) {
        char firstChar = arr[i].empty() ? ' ' : std::tolower(arr[i][0]);
        
        int charIndex;
        if (firstChar >= 'a' && firstChar <= 'z') {
            charIndex = (firstChar - 'a') + 1;
        } else {
            charIndex = 0;
        }
        
        output[count[charIndex] - 1] = arr[i];
        count[charIndex]--;
    }

    // 4. Copiar o array de saída de volta para o array original
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

int main() {
    // Exemplo de uso
    std::vector<std::string> palavras = {"uva", "banana", "maçã", "laranja", "abacaxi", "kiwi", "pêssego", "abelha", "caju", "árvore", ""};

    std::cout << "Vetor original: ";
    imprimirVetor(palavras);

    countingSortStringsByFirstChar(palavras); // Chama a função Counting Sort

    std::cout << "Vetor ordenado (pelo primeiro caractere): ";
    imprimirVetor(palavras);

    // Outro exemplo com maiúsculas e minúsculas misturadas e diferentes comprimentos
    std::vector<std::string> nomes = {"Carlos", "ana", "Bruno", "Daniela", "eduardo", "Fernanda", "Gustavo", "Ágata", "Bob", "z", "Alexandre", "Zé", "123", "Átila"};

    std::cout << "\n--- Segundo Exemplo ---";
    std::cout << "\nVetor original de nomes: ";
    imprimirVetor(nomes);

    countingSortStringsByFirstChar(nomes);

    std::cout << "Vetor ordenado (pelo primeiro caractere): ";
    imprimirVetor(nomes);

    return 0;
} */
