// Lista 2 ex 3
public class SomaImpares {
    public static void main(String[] args) {
        int somatotal = 0;
        for (int i = 0; i < 10000; i++) {
            if ((i % 2) == 1) {
                somatotal += i;
            }
        }
        System.out.println(somatotal);
    }
}
