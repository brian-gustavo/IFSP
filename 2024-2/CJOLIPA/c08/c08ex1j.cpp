// Baseado no exercício 1J, capítulo 8 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int contador1, contador2, resto;
    int a[6][5], b[6][5];

    for (contador1 = 0; contador1 <= 5; ++contador1)
    {
        for (contador2 = 0; contador2 <= 4; ++contador2)
        {
            std::cout << "Informe o valor da coluna " << contador2 + 1 << ", linha " << contador1 + 1 << " da matriz: ";
            std::cin >> a[contador1][contador2];
            std::cin.ignore(80, '\n');
        }
    }

    for (contador1 = 0; contador1 <= 5; ++contador1)
    {
        for (contador2 = 0; contador2 <= 4; ++contador2)
        {
            resto = a[contador1][contador2] - 2 * (a[contador1][contador2] / 2);
            if (resto == 0)
                b[contador1][contador2] = a[contador1][contador2] + 5;
            else
                b[contador1][contador2] = a[contador1][contador2] - 4;
        }
    }
    std::cout << std::endl;

    for (contador1 = 0; contador1 <= 5; ++contador1)
    {
        for (contador2 = 0; contador2 <= 4; ++contador2)
        {
            std::cout << "Valor da coluna " << contador2 + 1 << ", linha " << contador1 + 1 << " da matriz original = " << a[contador1][contador2];
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    for (contador1 = 0; contador1 <= 5; ++contador1)
    {
        for (contador2 = 0; contador2 <= 4; ++contador2)
        {
            std::cout << "Valor da coluna " << contador2 + 1 << ", linha " << contador1 + 1 << " da nova matriz = " << b[contador1][contador2];
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
