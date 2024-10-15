public class SomaRestrita {
    public static void main(String[] args) {
        int somatotal = 0;

        for (int i = 0; i < 50000; i++) {
            if (i < 100 || i > 137) {
                somatotal += i;
            }
        }

        System.out.println(somatotal);
    }
}
