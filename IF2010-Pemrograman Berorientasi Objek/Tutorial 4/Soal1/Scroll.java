public abstract class Scroll {
    private String content;

    public Scroll(String content) {
        this.content = content;
    }

    public String getContent() {
        return content;
    }

    public abstract String process();
}
