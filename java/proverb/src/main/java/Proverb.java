class Proverb {
    private final String[] words;

    Proverb(String[] words) {
        this.words = words;
    }

    String recite() {
        if (words.length == 0) return "";
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < words.length - 1; i++) {
            result.append(upperLine(words[i], words[i + 1]));
        }

        result.append(lastLine(words[0]));

        return result.toString();
    }

    private static String upperLine(String word1, String word2) {
        return String.format("For want of a %s the %s was lost.\n", word1, word2);
    }

    private static String lastLine(String word) {
        return String.format("And all for the want of a %s.", word);
    }
}
