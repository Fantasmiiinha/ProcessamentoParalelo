#include "ListaSimplesEncad.h"

ListaSimplesEncad::ListaSimplesEncad() {
    this->head = nullptr;
}

void ListaSimplesEncad::inserirElemento(int elemento) {
    Node* newNode = new Node(elemento);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }
}

int ListaSimplesEncad::acessarElemento(int indice) {
    Node* current = head;
    int currentIndex = 0;

    while (current) {
        if (currentIndex == indice) {
            return current->data;
        }
        current = current->next;
        currentIndex++;
    }

    std::cout << "Indice invalido.\n";
    return -1; // Valor inválido para indicar erro
}

void ListaSimplesEncad::removerElemento(int indice) {
    Node* current = head;
    int currentIndex = 0;

    if (head == nullptr) {
        return;
    }

    while (current) {
        if (indice == 0) {
            head = current->next;
            delete current;
            return;
        }

        Node* nodeAtras;
        if (currentIndex == indice - 1) {
            nodeAtras = current;
        }

        if (currentIndex == indice) {

            if (current->next) {
                nodeAtras = current->next;
            }

            delete current;
            return;
        }
        current = current->next;
        currentIndex++;
    }

    std::cout << "Indice invalido.\n";
}

void ListaSimplesEncad::mostrarLista() {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void ListaSimplesEncad::addVector(std::vector<int> vetor) {
    for (int elemento : vetor) {
        inserirElemento(elemento);
    }
}

int ListaSimplesEncad::size() {
    Node* current = head;
    int size = 0;
    while (current) {
        size++;
        current = current->next;
    }

    return size;
}
