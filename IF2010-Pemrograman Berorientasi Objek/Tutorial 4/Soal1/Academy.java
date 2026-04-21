import java.util.ArrayList;

public class Academy {
    private ArrayList<Scroll> scrollStorage;

    public Academy() {
        scrollStorage = new ArrayList<>();
    }

    public Scroll getScroll(int index) {
        return scrollStorage.get(index - 1);
    }

    public void addScroll(Scroll s) {
        scrollStorage.add(s);
    }

    public int search(String keyword) {
        int foundCount = 0;
        String lowerKeyboard = keyword.toLowerCase();
        for (Scroll s : scrollStorage) {
            if (s.getContent().toLowerCase().contains(lowerKeyboard)) {
                foundCount++;
            }
        }
        return foundCount;
    }

    public int count() {
        return scrollStorage.size();
    }
}
