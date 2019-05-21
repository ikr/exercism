#include "nucleotide_count.h"
#include <sstream>
#include <stdexcept>

namespace {
void ensure_valid_nucleotide(const std::map<char, int> &counts,
                             const char nucleotide) {
    if (!counts.count(nucleotide)) {
        std::ostringstream message_stream{"Possible nucleotides: ATCG. Got: "};
        message_stream << nucleotide << ".";

        throw std::invalid_argument(message_stream.str());
    }
}
} // namespace

namespace dna {
counter::counter(const std::string &nucleotides_sequence)
    : m_counts{{'A', 0}, {'T', 0}, {'C', 0}, {'G', 0}} {
    for (const char n : nucleotides_sequence) {
        ensure_valid_nucleotide(m_counts, n);
        ++m_counts[n];
    }
}

std::map<char, int> counter::nucleotide_counts() const { return m_counts; }

int counter::count(const char nucleotide) const {
    ensure_valid_nucleotide(m_counts, nucleotide);
    return m_counts.at(nucleotide);
}
} // namespace dna
