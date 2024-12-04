// Baseado no exercício 1A, capítulo 7 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int contador1, contador2, trocador;
    int a[12];

    for (contador1 = 0; contador1 <= 11; ++contador1)
    {
        std::cout << "Insira o " << contador1 + 1 << "o. elemento da matriz: "; std::cin >> a[contador1];
        std::cin.ignore(80, '\n');
    }

    for (contador1 = 0; contador1 <= 10; ++contador1)
    {
        for (contador2 = (contador1 + 1); contador2 <= 11; ++contador2)
        {
            if (a[contador1] < a[contador2])
            {
                trocador = a[contador1];
                a[contador1] = a[contador2];
                a[contador2] = trocador;
            }
        }
    }
    std::cout << std::endl;

    for (contador1 = 0; contador1 <= 11; ++contador1)
        std::cout << contador1 + 1 << "o. elemento da matriz, em ordem decrescente = " << a[contador1] << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
