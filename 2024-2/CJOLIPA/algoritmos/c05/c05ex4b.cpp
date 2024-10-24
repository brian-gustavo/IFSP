// Baseado no exercício 4B, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int numero, resultado, contador = 1;

    std::cout << "Insira o número do qual se deseja obter a tabuada: "; std::cin >> numero;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    do
    {
        resultado = numero * contador;
        std::cout << numero << " x " << contador << " = " << resultado << std::endl;
        contador++;
    }
    while (not(contador > 10));

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
