import java.util.*;
import java.util.stream.Collectors;

class PigLatinTranslator {
    String translate(String s) {
        return Arrays
            .stream(s.split(" "))
            .map(PigLatinTranslator::translateWord)
            .collect(Collectors.joining(" "));
    }

    private static String translateWord(String s) {
        if (matchPrefix(leadingVowels, s).length() > 0) {
            return s + "ay";
        }

        String prefix = "";
        String suffix = s;

        while (true) {
            String p = matchPrefix(prefix.equals("") ? leadingConsonants : consonants,
                                   suffix);

            if (p.length() == 0) break;

            prefix += p;
            suffix = suffix.substring(p.length());
        }

        return suffix + prefix + "ay";
    }

    private static final List<String> leadingVowels;
    private static final List<String> leadingConsonants;
    private static final List<String> consonants;

    static {
        leadingVowels = Arrays
            .asList("xr", "yt", "a", "e", "i", "o", "u");

        consonants = Arrays
            .asList("b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n",
                    "p", "qu", "q", "r", "s", "t", "v", "w", "x", "z");

        leadingConsonants = new ArrayList<>();
        leadingConsonants.add("y");
        leadingConsonants.addAll(consonants);
    }

    private static String matchPrefix(List<String> oneOf, String s) {
        for (String p : oneOf) {
            if (s.indexOf(p) == 0) return p;
        }

        return "";
    }
}
