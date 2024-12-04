// Baseado no exercício 1D, capítulo 6 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <cmath>

int main(void)
{
    int contador;
    int a[15], b[15];

    for (contador = 0; contador <= 14; ++contador)
    {
        std::cout << "Informe o " << contador + 1 << "o. valor da matriz: ";
        std::cin >> a[contador];
        std::cin.ignore(80, '\n');
    }
    std::cout << std::endl;

    for (contador = 0; contador <= 14; ++contador)
        b[contador] = pow(a[contador], 2);

    std::cout << "Elementos da nova matriz: " << std::endl;
    for (contador = 0; contador <= 14; ++contador)
        std::cout << b[contador] << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
