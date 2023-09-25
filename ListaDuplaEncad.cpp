#include "ListaDuplaEncad.h"

ListaDuplaEncad::ListaDuplaEncad() {
    this->head = nullptr;
    this->tail = nullptr;
}

void ListaDuplaEncad::inserirElemento(int elemento) {
    Node* newNode = new Node(elemento);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int ListaDuplaEncad::acessarElemento(int indice) {
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

void ListaDuplaEncad::removerElemento(int indice) {
    Node* current = head;
    int currentIndex = 0;

    while (current) {
        if (currentIndex == indice) {
            if (current->prev) {
                current->prev->next = current->next;
            }
            else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            else {
                tail = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
        currentIndex++;
    }

    std::cout << "Indice invalido.\n";
}

void ListaDuplaEncad::mostrarLista() {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void ListaDuplaEncad::addVector(std::vector<int> vetor) {
    for (int elemento : vetor) {
        inserirElemento(elemento);
    }
}

int ListaDuplaEncad::size() {
    Node* current = head;
    int size = 0;
    while (current) {
        size++;
        current = current->next;
    }

    return size;
}
