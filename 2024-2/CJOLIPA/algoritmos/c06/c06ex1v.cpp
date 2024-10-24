// Baseado no exerc�cio 1V, cap�tulo 6 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int contador, resto, totalpares = 0, totalimpares = 0;
    int a[30];

    for (contador = 1; contador <= 30; ++contador)
    {
        std::cout << "Informe o " << contador << "o. valor da matriz: ";
        std::cin >> a[contador];
        std::cin.ignore(80, '\n');
    }

    for (contador = 1; contador <= 30; ++contador)
    {
        resto = a[contador] - 2 * (a[contador] / 2);
        if (resto == 0)
            totalpares++;
        else
            totalimpares++;
    }

    std::cout << std::endl;
    std::cout << "Total de valores pares presentes na matriz = " << totalpares << std::endl;
    std::cout << "Total de valores �mpares presentes na matriz = " << totalimpares << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
