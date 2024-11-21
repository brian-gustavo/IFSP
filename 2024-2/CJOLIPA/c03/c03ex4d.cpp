// Baseado no exercício 4D, capítulo 3 do livro "Algoritmos", escrito pelo prof. Augusto Manzano.

#include <iostream>

int main(void)
{
    setlocale(LC_ALL, ".1252");

    float tempo, velocidade, distancia, litros_usados;

    std::cout << "Informe o tempo de viagem: "; std::cin >> tempo;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    std::cout << "Informe a velocidade média do veículo durante a viagem: "; std::cin >> velocidade;
    std::cin.ignore(80, '\n');
    std::cout << std::endl;

    distancia = tempo * velocidade;
    litros_usados = distancia / 12;

    std::cout << "Tempo de viagem: " << tempo << std::endl;
    std::cout << "Velocidade média: " << velocidade << std::endl;
    std::cout << "Distância percorrida: " << distancia << std::endl;
    std::cout << "Litros de combustível utilizados: " << litros_usados << std::endl;
    std::cout << std::endl;

    std::cout << "Tecle <Enter> para encerrar... ";
    std::cin.get();
    return 0;
}
