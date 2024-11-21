// Baseado no exercício 1L, capítulo 6 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int contador;
    float a[10], b[10];

    for (contador = 0; contador <= 9; ++contador)
    {
        std::cout << "Informe o " << contador + 1 << "o. valor da matriz: ";
        std::cin >> a[contador];
        std::cin.ignore(80, '\n');
    }
    std::cout << std::endl;

    for (contador = 0; contador <= 9; ++contador)
        b[contador] = a[contador] / 2;

    std::cout << "Elementos da primeira matriz: " << std::endl;
    for (contador = 0; contador <= 9; ++contador)
        std::cout << a[contador] << std::endl;
    std::cout << std::endl;

    std::cout << "Elementos da segunda matriz: " << std::endl;
    for (contador = 0; contador <= 9; ++contador)
        std::cout << b[contador] << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
