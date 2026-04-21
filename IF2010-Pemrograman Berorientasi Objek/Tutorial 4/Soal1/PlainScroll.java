public class PlainScroll extends Scroll {
    public PlainScroll(String content) {
        super(content);
    }

    @Override
    public String process() {
        String ori = getContent();
        ori = ori.trim();
        if (ori.isEmpty()) {
            return "";
        }
        String[] words = ori.split("\\s+");

        StringBuilder result = new StringBuilder();
        for (int i = 0 ; i < words.length ; i++) {
            String word = words[i];
            String filter = word.substring(0, 1).toUpperCase() + word.substring(1).toLowerCase();
            result.append(filter);

            if (i < words.length - 1) {
                result.append(" ");
            }
        }

        return result.toString();
    }

    @Override
    public String toString() {
        return "[PLAIN] " + getContent();
    }
}


