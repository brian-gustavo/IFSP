// Baseado no exercício 2E, capítulo 10 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

void paridade(int valor)
{
   int resto;

   resto = valor - 2 * (valor / 2);

   if (resto == 0)
    std::cout << valor << " é par." << std::endl;
   else
    std::cout << valor << " é ímpar." << std::endl;
}

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int numero;

    std::cout << "Insira um valor: "; std::cin >> numero;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    paridade(numero);

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
