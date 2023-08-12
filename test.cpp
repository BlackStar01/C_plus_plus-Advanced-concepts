#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left_tree;
    Node *right_tree;
    int deep;

    //intialize the node
    Node(int val) : value(val), left_tree(nullptr), right_tree(nullptr), deep(0) {};
};

// Insert a new node
Node *insert(Node *my_tree, const int new_value) {
    
    if (my_tree == nullptr)
    {
        cout << "Tree creation ..." << my_tree->value << endl;
        my_tree = new Node(new_value);
    }
    Node *my_node = new Node(new_value);

    auto print_step = [my_tree, new_value]() {
        cout << "Inserting ... " << new_value << endl;
        cout << "Parent node = "  << my_tree->value << endl << endl;
    };

    if(new_value < my_tree->value) {
        
        if(my_tree->left_tree == nullptr) {
            print_step();
            my_tree->left_tree = my_node;
            return my_tree; 
        }
        insert(my_tree->left_tree, new_value); 
    }
    else if(new_value > my_tree->value) {
        if(my_tree->right_tree == nullptr) {
            print_step();
            my_tree->right_tree = my_node;
            return my_tree;
        }
        insert(my_tree->right_tree, new_value);
    }
    else if(new_value == my_tree->value) {
        print_step();
        cout << "Élément existant..." << endl;
    }
    return my_tree;
}

// Compute the deep of a binary tree ...
int deep_tree(Node *tree) {
    if(tree->left_tree != nullptr) {
        tree->deep++;
        deep_tree(tree->left_tree);
    }
    else if(tree->right_tree != nullptr) {
        tree->deep++;
        deep_tree(tree->right_tree);
    }
    cout << " Deep = " << tree->deep;
    return tree->deep;
}

void display_node(Node *node) {

}

void display_binary_tree(Node *my_tree) {

}


int main() {

    Node *my_tree = new Node(8);

    my_tree = insert(my_tree, 3);
    my_tree = insert(my_tree, 10);
    my_tree = insert(my_tree, 1);
    my_tree = insert(my_tree, 6);
    my_tree = insert(my_tree, 14);
    my_tree = insert(my_tree, 4);
    my_tree = insert(my_tree, 7);
    my_tree = insert(my_tree, 13);
    my_tree = insert(my_tree, 22);

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
