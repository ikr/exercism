#include "binary_search_tree.h"

namespace binary_tree {

template <typename T>
binary_tree<T>::binary_tree(const T &d)
    : mdata{d}, pleft{nullptr}, pright{nullptr} {}

template <typename T> void binary_tree<T>::insert(const T &d) {
    tree_ptr &branch = d <= mdata ? pleft : pright;

    if (!branch) {
        branch.reset(new binary_tree(d));
    } else {
        branch->insert(d);
    }
}

template <typename T> btree_iterator<T> binary_tree<T>::begin() const {
    typename btree_iterator<T>::node_ptrs path{this};
    auto pnode = this;

    while (pnode->left()) {
        pnode = pnode->left().get();
        path.push_back(pnode);
    }

    return btree_iterator<T>{path};
}

template <typename T> btree_iterator<T> binary_tree<T>::end() const {
    return btree_iterator<T>{{}};
}

template <typename T>
btree_iterator<T>::btree_iterator(const node_ptrs &path_from_root_)
    : path_from_root{path_from_root_} {}

template <typename T>
bool btree_iterator<T>::operator!=(const btree_iterator &other) const {
    if (path_from_root.size() != other.path_from_root.size())
        return true;

    if (!path_from_root.size())
        return false;

    return path_from_root.back() != other.path_from_root.back();
}

template <typename T> btree_iterator<T> &btree_iterator<T>::operator++() {
    // TODO
    return *this;
}

template <typename T> T btree_iterator<T>::operator*() const {
    return path_from_root.back()->data();
}

template struct binary_tree<uint32_t>;
template struct btree_iterator<uint32_t>;
template struct binary_tree<std::string>;
template struct btree_iterator<std::string>;

} // namespace binary_tree
