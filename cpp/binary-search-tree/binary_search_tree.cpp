#include "binary_search_tree.h"
#include <string>

namespace binary_tree {

template <typename T> btree_iterator<T> binary_tree<T>::begin() const {
    return btree_iterator<T>{this, min_node(this)};
}

template <typename T> btree_iterator<T> binary_tree<T>::end() const {
    return btree_iterator<T>{this, nullptr};
}

template struct binary_tree<uint32_t>;
template struct btree_iterator<uint32_t>;
template struct binary_tree<std::string>;
template struct btree_iterator<std::string>;

} // namespace binary_tree
