// Baseado no exerc�cio 4K, cap�tulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    float carteira, cotacao, conversao;

    std::cout << "Informe a quantidade de d�lares que voc� possui: "; std::cin >> carteira;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe a atual cota��o do d�lar: "; std::cin >> cotacao;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    conversao = carteira * cotacao;

    std::cout << "Convers�o em reais = " << conversao << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
