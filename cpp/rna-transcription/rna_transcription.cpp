#include "rna_transcription.h"
#include <algorithm>
#include <cassert>
#include <unordered_map>

namespace transcription {
char to_rna(const char nucleotide) {
    static const std::unordered_map<char, char> fn_table{
        {'G', 'C'}, {'C', 'G'}, {'T', 'A'}, {'A', 'U'}};

    assert(fn_table.count(nucleotide));
    return fn_table.at(nucleotide);
}

std::string to_rna(std::string seq) {
    std::transform(seq.cbegin(), seq.cend(), seq.begin(),
                   static_cast<char (*)(char)>(to_rna));
    return seq;
}
} // namespace transcription
