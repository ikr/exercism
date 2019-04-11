#include "binary_search_tree.h"
#include <string>

namespace {

template <typename T>
const binary_tree::binary_tree<T> *
min_node(const binary_tree::binary_tree<T> *proot) {
    auto pnode = proot;

    while (pnode->left())
        pnode = pnode->left().get();

    return pnode;
}

} // namespace

namespace binary_tree {

template <typename T>
binary_tree<T>::binary_tree(const T &d)
    : mdata{d}, pleft{nullptr}, pright{nullptr} {}

template <typename T> void binary_tree<T>::insert(const T &d) {
    tree_ptr &branch = d <= mdata ? pleft : pright;

    if (!branch)
        branch.reset(new binary_tree(d));
    else
        branch->insert(d);
}

template <typename T> btree_iterator<T> binary_tree<T>::begin() const {
    return btree_iterator<T>{this, min_node(this)};
}

template <typename T> btree_iterator<T> binary_tree<T>::end() const {
    return btree_iterator<T>{this, nullptr};
}

template <typename T>
btree_iterator<T>::btree_iterator(const binary_tree<T> *proot_,
                                  const binary_tree<T> *pnode_)
    : proot{proot_}, pnode{pnode_} {}

template <typename T>
bool btree_iterator<T>::operator!=(const btree_iterator &other) const {
    return pnode != other.pnode || proot != other.proot;
}

template <typename T> btree_iterator<T> &btree_iterator<T>::operator++() {
    if (pnode->right())
        pnode = min_node(pnode->right().get());
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

template <typename T> const T &btree_iterator<T>::operator*() const {
    return pnode->data();
}

template struct binary_tree<uint32_t>;
template struct btree_iterator<uint32_t>;
template struct binary_tree<std::string>;
template struct btree_iterator<std::string>;

} // namespace binary_tree
