#include "binary_search_tree.h"
#include <cassert>
#include <vector>

namespace {

template <typename T> using btree = binary_tree::binary_tree<T>;
template <typename T> using btree_path = std::vector<const btree<T> *>;

template <typename T> const btree<T> &leftmost(const btree<T> &node) {
    if (!node.left())
        return node;

    return leftmost(*(node.left()));
}

template <typename T>
void path_between_recur(btree_path<T> &path_so_far, const btree<T> &node) {
    assert(path_so_far.size());
    const btree<T> *pprev = path_so_far.back();

    if (pprev == &node)
        return;

    const btree<T> *pbranch = node.data() <= pprev->data()
                                  ? pprev->left().get()
                                  : pprev->right().get();

    assert(pbranch);
    path_so_far.push_back(pbranch);
    path_between_recur(path_so_far, node);
}

template <typename T>
btree_path<T> path_between(const btree<T> &root, const btree<T> &node) {
    btree_path<T> result{&root};
    path_between_recur(result, node);
    return result;
}

} // namespace

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

template <typename T> const_iterator<T> binary_tree<T>::begin() const {
    return const_iterator<T>{this, &(leftmost(*this))};
}

template <typename T> const_iterator<T> binary_tree<T>::end() const {
    return const_iterator<T>{this, nullptr};
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
    assert(pnode);
    auto path = path_between(*proot, *pnode);

    for (auto i = path.rbegin(); i != path.rend(); ++i) {
        if ((*i)->right()) {
            pnode = (*i)->right().get();
            return *this;
        }
    }

    pnode = proot->end().pnode;
    return *this;
}

template <typename T> T const_iterator<T>::operator*() const {
    assert(pnode);
    return pnode->data();
}

} // namespace binary_tree
