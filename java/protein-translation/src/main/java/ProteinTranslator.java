import java.util.*;

final class ProteinTranslator {
    private static enum Protein {
        METHIONINE(Arrays.asList("AUG")),
        PHENYLALANINE(Arrays.asList("UUU", "UUC")),
        LEUCINE(Arrays.asList("UUA", "UUG")),
        SERINE(Arrays.asList("UCU", "UCC", "UCA", "UCG")),
        TYROSINE(Arrays.asList("UAU", "UAC")),
        CYSTEINE(Arrays.asList("UGU", "UGC")),
        TRYPTOPHAN(Arrays.asList("UGG")),
        STOP(Arrays.asList("UAA", "UAG", "UGA"));

        static Protein match(String codon) {
            for (Protein p : Protein.values()) {
                if (p.codons.contains(codon)) {
                    return p;
                }
            }

            return null;
        }

        private final Set<String> codons;

        Protein(List<String> codons) {
            this.codons = new HashSet(codons);
        }

        String humanName() {
            return name().substring(0, 1) + name().substring(1).toLowerCase();
        }
    }

    List<String> translate(String rnaSequence) {
        List<String> result = new ArrayList<>();

        for (int i = 0; i < rnaSequence.length(); i += 3) {
            String triple = rnaSequence.substring(i, i + 3);
            Protein p = Protein.match(triple);

            if (p == Protein.STOP) break;

            result.add(p.humanName());
        }

        return result;
    }
}
