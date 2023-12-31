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

void display_node(Node *node, int indent = 0) {
    if (node == nullptr) {
        return;
    }

    // Display the node's value within proper formatting
    cout << string(indent, ' ') << "         ---" << endl;
    cout << string(indent, ' ') << "Niveau " << indent/10 + 1 << " |" << node->value << "|" << endl;
    cout << string(indent, ' ') << "         ---" << endl;

    // Recursively display left and right subtrees
    display_node(node->left_tree, indent + 10);
    display_node(node->right_tree, indent + 10);
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

    display_node(my_tree);

    //cout << deep_tree(my_tree);

    return 0;
}