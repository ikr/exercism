#include "protein_translation.h"

#include <map>
#include <utility>

namespace {
const auto amino_acids_by_codons = [] {
    std::map<std::string, std::string> ans;

    const std::vector<std::pair<std::vector<std::string>, std::string>> src{
        {{"AUG"}, "Methionine"},      {{"UUU", "UUC"}, "Phenylalanine"},
        {{"UUA", "UUG"}, "Leucine"},  {{"UCU", "UCC", "UCA", "UCG"}, "Serine"},
        {{"UAU", "UAC"}, "Tyrosine"}, {{"UGU", "UGC"}, "Cysteine"},
        {{"UGG"}, "Tryptophan"}};

    for (const auto &p : src) {
        for (const auto &codon : p.first) {
            ans[codon] = p.second;
        }
    }

    return ans;
}();
} // namespace

namespace protein_translation {
std::vector<std::string> proteins(const std::string &rna) {
    std::vector<std::string> ans;

    for (auto i = 0U; i + 2 < rna.size(); i += 3) {
        const auto codon = rna.substr(i, 3);

        if (amino_acids_by_codons.count(codon))
            ans.push_back(amino_acids_by_codons.at(codon));
        else
            break;
    }

    return ans;
}
} // namespace protein_translation
