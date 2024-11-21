// Baseado no exercício 6B, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int numero, resultado;

    std::cout << "Insira o número do qual se deseja obter a tabuada: "; std::cin >> numero;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    for (int contador = 1; contador <= 10; ++contador)
    {
        resultado = numero * contador;
        std::cout << numero << " x " << contador << " = " << resultado << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
