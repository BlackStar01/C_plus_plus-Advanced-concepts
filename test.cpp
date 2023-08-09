#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left_tree;
    Node *right_tree;

    //intialize the node
    Node(int val) : value(val), left_tree(nullptr), right_tree(nullptr) {};
};

// Insert a new node
void insert(const Node *my_tree, const int new_value) {
    if (my_tree == nullptr)
    {
        my_tree = new Node(new_value);
    }

    if(new_value < my_tree->value) {
        insert(my_tree->left_tree, new_value);
    }
    else if(new_value > my_tree->value) {
        insert(my_tree->right_tree, new_value);
    }
    else {
        cout << "Elément existant" << endl;
    }
}

// Compute the deep of a binary tree ...
int deep_tree(Node *tree) {
    int compt = 0;

    if(tree->left_tree != nullptr) {
        compt++;
    }
    else if(tree->right_tree != nullptr) {
        compt++;
    }
}

void display_node(Node *node) {

}

void display_binary_tree(Node *my_tree) {

}


int main() {

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
