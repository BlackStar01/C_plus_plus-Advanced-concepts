#include <iostream>
using namespace std;

struct Element {
    int value;
    Element *next;
    Element *last;

    Element(int val): value(val), next(nullptr), last(nullptr) {};
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
        stack->first->last = nullptr;
    }
    else {
        element->next = stack->first;
        stack->first->last = element; 
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

/* #include <iostream>
#include <functional>
#include <chrono>

int add(int a, int b) {
    return a + b;
};

int modulo(int a, int b) {
    return a % b;
};

int operation(std::function<int(int, int)> func, int x, int y) {
    return func(x, y);
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    int a = 5;
    int b = 10;

    std::cout << operation(modulo, a, b);
    std::cout << operation(add, a, b);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    std::cout << "\n\nTemps d'exécution : " << duration << " microsecondes" << std::endl;
    return 0;
} */