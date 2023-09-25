#include "Node.h"

Node::Node(int value) {
    this->data = value;
    this->prev = nullptr;
    this->next = nullptr;
}
