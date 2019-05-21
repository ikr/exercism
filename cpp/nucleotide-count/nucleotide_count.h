#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

#include <map>

namespace dna {
struct counter {
    counter(const std::string &nucleotides_sequence);
    std::map<char, int> nucleotide_counts() const;
    int count(const char nucleotide) const;

  private:
    std::map<char, int> m_counts;
};
} // namespace dna

#endif // NUCLEOTIDE_COUNT_H
