#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

namespace binary_tree {

template <typename T> struct binary_tree {
    explicit binary_tree(const T &d);

    void insert(const T &d);
    const T &data() const { return mdata; }
    const binary_tree *left() const { return pleft; }
    const binary_tree *right() const { return pright; }

  private:
    const T mdata;
    binary_tree *pleft;
    binary_tree *pright;
};

} // namespace binary_tree

#endif // BINARY_SEARCH_TREE_H
