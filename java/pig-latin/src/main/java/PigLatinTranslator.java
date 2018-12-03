class PigLatinTranslator {
    String translate(String s) {
        String p = fullConsonantPrefix(s);
        return s.substring(p.length()) + p + "ay";
    }

    private static String fullConsonantPrefix(final String s) {
        String result = "";
        String suffix = s;

        while (true) {
            String prefix = consonantPrefix(suffix);
            if (prefix.equals("")) break;

            result += prefix;
            suffix = suffix.substring(prefix.length());
        }

        return result.equals("xr") || result.startsWith("yt") ? "" : result;
    }

    private static String consonantPrefix(final String s) {
        for (Consonant c : Consonant.values()) {
            if (s.indexOf(c.value()) == 0) {
                return c.value();
            }
        }

        return "";
    }
}

enum Consonant {
    B("b"), C("c"), D("d"), F("f"), G("g"), H("h"), K("k"),
    L("l"), M("m"), N("n"), P("p"), QU("qu"), Q("q"), R("r"), S("s"),
    T("t"), V("v"), W("w"), X("x"), Y("y"), Z("z");

    private final String value;

    Consonant(String value) {
        this.value = value;
    }

    public String value() {
        return this.value;
    }
}
