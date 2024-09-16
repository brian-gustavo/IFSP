// Baseado no exercício 4E, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    float valor, taxa, tempo, prestacao;

    std::cout << "Informe o valor total do bem: "; std::cin >> valor;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe a taxa de cobrança: "; std::cin >> taxa;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe o tempo de atraso: "; std::cin >> tempo;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    prestacao = valor + (valor * (taxa / 100) * tempo);

    std::cout << "Prestação a ser paga = " << prestacao << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
