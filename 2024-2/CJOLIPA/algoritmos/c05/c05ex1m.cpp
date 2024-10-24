// Baseado no exercício 1M, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    float numero, media, soma = 0;
    int contador = 1;

    while (contador <= 10)
    {
        std::cout << "Insira o " << contador << "o. valor: "; std::cin >> numero;
        std::cin.ignore(80, '\n');

        soma += numero;
        contador++;
    }

    media = soma / 10;

    std::cout << std::endl;
    std::cout << "Somatório dos valores = " << soma << std::endl;
    std::cout << "Média dos valores = " << media << std::endl;

    std::cout << std::endl;
    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
