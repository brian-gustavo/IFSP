// Baseado no exercício 1G, capítulo 6 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <string>

int main(void)
{
    int contador;
    std::string a[20], b[30], c[50];

    for (contador = 0; contador <= 19; ++contador)
    {
        std::cout << "Informe o " << contador + 1 << "o. nome da matriz 1: ";
        std::cin >> a[contador];
        std::cin.ignore(80, '\n');
    }
    std::cout << std::endl;

    for (contador = 0; contador <= 29; ++contador)
    {
        std::cout << "Informe o " << contador + 1 << "o. nome da matriz 2: ";
        std::cin >> b[contador];
        std::cin.ignore(80, '\n');
    }
    std::cout << std::endl;

    for (contador = 0; contador <= 49; ++contador)
        if (contador > 19)
            c[contador] = b[contador - 20];
        else
            c[contador] = a[contador];

    std::cout << "Elementos da matriz resultante: " << std::endl;
    for (contador = 0; contador <= 49; ++contador)
        std::cout << c[contador] << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
