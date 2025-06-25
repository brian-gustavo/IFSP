// Tabela hash com endereçamento aberto (sondagem linear)
/* #include <iostream>
#include <vector>
#include <string>

enum SlotStatus { EMPTY, OCCUPIED, DELETED };

class HashTableOpenAddressing {
private:
    int capacity;
    std::vector<std::pair<std::string, int>> table;
    std::vector<SlotStatus> status;
    int currentSize;

    int hashFunction(const std::string& key) {
        long long hash = 0;
        for (char c : key) {
            hash = (hash * 31 + static_cast<long long>(c));
        }
        return (hash % capacity + capacity) % capacity;
    }

    void resizeAndRehash() {
        int oldCapacity = capacity;
        capacity *= 2;
        std::vector<std::pair<std::string, int>> oldTable = table;
        std::vector<SlotStatus> oldStatus = status;

        table.assign(capacity, {"", 0}); 
        status.assign(capacity, EMPTY); 
        currentSize = 0;

        for (int i = 0; i < oldCapacity; ++i) {
            if (oldStatus[i] == OCCUPIED) {
                insert(oldTable[i].first, oldTable[i].second);
            }
        }
        std::cout << "Tabela redimensionada para capacidade: " << capacity << std::endl;
    }

public:
    HashTableOpenAddressing(int cap) : capacity(cap), currentSize(0) {
        table.resize(capacity);
        status.assign(capacity, EMPTY);
    }

    void insert(const std::string& key, int value) {
        if (static_cast<double>(currentSize) / capacity >= 0.7) {
            resizeAndRehash();
        }

        int index = hashFunction(key);
        int originalIndex = index;

        while (status[index] == OCCUPIED) {
            if (table[index].first == key) {
                table[index].second = value;
                std::cout << "Chave '" << key << "' atualizada no indice " << index << std::endl;
                return;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex) {
                std::cerr << "Erro: Tabela cheia, nao foi possivel inserir '" << key << "'" << std::endl;
                return;
            }
        }

        table[index] = {key, value};
        status[index] = OCCUPIED;
        currentSize++;
        std::cout << "Chave '" << key << "' inserida no indice " << index << std::endl;
    }

    int search(const std::string& key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (status[index] != EMPTY) {
            if (status[index] == OCCUPIED && table[index].first == key) {
                return table[index].second;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex) {
                break;
            }
        }
        return -1;
    }

    void remove(const std::string& key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (status[index] != EMPTY) {
            if (status[index] == OCCUPIED && table[index].first == key) {
                status[index] = DELETED;
                currentSize--;
                std::cout << "Chave '" << key << "' removida (marcada como DELETED) do indice " << index << std::endl;
                return;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex) {
                break;
            }
        }
        std::cout << "Chave '" << key << "' nao encontrada para remocao." << std::endl;
    }

    void display() {
        std::cout << "\n--- Conteudo da Tabela Hash (Enderecamento Aberto) ---" << std::endl;
        for (int i = 0; i < capacity; ++i) {
            std::cout << "Balde " << i << ": ";
            if (status[i] == OCCUPIED) {
                std::cout << "[" << table[i].first << ": " << table[i].second << "]";
            } else if (status[i] == DELETED) {
                std::cout << "[DELETED]";
            } else { // EMPTY
                std::cout << "[EMPTY]";
            }
            std::cout << std::endl;
        }
        std::cout << "---------------------------------------------------" << std::endl;
    }
};

int main() {
    HashTableOpenAddressing myHashTable(5); 

    std::cout << "--- Operacoes de Insercao ---" << std::endl;
    myHashTable.insert("apple", 10);
    myHashTable.insert("banana", 20);
    myHashTable.insert("cherry", 30);
    myHashTable.insert("grape", 40); 
    myHashTable.insert("melon", 50);
    myHashTable.insert("lemon", 60); 

    myHashTable.display();

    std::cout << "\n--- Operacoes de Busca ---" << std::endl;
    std::string searchKey1 = "banana";
    int value1 = myHashTable.search(searchKey1);
    if (value1 != -1) {
        std::cout << "Valor de '" << searchKey1 << "': " << value1 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey1 << "' nao encontrada." << std::endl;
    }

    std::string searchKey2 = "cherry";
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

    myHashTable.display();

    std::cout << "\n--- Operacoes de Remocao ---" << std::endl;
    myHashTable.remove("banana");
    myHashTable.remove("grape");
    myHashTable.remove("kiwi");

    myHashTable.display();

    std::cout << "\n--- Busca apos remocao ---" << std::endl;
    std::string searchKey4 = "banana";
    int value4 = myHashTable.search(searchKey4);
    if (value4 != -1) {
        std::cout << "Valor de '" << searchKey4 << "': " << value4 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey4 << "' nao encontrada." << std::endl;
    }

    std::string searchKey5 = "cherry";
    int value5 = myHashTable.search(searchKey5);
    if (value5 != -1) {
        std::cout << "Valor de '" << searchKey5 << "': " << value5 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey5 << "' nao encontrada." << std::endl;
    }

    return 0;
} */

// Tabela hash com endereçamento aberto (sondagem quadrática)
/* #include <iostream>
#include <vector>
#include <string>
#include <cmath>

enum SlotStatus { EMPTY, OCCUPIED, DELETED };

class HashTableQuadraticProbing {
private:
    int capacity;
    std::vector<std::pair<std::string, int>> table;
    std::vector<SlotStatus> status;
    int currentSize;

    int hashFunction(const std::string& key) {
        long long hash = 0;
        for (char c : key) {
            hash = (hash * 31 + static_cast<long long>(c));
        }
        return (hash % capacity + capacity) % capacity;
    }

    void resizeAndRehash() {
        int oldCapacity = capacity;
        capacity = findNextPrime(capacity * 2);
        
        std::vector<std::pair<std::string, int>> oldTable = table;
        std::vector<SlotStatus> oldStatus = status;

        table.assign(capacity, {"", 0});
        status.assign(capacity, EMPTY);
        currentSize = 0;

        for (int i = 0; i < oldCapacity; ++i) {
            if (oldStatus[i] == OCCUPIED) {
                insert(oldTable[i].first, oldTable[i].second);
            }
        }
        std::cout << "Tabela redimensionada para capacidade (proximo primo): " << capacity << std::endl;
    }

    int findNextPrime(int n) {
        while (true) {
            bool isPrime = true;
            if (n <= 1) isPrime = false;
            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) return n;
            n++;
        }
    }

public:
    HashTableQuadraticProbing(int cap) : capacity(findNextPrime(cap)), currentSize(0) {
        table.resize(capacity);
        status.assign(capacity, EMPTY);
    }

    void insert(const std::string& key, int value) {
        if (static_cast<double>(currentSize) / capacity >= 0.5) {
            resizeAndRehash();
        }

        int originalIndex = hashFunction(key);
        int index;
        int i = 0;

        while (i < capacity) {
            index = (originalIndex + static_cast<int>(std::pow(i, 2))) % capacity;
            
            if (status[index] == EMPTY || status[index] == DELETED) {
                table[index] = {key, value};
                status[index] = OCCUPIED;
                currentSize++;
                std::cout << "Chave '" << key << "' inserida no indice " << index << std::endl;
                return;
            }
            else if (status[index] == OCCUPIED && table[index].first == key) {
                table[index].second = value;
                std::cout << "Chave '" << key << "' atualizada no indice " << index << std::endl;
                return;
            }
            i++;
        }

        std::cerr << "Erro: Tabela cheia ou loop detectado, nao foi possivel inserir '" << key << "'" << std::endl;
    }

    int search(const std::string& key) {
        int originalIndex = hashFunction(key);
        int index;
        int i = 0;

        while (i < capacity) {
            index = (originalIndex + static_cast<int>(std::pow(i, 2))) % capacity;

            if (status[index] == EMPTY) {
                break;
            }
            if (status[index] == OCCUPIED && table[index].first == key) {
                return table[index].second;
            }
            i++;
        }
        return -1;
    }

    void remove(const std::string& key) {
        int originalIndex = hashFunction(key);
        int index;
        int i = 0;

        while (i < capacity) {
            index = (originalIndex + static_cast<int>(std::pow(i, 2))) % capacity;

            if (status[index] == EMPTY) {
                break;
            }
            if (status[index] == OCCUPIED && table[index].first == key) {
                status[index] = DELETED;
                currentSize--;
                std::cout << "Chave '" << key << "' removida (marcada como DELETED) do indice " << index << std::endl;
                return;
            }
            i++;
        }
        std::cout << "Chave '" << key << "' nao encontrada para remocao." << std::endl;
    }

    void display() {
        std::cout << "\n--- Conteudo da Tabela Hash (Sondagem Quadratica) ---" << std::endl;
        for (int i = 0; i < capacity; ++i) {
            std::cout << "Balde " << i << ": ";
            if (status[i] == OCCUPIED) {
                std::cout << "[" << table[i].first << ": " << table[i].second << "]";
            } else if (status[i] == DELETED) {
                std::cout << "[DELETED]";
            } else { // EMPTY
                std::cout << "[EMPTY]";
            }
            std::cout << std::endl;
        }
        std::cout << "---------------------------------------------------" << std::endl;
    }
};

int main() {
    HashTableQuadraticProbing myHashTable(7);

    std::cout << "--- Operacoes de Insercao ---" << std::endl;
    myHashTable.insert("apple", 10);
    myHashTable.insert("banana", 20);
    myHashTable.insert("cherry", 30);
    myHashTable.insert("grape", 40);
    myHashTable.insert("melon", 50);
    myHashTable.insert("lemon", 60);

    myHashTable.display();

    std::cout << "\n--- Operacoes de Busca ---" << std::endl;
    std::string searchKey1 = "banana";
    int value1 = myHashTable.search(searchKey1);
    if (value1 != -1) {
        std::cout << "Valor de '" << searchKey1 << "': " << value1 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey1 << "' nao encontrada." << std::endl;
    }

    std::string searchKey2 = "cherry";
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
    
    myHashTable.display();

    std::cout << "\n--- Operacoes de Remocao ---" << std::endl;
    myHashTable.remove("banana");
    myHashTable.remove("grape");
    myHashTable.remove("kiwi");

    myHashTable.display();

    std::cout << "\n--- Busca apos remocao ---" << std::endl;
    std::string searchKey4 = "banana";
    int value4 = myHashTable.search(searchKey4);
    if (value4 != -1) {
        std::cout << "Valor de '" << searchKey4 << "': " << value4 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey4 << "' nao encontrada." << std::endl;
    }

    std::string searchKey5 = "cherry";
    int value5 = myHashTable.search(searchKey5);
    if (value5 != -1) {
        std::cout << "Valor de '" << searchKey5 << "': " << value5 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey5 << "' nao encontrada." << std::endl;
    }

    return 0;
} */

// Tabela hash com endereçamento aberto (sondagem dupla hashing)
/* #include <iostream>
#include <vector>
#include <string>
#include <numeric>

enum SlotStatus { EMPTY, OCCUPIED, DELETED };

class HashTableDoubleHashing {
private:
    int capacity;
    std::vector<std::pair<std::string, int>> table;
    std::vector<SlotStatus> status;
    int currentSize;

    int hashFunction1(const std::string& key) {
        long long hash = 0;
        for (char c : key) {
            hash = (hash * 31 + static_cast<long long>(c));
        }
        return (hash % capacity + capacity) % capacity;
    }

    int hashFunction2(const std::string& key) {
        long long hash = 0;
        for (char c : key) {
            hash = (hash * 17 + static_cast<long long>(c));
        }
        int step = (hash % (capacity - 1) + 1);
        return step;
    }

    void resizeAndRehash() {
        int oldCapacity = capacity;
        capacity = findNextPrime(capacity * 2);
        
        std::vector<std::pair<std::string, int>> oldTable = table;
        std::vector<SlotStatus> oldStatus = status;

        table.assign(capacity, {"", 0});
        status.assign(capacity, EMPTY);
        currentSize = 0;

        for (int i = 0; i < oldCapacity; ++i) {
            if (oldStatus[i] == OCCUPIED) {
                insert(oldTable[i].first, oldTable[i].second);
            }
        }
        std::cout << "Tabela redimensionada para capacidade (proximo primo): " << capacity << std::endl;
    }

    int findNextPrime(int n) {
        while (true) {
            bool isPrime = true;
            if (n <= 1) isPrime = false;
            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) return n;
            n++;
        }
    }

public:
    HashTableDoubleHashing(int cap) : currentSize(0) {
        capacity = findNextPrime(cap);
        table.resize(capacity);
        status.assign(capacity, EMPTY);
    }

    void insert(const std::string& key, int value) {
        if (static_cast<double>(currentSize) / capacity >= 0.7) {
            resizeAndRehash();
        }

        int h1 = hashFunction1(key);
        int h2 = hashFunction2(key);
        int index;
        
        for (int i = 0; i < capacity; ++i) {
            index = (h1 + i * h2) % capacity;
            if (index < 0) index += capacity;

            if (status[index] == EMPTY || status[index] == DELETED) {
                table[index] = {key, value};
                status[index] = OCCUPIED;
                currentSize++;
                std::cout << "Chave '" << key << "' inserida no indice " << index << std::endl;
                return;
            }
            else if (status[index] == OCCUPIED && table[index].first == key) {
                table[index].second = value;
                std::cout << "Chave '" << key << "' atualizada no indice " << index << std::endl;
                return;
            }
        }

        std::cerr << "Erro: Tabela cheia ou loop detectado, nao foi possivel inserir '" << key << "'" << std::endl;
    }

    int search(const std::string& key) {
        int h1 = hashFunction1(key);
        int h2 = hashFunction2(key);
        int index;

        for (int i = 0; i < capacity; ++i) {
            index = (h1 + i * h2) % capacity;
            if (index < 0) index += capacity;

            if (status[index] == EMPTY) {
                break;
            }
            if (status[index] == OCCUPIED && table[index].first == key) {
                return table[index].second;
            }
        }
        return -1;
    }

    void remove(const std::string& key) {
        int h1 = hashFunction1(key);
        int h2 = hashFunction2(key);
        int index;

        for (int i = 0; i < capacity; ++i) {
            index = (h1 + i * h2) % capacity;
            if (index < 0) index += capacity;

            if (status[index] == EMPTY) {
                break;
            }
            if (status[index] == OCCUPIED && table[index].first == key) {
                status[index] = DELETED;
                currentSize--;
                std::cout << "Chave '" << key << "' removida (marcada como DELETED) do indice " << index << std::endl;
                return;
            }
        }
        std::cout << "Chave '" << key << "' nao encontrada para remocao." << std::endl;
    }

    void display() {
        std::cout << "\n--- Conteudo da Tabela Hash (Sondagem Dupla Hashing) ---" << std::endl;
        for (int i = 0; i < capacity; ++i) {
            std::cout << "Balde " << i << ": ";
            if (status[i] == OCCUPIED) {
                std::cout << "[" << table[i].first << ": " << table[i].second << "]";
            } else if (status[i] == DELETED) {
                std::cout << "[DELETED]";
            } else { // EMPTY
                std::cout << "[EMPTY]";
            }
            std::cout << std::endl;
        }
        std::cout << "----------------------------------------------------" << std::endl;
    }
};

int main() {
    HashTableDoubleHashing myHashTable(7); 

    std::cout << "--- Operacoes de Insercao ---" << std::endl;
    myHashTable.insert("apple", 10);
    myHashTable.insert("banana", 20);
    myHashTable.insert("cherry", 30);
    myHashTable.insert("grape", 40);
    myHashTable.insert("melon", 50);
    myHashTable.insert("lemon", 60);

    myHashTable.display();

    std::cout << "\n--- Operacoes de Busca ---" << std::endl;
    std::string searchKey1 = "banana";
    int value1 = myHashTable.search(searchKey1);
    if (value1 != -1) {
        std::cout << "Valor de '" << searchKey1 << "': " << value1 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey1 << "' nao encontrada." << std::endl;
    }

    std::string searchKey2 = "cherry";
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
    
    myHashTable.display();

    std::cout << "\n--- Operacoes de Remocao ---" << std::endl;
    myHashTable.remove("banana");
    myHashTable.remove("grape");
    myHashTable.remove("kiwi");

    myHashTable.display();

    std::cout << "\n--- Busca apos remocao ---" << std::endl;
    std::string searchKey4 = "banana";
    int value4 = myHashTable.search(searchKey4);
    if (value4 != -1) {
        std::cout << "Valor de '" << searchKey4 << "': " << value4 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey4 << "' nao encontrada." << std::endl;
    }

    std::string searchKey5 = "cherry";
    int value5 = myHashTable.search(searchKey5);
    if (value5 != -1) {
        std::cout << "Valor de '" << searchKey5 << "': " << value5 << std::endl;
    } else {
        std::cout << "Chave '" << searchKey5 << "' nao encontrada." << std::endl;
    }

    return 0;
} */

// Tabela hash com std::unordered_map
/* #include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> myHashTable;

    std::cout << "--- Operacoes de Insercao ---" << std::endl;
    myHashTable["apple"] = 10;
    std::cout << "Chave 'apple' inserida com valor 10." << std::endl;
    myHashTable["banana"] = 20;
    std::cout << "Chave 'banana' inserida com valor 20." << std::endl;
    myHashTable["cherry"] = 30;
    std::cout << "Chave 'cherry' inserida com valor 30." << std::endl;
    myHashTable["grape"] = 40;
    std::cout << "Chave 'grape' inserida com valor 40." << std::endl;
    myHashTable["melon"] = 50;
    std::cout << "Chave 'melon' inserida com valor 50." << std::endl;
    myHashTable["apple"] = 15;
    std::cout << "Chave 'apple' atualizada para valor 15." << std::endl;

    std::cout << "\n--- Conteudo da Tabela Hash ---" << std::endl;
    for (const auto& pair : myHashTable) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;
    std::cout << "Tamanho atual da tabela: " << myHashTable.size() << std::endl;
    std::cout << "Numero de baldes: " << myHashTable.bucket_count() << std::endl;
    std::cout << "Fator de carga: " << myHashTable.load_factor() << std::endl;

    std::cout << "\n--- Operacoes de Busca ---" << std::endl;
    std::string searchKey1 = "banana";
    auto it1 = myHashTable.find(searchKey1);
    if (it1 != myHashTable.end()) {
        std::cout << "Valor de '" << searchKey1 << "': " << it1->second << std::endl;
    } else {
        std::cout << "Chave '" << searchKey1 << "' nao encontrada." << std::endl;
    }
    std::string searchKey2 = "orange";
    auto it2 = myHashTable.find(searchKey2);
    if (it2 != myHashTable.end()) {
        std::cout << "Valor de '" << searchKey2 << "': " << it2->second << std::endl;
    } else {
        std::cout << "Chave '" << searchKey2 << "' nao encontrada." << std::endl;
    }

    std::cout << "\n--- Operacoes de Remocao ---" << std::endl;
    myHashTable.erase("banana");
    std::cout << "Chave 'banana' removida." << std::endl;
    myHashTable.erase("kiwi");
    std::cout << "Tentando remover 'kiwi'." << std::endl;

    std::cout << "\n--- Conteudo da Tabela Hash apos remocao ---" << std::endl;
    for (const auto& pair : myHashTable) {
        std::cout << "[" << pair.first << ": " << pair.second << "] ";
    }
    std::cout << std::endl;
    std::cout << "Tamanho atual da tabela: " << myHashTable.size() << std::endl;

    std::cout << "\n--- Busca apos remocao ---" << std::endl;
    std::string searchKey3 = "banana";
    auto it3 = myHashTable.find(searchKey3);
    if (it3 != myHashTable.end()) {
        std::cout << "Valor de '" << searchKey3 << "': " << it3->second << std::endl;
    } else {
        std::cout << "Chave '" << searchKey3 << "' nao encontrada." << std::endl;
    }

    return 0;
} */

// Tabela hash com std::unordered_set
#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::unordered_set<std::string> myHashSet;

    std::cout << "--- Operacoes de Insercao ---" << std::endl;
    myHashSet.insert("apple");
    std::cout << "Chave 'apple' inserida." << std::endl;
    myHashSet.insert("banana");
    std::cout << "Chave 'banana' inserida." << std::endl;
    myHashSet.insert("cherry");
    std::cout << "Chave 'cherry' inserida." << std::endl;
    myHashSet.insert("grape");
    std::cout << "Chave 'grape' inserida." << std::endl;
    myHashSet.insert("melon");
    std::cout << "Chave 'melon' inserida." << std::endl;
    myHashSet.insert("apple");
    std::cout << "Tentando inserir 'apple' novamente (nao tera efeito, ja existe)." << std::endl;

    std::cout << "\n--- Conteudo do HashSet ---" << std::endl;
    for (const std::string& key : myHashSet) {
        std::cout << "[" << key << "] ";
    }
    std::cout << std::endl;
    std::cout << "Tamanho atual do set: " << myHashSet.size() << std::endl;
    std::cout << "Numero de baldes: " << myHashSet.bucket_count() << std::endl;
    std::cout << "Fator de carga: " << myHashSet.load_factor() << std::endl;

    std::cout << "\n--- Operacoes de Busca ---" << std::endl;
    std::string searchKey1 = "banana";
    auto it1 = myHashSet.find(searchKey1);
    if (it1 != myHashSet.end()) {
        std::cout << "Chave '" << searchKey1 << "' encontrada no set." << std::endl;
    } else {
        std::cout << "Chave '" << searchKey1 << "' nao encontrada no set." << std::endl;
    }
    std::string searchKey2 = "orange";
    auto it2 = myHashSet.find(searchKey2);
    if (it2 != myHashSet.end()) {
        std::cout << "Chave '" << searchKey2 << "' encontrada no set." << std::endl;
    } else {
        std::cout << "Chave '" << searchKey2 << "' nao encontrada no set." << std::endl;
    }

    std::cout << "\n--- Operacoes de Remocao ---" << std::endl;
    myHashSet.erase("banana");
    std::cout << "Chave 'banana' removida." << std::endl;
    myHashSet.erase("kiwi");
    std::cout << "Tentando remover 'kiwi'." << std::endl;

    std::cout << "\n--- Conteudo do HashSet apos remocao ---" << std::endl;
    for (const std::string& key : myHashSet) {
        std::cout << "[" << key << "] ";
    }
    std::cout << std::endl;
    std::cout << "Tamanho atual do set: " << myHashSet.size() << std::endl;

    std::cout << "\n--- Busca apos remocao ---" << std::endl;
    std::string searchKey3 = "banana";
    auto it3 = myHashSet.find(searchKey3);
    if (it3 != myHashSet.end()) {
        std::cout << "Chave '" << searchKey3 << "' encontrada no set." << std::endl;
    } else {
        std::cout << "Chave '" << searchKey3 << "' nao encontrada no set." << std::endl;
    }

    return 0;
}
