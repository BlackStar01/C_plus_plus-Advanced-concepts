#include <iostream>
using namespace std;

struct Element {
    int value;
    Element *next;

    Element(int val): value(val), next(nullptr) {};
};

struct Stack
{
    Element *first;
};

void add(Stack * stack, int value) {
    Element *element = new Element(value);
    cout << "Ajout de " << value << endl;
    if (stack->first == nullptr )
    {
        stack->first = element;
        /* stack->first->last = nullptr; */
    }
    else {
        element->next = stack->first;
        /* stack->first->last = element; */ 
        stack->first = element;
    }
}

void display_stack(Stack *stack) {
    cout << " MA PILE " << endl;
    if (stack->first == nullptr) {
        cout << " Empty " << endl;
    }
    while (stack->first != nullptr)
    {
        cout << stack->first->value << " <- ";
        stack->first = stack->first->next;
    }
    cout << " NULL " << endl;
    
}

int main() {

    Stack *my_stack = new Stack();
    add(my_stack, 7);
    add(my_stack, 6);
    add(my_stack, 5);

    display_stack(my_stack);

    //cout << deep_tree(my_tree);

    return 0;
}
