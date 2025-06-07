#include <iostream>
#include <vector>
#include <chrono> 
#include <random>
#include <numeric>

using namespace std;

// Trecho fornecido pelo professor
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* Exercício 1
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
} */

/* Exercício 2
void bubbleSort(int arr[], int n, int &passes) {
    bool swapped;
    passes = 0;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        passes++;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
} */

/* Exercício 3
void bubbleSort(int arr[], int n, int &passes, int &comparisons, int &swaps) {
    bool swapped_this_pass;
    passes = 0;
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        swapped_this_pass = false;
        passes++;

        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;

            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped_this_pass = true;
                swaps++;
            }
        }

        if (swapped_this_pass == false) {
            break;
        }
    }
} */

/* Exercício 4
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j+1]) {           <--- Linha que precisou ser mudada
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
} */

/* Exercício 5
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << "Passada " << (i + 1) << ":" << endl;
        bool swapped_this_pass = false;

        for (int j = 0; j < n - i - 1; j++) {
            cout << "Comparando " << arr[j] << " e " << arr[j+1] << ": ";

            if (arr[j] > arr[j+1]) {
                cout << "Troca! -> ";
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped_this_pass = true;
                printArray(arr, n);
                cout << endl;
            } else {
                cout << "Não troca" << endl;
            }
        }

        cout << "Final da passada " << (i + 1) << ": ";
        printArray(arr, n);
        cout << endl;

        if (swapped_this_pass == false) {
             cout << "Array já ordenado, encerrando." << endl;
             break;
        }
        cout << endl;
    }
} */

// Exercício 6
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca arr[j] e arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void generateRandomArray(int arr[], int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);
    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }
}

double measureTime(int arr[], int n) {
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr, n);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration.count() / 1000.0;
}

int main() {
    /* Exercício 1
    int arr[] = {7, 3, 9, 1, 5, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    printArray(arr, n);

    bubbleSort(arr, n);
    cout << "Array ordenado: ";
    printArray(arr, n); */

    /* Exercício 2
    int passes;

    int arrDesordenado[] = {5, 4, 3, 2, 1};
    int nDesordenado = sizeof(arrDesordenado) / sizeof(arrDesordenado[0]);

    cout << "Array desordenado original: ";
    printArray(arrDesordenado, nDesordenado);

    bubbleSort(arrDesordenado, nDesordenado, passes);
    cout << "Array desordenado ordenado: ";
    printArray(arrDesordenado, nDesordenado);
    cout << "Passadas para array desordenado: " << passes << endl << endl;

    int arrOrdenado[] = {1, 2, 3, 4, 5};
    int nOrdenado = sizeof(arrOrdenado) / sizeof(arrOrdenado[0]);

    cout << "Array ordenado original: ";
    printArray(arrOrdenado, nOrdenado);

    bubbleSort(arrOrdenado, nOrdenado, passes);
    cout << "Array ordenado (permanece igual): ";
    printArray(arrOrdenado, nOrdenado);
    cout << "Passadas para array ordenado: " << passes << endl; */

    /* Exercício 3
    int passes;     
    int comparisons;
    int swaps;       

    int arr1[] = {3, 1, 4, 1, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "--- Teste com arr1 ---" << endl;
    cout << "Array original arr1: ";
    printArray(arr1, n1);

    bubbleSort(arr1, n1, passes, comparisons, swaps);
    cout << "Array ordenado arr1: ";
    printArray(arr1, n1);
    cout << "Passadas: " << passes << endl;
    cout << "Comparações: " << comparisons << endl;
    cout << "Trocas: " << swaps << endl << endl;

    int arr2[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "--- Teste com arr2 ---" << endl;
    cout << "Array original arr2: ";
    printArray(arr2, n2);

    bubbleSort(arr2, n2, passes, comparisons, swaps);
    cout << "Array ordenado arr2: ";
    printArray(arr2, n2);
    cout << "Passadas: " << passes << endl;
    cout << "Comparações: " << comparisons << endl;
    cout << "Trocas: " << swaps << endl << endl;

    int arr3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << "--- Teste com arr3 (Pior Caso) ---" << endl;
    cout << "Array original arr3: ";
    printArray(arr3, n3);

    bubbleSort(arr3, n3, passes, comparisons, swaps);
    cout << "Array ordenado arr3: ";
    printArray(arr3, n3);
    cout << "Passadas: " << passes << endl;
    cout << "Comparações: " << comparisons << endl;
    cout << "Trocas: " << swaps << endl << endl;

    int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);

    cout << "--- Teste com arr4 (Melhor Caso) ---" << endl;
    cout << "Array original arr4: ";
    printArray(arr4, n4);

    bubbleSort(arr4, n4, passes, comparisons, swaps);
    cout << "Array ordenado arr4: ";
    printArray(arr4, n4);
    cout << "Passadas: " << passes << endl;
    cout << "Comparações: " << comparisons << endl;
    cout << "Trocas: " << swaps << endl << endl; */

    /* Exercício 4
    int arr[] = {7, 3, 9, 1, 5, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    printArray(arr, n);

    bubbleSort(arr, n);
    cout << "Array decrescente: ";
    printArray(arr, n); */

    /* Exercício 5
    int arr[] = {5, 2, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    printArray(arr, n);
    cout << endl << endl;

    bubbleSort(arr, n);

    cout << endl << "Array final ordenado: ";
    printArray(arr, n);
    cout << endl; */

    // Exercício 6
    const int sizes[] = {100, 500, 1000, 2000};
    const int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    const int num_executions = 5;

    for (int k = 0; k < num_sizes; ++k) {
        int current_n = sizes[k];
        double total_time = 0.0;
        
        cout << "Testando com array de " << current_n << " elementos:" << endl;

        int* arr_test = new int[current_n];

        for (int i = 0; i < num_executions; ++i) {
            generateRandomArray(arr_test, current_n);
            
            double time_taken = measureTime(arr_test, current_n);
            cout << "  Execução " << (i + 1) << ": " << time_taken << " ms" << endl;
            total_time += time_taken;
        }

        double average_time = total_time / num_executions;
        cout << "Tempo médio para " << current_n << " elementos: " << average_time << " ms" << endl;
        cout << "------------------------------------------" << endl << endl;

        delete[] arr_test;
    }

    return 0;
}
