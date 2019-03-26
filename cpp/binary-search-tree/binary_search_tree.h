#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>

namespace binary_tree {

template <typename T> struct binary_tree {
    explicit binary_tree(const T &d);
    ~binary_tree();

    void insert(const T &d);
    const T &data() const { return mdata; }
    const binary_tree *left() const { return pleft; }
    const binary_tree *right() const { return pright; }

  private:
    T mdata;
    binary_tree *pleft;
    binary_tree *pright;
};

template struct binary_tree<uint32_t>;
template struct binary_tree<std::string>;

} // namespace binary_tree

#endif // BINARY_SEARCH_TREE_H
