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

} // namespace binary_tree
