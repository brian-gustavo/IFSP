// Baseado no exercício 4B, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    float fahrenheit, celsius;

    std::cout << "Informe temperatura em graus Fahrenheit: "; std::cin >> fahrenheit;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    celsius = ((fahrenheit - 32) * 5) / 9;

    std::cout << "Valor em graus Celsius = " << celsius << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}

