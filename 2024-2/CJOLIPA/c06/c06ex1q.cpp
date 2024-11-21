// Baseado no exercício 1Q, capítulo 6 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int contador, resto;
    float a[15], b[15];

    for (contador = 0; contador <= 14; ++contador)
    {
        std::cout << "Informe o " << contador + 1 << "o. valor da matriz: ";
        std::cin >> a[contador];
        std::cin.ignore(80, '\n');
    }

    for (contador = 0; contador <= 14; ++contador)
    {
        resto = contador - 2 * (contador / 2);
        if (resto == 0)
            b[contador] = a[contador] / 2;
        else
            b[contador] = a[contador] * 1.5;
    }

    std::cout << std::endl;
    for (contador = 0; contador <= 14; ++contador)
    {
        std::cout << contador + 1 << "o. valor da nova matriz = " << b[contador] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
