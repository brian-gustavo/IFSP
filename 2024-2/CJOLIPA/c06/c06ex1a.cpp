// Baseado no exercício 1A, capítulo 6 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <string>

int main(void)
{
    int contador;
    std::string nome[10];

    for (contador = 0; contador <= 9; ++contador)
    {
        std::cout << "Informe o " << contador + 1 << "o. nome: ";
        getline(std::cin, nome[contador]);
    }
    std::cout << std::endl;

    for (contador = 0; contador <= 9; ++contador)
        std::cout << contador + 1 << "o. nome: " << nome[contador] << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
