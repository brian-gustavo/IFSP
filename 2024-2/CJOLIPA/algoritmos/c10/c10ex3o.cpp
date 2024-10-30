// Baseado no exercício 3O, capítulo 10 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

void fatoracao(int valor, int &fatorial)
{
   fatorial = 1;

   for (int contador = 1; contador <= valor; ++contador)
       fatorial *= contador;
}

int main(void)
{
    int numero, resultado;

    std::cout << "Insira um valor: "; std::cin >> numero;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    fatoracao(numero, resultado);

    std::cout << "Fatorial do valor inserido = " << resultado << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
