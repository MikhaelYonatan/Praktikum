public class PalindromeScroll extends Scroll {
    public PalindromeScroll(String content) {
        super(content);
    }

    public boolean isPalindrome() {
        String original = getContent();
        String cleaned = original.replaceAll("\\s+", "").toLowerCase();
        String reversed = new StringBuilder(cleaned).reverse().toString();
        return cleaned.equals(reversed);
    }

    @Override
    public String process() {
        return new StringBuilder(getContent()).reverse().toString();
    }

    @Override
    public String toString() {
        return "[PALINDROME] " + getContent();
    }
}
