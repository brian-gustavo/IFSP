// Baseado no exerc�cio 4J, cap�tulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>
#include <cmath>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int valor1, valor2, valor_final;

    std::cout << "Informe um valor: "; std::cin >> valor1;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe um segundo valor: "; std::cin >> valor2;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    valor_final = pow((valor1 - valor2), 2);

    std::cout << "Quadrado da diferen�a dos valores = " << valor_final << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
