final class Hamming {
    private final String l;
    private final String r;

    Hamming(String leftStrand, String rightStrand) {
        if (leftStrand.length() != rightStrand.length()) {
            throw new IllegalArgumentException("leftStrand and rightStrand must be of equal length.");
        }

        l = leftStrand;
        r = rightStrand;
    }

    int getHammingDistance() {
        int result = 0;

        for (int i = 0; i < l.length(); i++) {
            if (l.charAt(i) != r.charAt(i)) result++;
        }

        return result;
    }
}
