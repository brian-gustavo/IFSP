// Baseado no exercício 2B, capítulo 10 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

void somatorio(int ultimo)
{
   int soma = 0;

   for (int contador = 1; contador <= ultimo; contador++)
        soma = soma + contador;

   std::cout << "Somatório = " << soma << std::endl;
}

int main(void)
{
    setlocale(LC_ALL, ".1252");

    int numero;

    std::cout << "Insira o valor de encerramento do somatório: "; std::cin >> numero;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    somatorio(numero);

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
