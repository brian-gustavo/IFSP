// Baseado no exercício 4F, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    int valor1, valor2, trocador;

    std::cout << "Informe um valor: "; std::cin >> valor1;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um segundo valor: "; std::cin >> valor2;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    trocador = valor2;
    valor2 = valor1;
    valor1 = trocador;

    std::cout << "Valores trocados = " << valor1 << ", " << valor2 << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
