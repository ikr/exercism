#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <string>
#include <vector>

namespace binary_tree {

template <typename T> struct btree_iterator;

template <typename T> struct binary_tree {
    using tree_ptr = std::unique_ptr<binary_tree>;

    explicit binary_tree(const T &d);

    void insert(const T &d);
    const T &data() const { return mdata; }
    const tree_ptr &left() const { return pleft; }
    const tree_ptr &right() const { return pright; }

    btree_iterator<T> begin() const;
    btree_iterator<T> end() const;

  private:
    T mdata;
    tree_ptr pleft;
    tree_ptr pright;

    void provide_iter_storage() const;
    using node_ptrs = std::vector<const binary_tree<T> *>;
    mutable std::unique_ptr<node_ptrs> iter_storage;
};

template <typename T> struct btree_iterator {
    using node_ptrs_iter =
        typename std::vector<const binary_tree<T> *>::const_iterator;

    explicit btree_iterator(node_ptrs_iter impl_);

    bool operator!=(const btree_iterator &other) const;
    btree_iterator &operator++();
    T operator*() const;

  private:
    node_ptrs_iter impl;
};

} // namespace binary_tree

#endif // BINARY_SEARCH_TREE_H
