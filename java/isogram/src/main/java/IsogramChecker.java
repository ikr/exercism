class IsogramChecker {
    boolean isIsogram(String phrase) {
        StringBuilder letters = phrase
            .chars()
            .filter(Character::isAlphabetic)
            .collect(
                     StringBuilder::new,
                     StringBuilder::appendCodePoint,
                     StringBuilder::append
                     );

        return (
                letters.chars().map(Character::toLowerCase).distinct().count() ==
                letters.length()
                );
    }
}
