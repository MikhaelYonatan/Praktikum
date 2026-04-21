public class CipherScroll extends Scroll{
    private int shift;

    public CipherScroll(String content, int shift) {
        super(content);
        this.shift = shift;
    }

    private String shifting(String text, int shift) {
        StringBuilder result = new StringBuilder();

        for (char c : text.toCharArray()) {
            if (c >= 'A' && c <= 'Z') {
                char shifted = (char) (((c - 'A' + shift % 26 + 26) % 26) + 'A');
                result.append(shifted);
            } 
            else if (c >= 'a' && c <= 'z') {
                char shifted = (char) (((c - 'a' + shift % 26 + 26) % 26) + 'a');
                result.append(shifted);
            } 
            else {
                result.append(c);
            }
        }
        return result.toString();
    }

    @Override
    public String process() {
        return shifting(getContent(), shift);
    }

    public String decode() {
        return shifting(getContent(), -shift);
    }

    @Override
    public String toString() {
        return "[CIPHER] " + getContent();
    }
}
