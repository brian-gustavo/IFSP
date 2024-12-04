// Baseado no exercício 1N, capítulo 8 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int contador1, contador2, resto, paridade = 0;
    int a[7][7];

    for (contador1 = 0; contador1 <= 6; ++contador1)
    {
        for (contador2 = 0; contador2 <= 6; ++contador2)
        {
            std::cout << "Informe o valor da coluna " << contador2 + 1 << ", linha " << contador1 + 1 << " da matriz: ";
            std::cin >> a[contador1][contador2];
            std::cin.ignore(80, '\n');
        }
    }

    for (contador1 = 0; contador1 <= 6; ++contador1)
    {
        for (contador2 = 0; contador2 <= 6; ++contador2)
        {
            resto = a[contador1][contador2] - 2 * (a[contador1][contador2] / 2);
            if (resto == 0)
                paridade++;
        }
    }
    std::cout << std::endl;

    std::cout << "Quantidade de pares na matriz = " << paridade << std::endl << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
