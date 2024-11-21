// Baseado no exercício 1B, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int numero, resultado, contador = 1;

    std::cout << "Insira o número do qual se deseja obter a tabuada: "; std::cin >> numero;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    while (contador <= 10)
    {
        resultado = numero * contador;
        std::cout << numero << " x " << contador << " = " << resultado << std::endl;
        contador++;
    }

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
