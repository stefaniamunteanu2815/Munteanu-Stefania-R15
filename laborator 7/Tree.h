#pragma once
template <typename T>
struct Node 
{
    T value;
    Node<T>** children;
    int num_children;
    int capacity;

    Node(T val) : value(val), num_children(0), capacity(2) 
    {
        children = new Node<T>*[capacity];
    }

    void add_child(Node<T>* child) 
    {
        if (num_children == capacity) 
        {
            capacity *= 2;
            Node<T>** new_list = new Node<T>*[capacity];
            for (int i = 0; i < num_children; i++) new_list[i] = children[i];
            delete[] children;
            children = new_list;
        }
        children[num_children++] = child;
    }
};

template <typename T>
class Tree 
{
    Node<T>* root;
    void delete_recursive(Node<T>* node) 
    {
        if (!node) return;
        for (int i = 0; i < node->num_children; i++) 
        {
            delete_recursive(node->children[i]);
        }
        delete[] node->children;
        delete node;
    }

    int count_recursive(Node<T>* node) const 
    {
        if (!node) return 0;
        int c = 1;
        for (int i = 0; i < node->num_children; i++) 
        {
            c += count_recursive(node->children[i]);
        }
        return c;
    }

    Node<T>* find_recursive(Node<T>* node, bool (*compare)(T)) 
    {
        if (!node) return nullptr;
        if (compare(node->value)) return node;
        for (int i = 0; i < node->num_children; i++) 
        {
            Node<T>* res = find_recursive(node->children[i], compare);
            if (res) return res;
        }
        return nullptr;
    }

public:
    Tree() : root(nullptr) {}
    ~Tree() { delete_recursive(root); }

    Node<T>* add_node(Node<T>* parent, T value) 
    {
        Node<T>* newNode = new Node<T>(value);
        if (!parent) 
        {
            if (!root) root = newNode;
        }
        else {
            parent->add_child(newNode);
        }
        return newNode;
    }

    Node<T>* get_node(Node<T>* parent) 
    {
        return (parent == nullptr) ? root : parent;
    }

    void delete_node(Node<T>* node) 
    {
        if (node == root) 
        {
            delete_recursive(root);
            root = nullptr;
        }
        else {
            delete_recursive(node);
        }
    }

    void insert(Node<T>* parent, int index, T value) 
    {
        if (!parent || index < 0 || index > parent->num_children) return;
        Node<T>* newNode = new Node<T>(value);
        if (parent->num_children == parent->capacity) 
        {
            parent->capacity *= 2;
            Node<T>** new_list = new Node<T>*[parent->capacity];
            for (int i = 0; i < parent->num_children; i++) new_list[i] = parent->children[i];
            delete[] parent->children;
            parent->children = new_list;
        }

        for (int i = parent->num_children; i > index; i--) 
        {
            parent->children[i] = parent->children[i - 1];
        }
        parent->children[index] = newNode;
        parent->num_children++;
    }
    void sort(Node<T>* node, bool (*compare)(T, T) = nullptr) 
    {
        if (!node || node->num_children < 2) return;
        for (int i = 0; i < node->num_children - 1; i++) 
        {
            for (int j = 0; j < node->num_children - i - 1; j++) 
            {
                bool swap_needed = false;
                if (compare) 
                {
                    if (!compare(node->children[j]->value, node->children[j + 1]->value)) swap_needed = true;
                }
                else {
                    if (!(node->children[j]->value < node->children[j + 1]->value)) swap_needed = true;
                }

                if (swap_needed) 
                {
                    Node<T>* temp = node->children[j];
                    node->children[j] = node->children[j + 1];
                    node->children[j + 1] = temp;
                }
            }
        }
    }

    int count(Node<T>* node) const 
    {
        return count_recursive(node ? node : root);
    }

    Node<T>* find(bool (*compare)(T)) 
    {
        return find_recursive(root, compare);
    }
};