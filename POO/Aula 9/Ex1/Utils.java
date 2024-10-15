import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class Utils {
    public static boolean existe(List<Aluno> x, Aluno y) {
        ordena(x);
        if (Collections.binarySearch(x, y) != -1) {
            return true;
        } else {
            return false;
        }
    }

    public static void ordena(List<Aluno> x) {
        Collections.sort(x);
    }
}
