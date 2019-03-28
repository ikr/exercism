#include "binary_search_tree.h"
#include <cassert>
#include <vector>

namespace {

template <typename T> using btree = binary_tree::binary_tree<T>;
template <typename T> using node_ptrs = std::vector<const btree<T> *>;

template <typename T> const btree<T> &leftmost(const btree<T> &node) {
    if (!node.left())
        return node;

    return leftmost(*(node.left()));
}

template <typename T>
void traverse_in_order(const btree<T> *pnode, node_ptrs<T> &result) {
    if (!pnode)
        return;

    traverse_in_order(pnode->left().get(), result);
    result.push_back(pnode);
    traverse_in_order(pnode->right().get(), result);
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
    return const_iterator<T>{this, nullptr};
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
    assert(pnode);

    node_ptrs<T> all_nodes;
    traverse_in_order(proot, all_nodes);

    for (auto i = all_nodes.begin(); i != all_nodes.end(); ++i) {
        if (*i == pnode) {
            ++i;
            pnode = i == all_nodes.end() ? nullptr : *i;
            return *this;
        }
    }

    pnode = nullptr;
    return *this;
}

template <typename T> T const_iterator<T>::operator*() const {
    assert(pnode);
    return pnode->data();
}

} // namespace binary_tree
