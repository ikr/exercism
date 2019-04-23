#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <type_traits>

namespace binary_tree {

template <typename T> struct btree_iterator;
template <typename T> struct binary_tree;

template <typename T>
const binary_tree<T> *min_node(const binary_tree<T> *proot) {
    auto pnode = proot;

    while (pnode->left())
        pnode = pnode->left().get();

    return pnode;
}

template <typename T> struct binary_tree final {
    using tree_ptr = std::unique_ptr<binary_tree>;

    template <typename D,
              typename = typename std::enable_if<!std::is_same<
                  binary_tree<T>, typename std::decay<D>::type>::value>::type>
    explicit binary_tree(D &&d)
        : mdata{std::forward<D>(d)}, pleft{nullptr}, pright{nullptr} {}

    template <typename D> void insert(D &&d) {
        tree_ptr &branch = d <= mdata ? pleft : pright;

        if (!branch)
            branch.reset(new binary_tree(std::forward<D>(d)));
        else
            branch->insert(std::forward<D>(d));
    }

    const T &data() const { return mdata; }
    const tree_ptr &left() const { return pleft; }
    const tree_ptr &right() const { return pright; }

    btree_iterator<T> begin() const {
        return btree_iterator<T>{this, min_node<T>(this)};
    };

    btree_iterator<T> end() const { return btree_iterator<T>{this, nullptr}; }

  private:
    T mdata;
    tree_ptr pleft;
    tree_ptr pright;
};

template <typename T> struct btree_iterator final {
    btree_iterator(const binary_tree<T> *proot_, const binary_tree<T> *pnode_)
        : proot{proot_}, pnode{pnode_} {}

    bool operator!=(const btree_iterator &other) const {
        return pnode != other.pnode || proot != other.proot;
    }

    btree_iterator &operator++() {
        if (pnode->right())
            pnode = min_node<T>(pnode->right().get());
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
