import java.util.*;
import java.util.stream.*;

class Anagram {
    private String cword;

    Anagram(String word) {
        this.cword = canonize(word);
    }

    List<String> match(List<String> candidates) {
        return candidates
            .stream()
            .filter(this::isAnagram)
            .collect(Collectors.toList());
    }

    private boolean isAnagram(String candidate) {
        return cword.equals(canonize(candidate));
    }

    private static String canonize(String s) {
        return IntStream
            .range(0, s.length())
            .map(
                 i -> i == 0 ?
                 Character.toLowerCase(s.codePointAt(i)) :
                 s.codePointAt(i))
            .sorted()
            .collect(
                     StringBuilder::new,
                     StringBuilder::appendCodePoint,
                     StringBuilder::append)
            .toString();
    }
}
