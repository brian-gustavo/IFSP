// Baseado no exercício 4K, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    float carteira, cotacao, conversao;

    std::cout << "Informe a quantidade de dólares que você possui: "; std::cin >> carteira;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe a atual cotação do dólar: "; std::cin >> cotacao;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    conversao = carteira * cotacao;

    std::cout << "Conversão em reais = " << conversao << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
