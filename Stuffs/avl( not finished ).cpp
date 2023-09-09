/* 
    arbre binaire de recherche équilibré (AVL)
    10, 20, 30, 25, 5 et 3 
    https://cours.etsmtl.ca/SEG/FHenri/inf145/Suppl%C3%A9ments/arbres%20AVL.htm
    https://www.youtube.com/watch?v=zP2xbKerIds&ab_channel=MaanethDeSilva
*/

#include <iostream>
using namespace std;

struct Node {
    int value;
    int height;
    float balance_factor;
    Node *left_node;
    Node *right_node;

    Node(int val) : value(val), height(0), balance_factor(1), left_node(nullptr), right_node(nullptr) {};
};

void insert(Node *my_tree, int new_value) {
    Node *new_node = new Node(new_value);
    if(my_tree == nullptr) {
        Node *my_tree = new Node(new_value);
    }
    if (new_value < my_tree->value)
    {
        my_tree->left_node == nullptr ? my_tree->left_node = new_node;
    }

}

Node *rotateLeft(Node *my_node) {

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
