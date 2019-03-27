#include "binary_search_tree.h"

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

template <typename T>
const_iterator<T>::const_iterator(const binary_tree<T> *proot_,
                                  const binary_tree<T> *pnode_)
    : proot{proot_}, pnode{pnode_} {}

template <typename T>
bool const_iterator<T>::operator!=(const const_iterator &other) const {
    return proot != other.proot || pnode != other.pnode;
}

template <typename T> const_iterator<T> &const_iterator<T>::operator++() {
    return *this;
}

template <typename T> T const_iterator<T>::operator*() const {
    return pnode->data();
}

} // namespace binary_tree
