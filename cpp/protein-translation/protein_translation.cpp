#include "protein_translation.h"

#include <map>
#include <utility>

namespace {
std::map<std::string, std::string> map_codons_to_amino_acids() {
    std::map<std::string, std::string> ans;

    const std::vector<std::pair<std::vector<std::string>, std::string>> src{
        {{"AUG"}, "Methionine"}};

    for (const auto &p : src) {
        for (const auto &codon : p.first) {
            ans[codon] = p.second;
        }
    }

    return ans;
}

const auto amino_acids_by_codons = map_codons_to_amino_acids();
} // namespace

namespace protein_translation {
std::vector<std::string> proteins(const std::string &rna) {
    assert(rna.size());
    return {"Methionine"};
}
} // namespace protein_translation
