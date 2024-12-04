// Baseado no exercício 1S, capítulo 8 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int contador1, contador2, resto;
    int a[5][6], b[5][6], c[5][6];

    for (contador1 = 0; contador1 <= 4; ++contador1)
    {
        for (contador2 = 0; contador2 <= 5; ++contador2)
        {
            do
            {
                std::cout << "Informe o valor da coluna " << contador2 + 1 << ", linha " << contador1 + 1 << " da primeira matriz: ";
                std::cin >> a[contador1][contador2];
                std::cin.ignore(80, '\n');

                resto = a[contador1][contador2] - 2 * (a[contador1][contador2] / 2);
            }
            while (not(resto == 0));
        }
    }
    std::cout << std::endl;

    for (contador1 = 0; contador1 <= 4; ++contador1)
    {
        for (contador2 = 0; contador2 <= 5; ++contador2)
        {
            do
            {
                std::cout << "Informe o valor da coluna " << contador2 + 1 << ", linha " << contador1 + 1 << " da segunda matriz: ";
                std::cin >> b[contador1][contador2];
                std::cin.ignore(80, '\n');

                resto = b[contador1][contador2] - 2 * (b[contador1][contador2] / 2);
            }
            while (not(resto != 0));
        }
    }

    for (contador1 = 0; contador1 <= 4; ++contador1)
    {
        for (contador2 = 0; contador2 <= 5; ++contador2)
            c[contador1][contador2] = a[contador1][contador2] + b [contador1][contador2];
    }
    std::cout << std::endl;

    for (contador1 = 0; contador1 <= 4; ++contador1)
    {
        for (contador2 = 0; contador2 <= 5; ++contador2)
        {
            std::cout << "Valor da coluna " << contador2 + 1 << ", linha " << contador1 + 1 << " da matriz resultante = " << c[contador1][contador2];
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
