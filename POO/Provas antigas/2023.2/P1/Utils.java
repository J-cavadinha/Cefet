import java.util.List;

public class Utils {
    public static boolean existe(List<E> x, Produto y) {
        // Lista possui objetos de diversos ítens inclusive Produto
        if (x.contains(y)) {
            return true;
        } else {
            return false;
        }
    }
}
