#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "Node.h"

class ListaDuplaEncad
{
private:
    Node* head;
    Node* tail;

public:

    ListaDuplaEncad();

    void inserirElemento(int elemento);

    int acessarElemento(int indice);

    void removerElemento(int indice);

    void mostrarLista();

    void addVector(std::vector<int> vetor);

    int size();
};

