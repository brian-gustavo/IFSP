// Baseado no exercício 4A, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    float celsius, fahrenheit;

    std::cout << "Informe temperatura em graus Celsius: "; std::cin >> celsius;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    fahrenheit = celsius * 9 / 5 + 32;

    std::cout << "Valor em graus Fahrenheit = " << fahrenheit << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
