#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <memory>

namespace binary_tree {

template <typename T> struct btree_iterator;

template <typename T> struct binary_tree {
    using tree_ptr = std::unique_ptr<binary_tree>;

    static const binary_tree *min_node(const binary_tree *proot) {
        auto pnode = proot;

        while (pnode->left())
            pnode = pnode->left().get();

        return pnode;
    }

    template <typename D>
    explicit binary_tree(D &&d)
        : mdata{std::forward<D>(d)}, pleft{nullptr}, pright{nullptr} {}

    template <typename D> void insert(D &&d) {
        tree_ptr &branch = d <= mdata ? pleft : pright;

        if (!branch)
            branch.reset(new binary_tree(std::forward<D>(d)));
        else
            branch->insert(d);
    }

    const T &data() const { return mdata; }
    const tree_ptr &left() const { return pleft; }
    const tree_ptr &right() const { return pright; }

    btree_iterator<T> begin() const;
    btree_iterator<T> end() const;

  private:
    T mdata;
    tree_ptr pleft;
    tree_ptr pright;
};

template <typename T> struct btree_iterator {
    btree_iterator(const binary_tree<T> *proot_, const binary_tree<T> *pnode_);

    bool operator!=(const btree_iterator &other) const;
    btree_iterator &operator++();
    const T &operator*() const;

  private:
    const binary_tree<T> *proot;
    const binary_tree<T> *pnode;
};

} // namespace binary_tree

#endif // BINARY_SEARCH_TREE_H
