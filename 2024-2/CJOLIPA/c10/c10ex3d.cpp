// Baseado no exercício 3D, capítulo 10 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

void exponenciacao(int valor1, int valor2, int &valor3)
{
   valor3 = 1;

   for (int contador = 0; contador <= (valor2 - 1); ++contador)
       valor3 *= valor1;
}

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int base, expoente, resultado;

    std::cout << "Insira a base: "; std::cin >> base;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Insira o expoente: "; std::cin >> expoente;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    exponenciacao(base, expoente, resultado);

    std::cout << "Resultado da exponenciação = " << resultado << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
