/**
 * Estruturas de dados e rotinas auxiliares para algorítimos com grafos.
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <functional>
#include <iostream>
#include <ostream>
#include <set>

template <typename T>
struct node {
    T data;
    node *parent;
    node *left;
    node *right;

    node(T v) : data(v) {}
};

template <typename T>
void traverse_inorder(const node<T> *n, std::function<void(const node<T> *)> fn) {
    if (n == nullptr)
        return;

    traverse_inorder(n->left, fn);
    fn(n);
    traverse_inorder(n->right, fn);
}

template <typename T>
std::ostream &operator<<(std::ostream &s, const node<T> &root) {
    s << "digraph G {\n";

    std::function<void(const node<T> *)> fn = [&s](const node<T> *n) {
        if (n->left) {
            s << "  \"" << n << " " << n->data << "\""
              << " -> \"" << n->left << " " << n->left->data << "\";"
              << "\n";
        }

        if (n->right) {
            s << "  \"" << n << " " << n->data << "\""
              << " -> \"" << n->right << " " << n->right->data << "\";"
              << "\n";
        }

        if (n->left == nullptr && n->right == nullptr) {
            s << "  \"" << n << " " << n->data << "\";\n";
        }
    };

    traverse_inorder(&root, fn);
    s << "}\n";
    return s;
}

#endif /* GRAPH_H */