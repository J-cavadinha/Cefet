public class Ex1 {
    public static void main(String[] args) {
        int[] array1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

        int[] array_suporte = new int[20];
        int aux = 0;

        for (int i = 19; i >= 0; i--) {
            array_suporte[aux] = array1[i];
            aux++;
        }

        for (int k = 0; k < array_suporte.length; k++) {
            System.out.print(array_suporte[k] + "\t");
        }
    }
}
