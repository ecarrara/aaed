#ifndef ALGO_CARTESIANTREESORT_H
#define ALGO_CARTESIANTREESORT_H

#include "../graph.hpp"
#include <iostream>
#include <queue>

// references:
//    https://iq.opengenus.org/cartesian-tree-sorting/
//    https://courses.csail.mit.edu/6.851/spring12/scribe/2012scribes.pdf

template <typename T>
struct cartesian_tree {
    node<T> *root = nullptr;
    node<T> *last = nullptr;

    void add_node(T value) {
        node<T> *new_node = new node<T>(value);

        if (root == nullptr) {
            last = new_node;
            root = new_node;
            return;
        }

        node<T> *lowest_node = find_lowest_node(last, value);
        if (lowest_node == nullptr) {
            new_node->left = root;
            root->parent = new_node;
            root = new_node;
        } else {
            new_node->left = lowest_node->right;
            lowest_node->right = new_node;
            new_node->parent = lowest_node;
        }
        last = new_node;
    }

private:
    node<T> *find_lowest_node(node<T> *node, T value) {
        if (node->data < value) {
            return node;
        } else if (node->parent != nullptr) {
            return find_lowest_node(node->parent, value);
        } else {
            return nullptr;
        }
    }
};

template <typename T>
void cartesiantree_sort(std::vector<T> &in) {
    cartesian_tree<T> tree;

    for (T value : in) {
        tree.add_node(value);
    }

    auto cmp = [](node<T> *a, node<T> *b) { return a->data > b->data; };
    std::priority_queue<node<T> *, std::vector<node<T> *>, decltype(cmp)> prio_queue(cmp);
    prio_queue.push(tree.root);

    size_t i = 0;
    while (!prio_queue.empty()) {
        node<T> *aux = prio_queue.top();
        prio_queue.pop();

        in[i++] = aux->data;

        if (aux->left) {
            prio_queue.push(aux->left);
        }
        if (aux->right) {
            prio_queue.push(aux->right);
        }
    }
};

#endif /* ALGO_CARTESIANTREESORT_H */