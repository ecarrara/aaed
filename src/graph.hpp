/**
 * Estruturas de dados e rotinas auxiliares para algorítimos com grafos.
 */
#ifndef GRAPH_H
#define GRAPH_H

template <typename T>
struct node {
    T data;
    node *parent;
    node *left;
    node *right;

    node(T v) : data(v) {}
};

template <typename T>
bool operator<(const node<T> &a, const node<T> &b) {
    return a->data < b->data;
}

template <typename T>
bool operator>(const node<T> &a, const node<T> &b) {
    return a->data > b->data;
}

#endif /* GRAPH_H */