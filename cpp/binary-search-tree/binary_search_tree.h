#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <string>

namespace binary_tree {

template <typename T> struct binary_tree {
    using tree_ptr = std::unique_ptr<binary_tree>;

    explicit binary_tree(const T &d);

    void insert(const T &d);
    const T &data() const { return mdata; }
    const tree_ptr &left() const { return pleft; }
    const tree_ptr &right() const { return pright; }

  private:
    T mdata;
    tree_ptr pleft;
    tree_ptr pright;
};

template struct binary_tree<uint32_t>;
template struct binary_tree<std::string>;

} // namespace binary_tree

#endif // BINARY_SEARCH_TREE_H
