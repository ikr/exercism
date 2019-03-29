#include "binary_search_tree.h"

namespace {

template <typename T> using btree = binary_tree::binary_tree<T>;

template <typename T>
void traverse_in_order(const btree<T> *pnode,
                       std::vector<const btree<T> *> &result) {
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
    : mdata(d), pleft{nullptr}, pright{nullptr}, iter_storage{nullptr} {}

template <typename T> void binary_tree<T>::insert(const T &d) {
    iter_storage.reset(nullptr);
    tree_ptr &branch = d <= mdata ? pleft : pright;

    if (!branch) {
        branch = tree_ptr{new binary_tree(d)};
    } else {
        branch->insert(d);
    }
}

template <typename T> void binary_tree<T>::provide_iter_storage() const {
    if (!iter_storage) {
        std::unique_ptr<node_ptrs> new_iter_storage(new node_ptrs());
        traverse_in_order(this, *new_iter_storage);
        iter_storage.swap(new_iter_storage);
    }
}

template <typename T> btree_iterator<T> binary_tree<T>::begin() const {
    provide_iter_storage();
    return btree_iterator<T>{iter_storage->begin()};
}

template <typename T> btree_iterator<T> binary_tree<T>::end() const {
    provide_iter_storage();
    return btree_iterator<T>{iter_storage->end()};
}

template <typename T>
btree_iterator<T>::btree_iterator(node_ptrs_iter impl_) : impl{impl_} {}

template <typename T>
bool btree_iterator<T>::operator!=(const btree_iterator &other) const {
    return impl != other.impl;
}

template <typename T> btree_iterator<T> &btree_iterator<T>::operator++() {
    ++impl;
    return *this;
}

template <typename T> T btree_iterator<T>::operator*() const {
    return (*impl)->data();
}

} // namespace binary_tree
