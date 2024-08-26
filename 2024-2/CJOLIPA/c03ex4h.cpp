// Baseado no exercício 4H, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    float volume, comprimento, largura, altura;

    std::cout << "Informe o comprimento da caixa: "; std::cin >> comprimento;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe a largura da caixa: "; std::cin >> largura;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe a altura da caixa: "; std::cin >> altura;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    volume = comprimento * largura * altura;

    std::cout << "Volume da caixa = " << volume << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
