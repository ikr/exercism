#if !defined(SERIES_H)
#define SERIES_H

#include <string>
#include <vector>

namespace series {
std::vector<int> digits(const std::string &source);

std::vector<std::vector<int>> slice(const std::string &source,
                                    const int window_size);
} // namespace series

#endif // SERIES_H
