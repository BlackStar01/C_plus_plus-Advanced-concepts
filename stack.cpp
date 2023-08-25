#include <iostream>
using namespace std;

struct Stack
{
    Element *first;
    Stack(Element element) :  first(nullptr) {};
};

struct Element {
    int value;
    Element *next;

    Element(int val): value(val) {};
};

void add(Stack * stack, int value) {
    struct Element element(value);
    cout << "Ajout de " << value << endl;
    if (stack->first == nullptr )
    {
        stack->first = &element;
    }
    else {
        stack->first->next = &element;
        stack->first = stack->first->next;
    }
}

void display_stack(Stack *stack) {
    cout << stack->first->value << " -> ";
}

