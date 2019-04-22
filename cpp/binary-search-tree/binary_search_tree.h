#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <memory>

namespace binary_tree {

template <typename T> struct btree_iterator;

template <typename T> struct binary_tree {
    using tree_ptr = std::unique_ptr<binary_tree>;

    explicit binary_tree(T d)
        : mdata{std::move(d)}, pleft{nullptr}, pright{nullptr} {}

    void insert(T d) {
        tree_ptr &branch = d <= mdata ? pleft : pright;

        if (!branch)
            branch.reset(new binary_tree(std::move(d)));
        else
            branch->insert(std::move(d));
    }

    const T &data() const { return mdata; }
    const tree_ptr &left() const { return pleft; }
    const tree_ptr &right() const { return pright; }

    btree_iterator<T> begin() const {
        return btree_iterator<T>{this, min_node(this)};
    };

    btree_iterator<T> end() const { return btree_iterator<T>{this, nullptr}; }

    static const binary_tree *min_node(const binary_tree *proot) {
        auto pnode = proot;

        while (pnode->left())
            pnode = pnode->left().get();

        return pnode;
    }

  private:
    T mdata;
    tree_ptr pleft;
    tree_ptr pright;
};

template <typename T> struct btree_iterator {
    btree_iterator(const binary_tree<T> *proot_, const binary_tree<T> *pnode_)
        : proot{proot_}, pnode{pnode_} {}

    bool operator!=(const btree_iterator &other) const {
        return pnode != other.pnode || proot != other.proot;
    }

    btree_iterator &operator++() {
        if (pnode->right())
            pnode = binary_tree<T>::min_node(pnode->right().get());
        else if (pnode == proot)
            pnode = nullptr;
        else {
            const binary_tree<T> *pnext = nullptr;
            auto p = proot;

            for (;;) {
                if (p->data() >= pnode->data()) {
                    pnext = p;
                    p = p->left().get();
                } else
                    p = p->right().get();

                if (p == pnode)
                    break;
            }

            pnode = pnext;
        }

        return *this;
    }

    const T &operator*() const { return pnode->data(); }

  private:
    const binary_tree<T> *proot;
    const binary_tree<T> *pnode;
};

} // namespace binary_tree

#endif // BINARY_SEARCH_TREE_H
