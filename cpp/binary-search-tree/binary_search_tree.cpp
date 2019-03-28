#include "binary_search_tree.h"
#include <vector>

namespace {

template <typename T> using btree = binary_tree::binary_tree<T>;

template <typename T> const btree<T> &leftmost(const btree<T> &node) {
    if (!node.left())
        return node;

    return leftmost(*(node.left()));
}

template <typename T> const btree<T> &rightmost(const btree<T> &node) {
    if (!node.right())
        return node;

    return leftmost(*(node.right()));
}

template <typename T>
std::vector<const btree<T> *> path_between(const btree<T> &root,
                                           const btree<T> &node) {
    return {};
}

} // namespace

namespace binary_tree {

template <typename T>
binary_tree<T>::binary_tree(const T &d)
    : mdata(d), pleft{nullptr}, pright{nullptr} {}

template <typename T> void binary_tree<T>::insert(const T &d) {
    tree_ptr &branch = d <= mdata ? pleft : pright;

    if (!branch) {
        branch = tree_ptr{new binary_tree(d)};
    } else {
        branch->insert(d);
    }
}

template <typename T> const_iterator<T> binary_tree<T>::begin() const {
    return const_iterator<T>{this, &(leftmost(*this))};
}

template <typename T> const_iterator<T> binary_tree<T>::end() const {
    return const_iterator<T>{this, rightmost(*this).right().get()};
}

template <typename T>
const_iterator<T>::const_iterator(const binary_tree<T> *proot_,
                                  const binary_tree<T> *pnode_)
    : proot{proot_}, pnode{pnode_} {}

template <typename T>
bool const_iterator<T>::operator!=(const const_iterator &other) const {
    return proot != other.proot || pnode != other.pnode;
}

template <typename T> const_iterator<T> &const_iterator<T>::operator++() {
    std::abort();
    return *this;
}

template <typename T> T const_iterator<T>::operator*() const {
    return pnode->data();
}

} // namespace binary_tree
