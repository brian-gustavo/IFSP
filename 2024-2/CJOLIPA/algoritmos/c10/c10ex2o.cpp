// Baseado no exercício 2O, capítulo 10 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

void fatoracao(int valor)
{
   int fatorial = 1;

   for (int contador = 1; contador <= valor; ++contador)
       fatorial *= contador;

   std::cout << "Fatorial do valor inserido = " << fatorial << std::endl;
}

int main(void)
{
    int numero;

    std::cout << "Insira um valor: "; std::cin >> numero;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    fatoracao(numero);

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
