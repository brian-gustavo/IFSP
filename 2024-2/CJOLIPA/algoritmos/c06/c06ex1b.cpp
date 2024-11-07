// Baseado no exercício 1B, capítulo 6 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int contador;
    float a[8], b[8];

    for (contador = 0; contador <= 7; ++contador)
    {
        std::cout << "Informe o " << contador + 1 << "o. valor da matriz: ";
        std::cin >> a[contador];
        std::cin.ignore(80, '\n');
    }
    std::cout << std::endl;

    for (contador = 0; contador <= 7; ++contador)
        b[contador] = a[contador] * 3;

    std::cout << "Elementos da nova matriz: " << std::endl;
    for (contador = 0; contador <= 7; ++contador)
        std::cout << b[contador] << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
