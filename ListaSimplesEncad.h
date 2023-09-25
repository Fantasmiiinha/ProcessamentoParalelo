#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "Node.h"

class ListaSimplesEncad
{
private:
    Node* head;

public:

    ListaSimplesEncad();

    void inserirElemento(int elemento);

    int acessarElemento(int indice);

    void removerElemento(int indice);

    void mostrarLista();

    void addVector(std::vector<int> vetor);

    int size();
};

