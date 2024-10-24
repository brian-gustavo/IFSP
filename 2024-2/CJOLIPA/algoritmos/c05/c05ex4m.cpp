// Baseado no exercício 4M, capítulo 5 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    float valor, media, soma = 0;
    int contador = 1;

    do
    {
        std::cout << "Insira um valor: "; std::cin >> valor;
        std::cin.ignore(80, '\n');
        std::cout << std::endl;

        soma += valor;
        contador++;
    }
    while (not(contador > 10));

    media = soma / 10;

    std::cout << "Somatório dos valores = " << soma << std::endl;
    std::cout << "Média dos valores = " << media << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
