class Proverb {
    private String[] words;

    Proverb(String[] words) {
        this.words = words;
    }

    String recite() {
        return words.length > 0 ? finalLine(words[0]) : "";
    }

    private static String finalLine(String word) {
        return String.format("And all for the want of a %s.", word);
    }
}
