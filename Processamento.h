#pragma once
#include<chrono>
#include<thread>
#include<random>
#include "ListaDuplaEncad.h"
#include "ListaSimplesEncad.h"

class Processamento
{
public:
    long long randomTimer();

    void processaVetor(std::vector<int> vetor1, std::vector<int> vetor2, std::vector<int> vetor3, std::vector<int> vetor4);
    void processaListaDupla(ListaDuplaEncad dupla1, ListaDuplaEncad dupla2, ListaDuplaEncad dupla3, ListaDuplaEncad dupla4);
    void processaListaSimples(ListaSimplesEncad simples1, ListaSimplesEncad simples2, ListaSimplesEncad simples3, ListaSimplesEncad simples4);
};

