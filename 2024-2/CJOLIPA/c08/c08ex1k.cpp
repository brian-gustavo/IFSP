// Baseado no exercício 1K, capítulo 8 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int contador1, contador2, somatorio = 0;
    int a[5][5];

    for (contador1 = 0; contador1 <= 4; ++contador1)
    {
        for (contador2 = 0; contador2 <= 4; ++contador2)
        {
            std::cout << "Informe o valor da coluna " << contador2 + 1 << ", linha " << contador1 + 1 << " da matriz: ";
            std::cin >> a[contador1][contador2];
            std::cin.ignore(80, '\n');
        }
    }

    for (contador1 = 0; contador1 <= 4; ++contador1)
    {
        for (contador2 = 0; contador2 <= 4; ++contador2)
        {
            if (contador1 == contador2)
                somatorio += a[contador1][contador2];
        }
    }
    std::cout << std::endl;

    std::cout << "Soma dos elementos da diagonal principal = " << somatorio << std::endl << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
