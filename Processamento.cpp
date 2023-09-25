#include "Processamento.h"

long long Processamento::randomTimer() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>intDistribution(0, 10);
    return (long long)intDistribution(gen);
}

void Processamento::processaVetor(std::vector<int> vetor1, std::vector<int> vetor2, std::vector<int> vetor3, std::vector<int> vetor4) {
    for (int i : vetor1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "Valor processado Vetor: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(randomTimer()));
        std::cout << "Pagamento Concluido...V " << std::endl;
    }

    for (int i : vetor2) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "Valor processado Vetor: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(randomTimer()));
        std::cout << "Pagamento Concluido...V " << std::endl;
    }

    for (int i : vetor3) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "Valor processado Vetor: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(randomTimer()));
        std::cout << "Pagamento Concluido...V " << std::endl;
    }

    for (int i : vetor4) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "Valor processado Vetor: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(randomTimer()));
        std::cout << "Pagamento Concluido...V " << std::endl;
    }
}

void Processamento::processaListaSimples(ListaSimplesEncad simples1, ListaSimplesEncad simples2, ListaSimplesEncad simples3, ListaSimplesEncad simples4) {
    for (int i = 0; i < simples1.size(); i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "Valor processado S: " << simples1.acessarElemento(i) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(randomTimer()));
        std::cout << "Pagamento Concluido...S " << std::endl;
    }

    for (int i = 0; i < simples2.size(); i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "Valor processado S: " << simples2.acessarElemento(i) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(randomTimer()));
        std::cout << "Pagamento Concluido...S " << std::endl;
    }

    for (int i = 0; i < simples3.size(); i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "Valor processado S: " << simples3.acessarElemento(i) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(randomTimer()));
        std::cout << "Pagamento Concluido...S " << std::endl;
    }

    for (int i = 0; i < simples4.size(); i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "Valor processado S: " << simples4.acessarElemento(i) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(randomTimer()));
        std::cout << "Pagamento Concluido...S " << std::endl;
    }
}

void Processamento::processaListaDupla(ListaDuplaEncad dupla1, ListaDuplaEncad dupla2, ListaDuplaEncad dupla3, ListaDuplaEncad dupla4) {
    for (int i = 0; i < dupla1.size(); i++) {
        std::cout << "Valor processado D: " << dupla1.acessarElemento(i) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(randomTimer()));
        std::cout << "Pagamento Concluido... " << std::endl;
    }

    for (int i = 0; i < dupla2.size(); i++) {
        std::cout << "Valor processado D: " << dupla2.acessarElemento(i) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(randomTimer()));
        std::cout << "Pagamento Concluido... " << std::endl;
    }

    for (int i = 0; i < dupla3.size(); i++) {
        std::cout << "Valor processado D: " << dupla3.acessarElemento(i) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(randomTimer()));
        std::cout << "Pagamento Concluido... " << std::endl;
    }

    for (int i = 0; i < dupla4.size(); i++) {
        std::cout << "Valor processado D: " << dupla4.acessarElemento(i) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(randomTimer()));
        std::cout << "Pagamento Concluido... " << std::endl;
    }
}


