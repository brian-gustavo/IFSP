// Baseado no exercício 1V, capítulo 6 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int contador, resto, totalpares = 0, totalimpares = 0;
    int a[30];

    for (contador = 0; contador <= 29; ++contador)
    {
        std::cout << "Informe o " << contador + 1 << "o. valor da matriz: ";
        std::cin >> a[contador];
        std::cin.ignore(80, '\n');
    }

    for (contador = 0; contador <= 29; ++contador)
    {
        resto = a[contador] - 2 * (a[contador] / 2);
        if (resto == 0)
            totalpares++;
        else
            totalimpares++;
    }

    std::cout << std::endl;
    std::cout << "Total de valores pares presentes na matriz = " << totalpares << std::endl;
    std::cout << "Total de valores ímpares presentes na matriz = " << totalimpares << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
