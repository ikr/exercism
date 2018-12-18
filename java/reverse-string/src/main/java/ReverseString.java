class ReverseString {
    String reverse(String inputString) {
        StringBuilder result = new StringBuilder();

        for (char c : inputString.toCharArray()) {
            result.insert(0, c);
        }

        return result.toString();
    }
}
