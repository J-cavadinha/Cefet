public class InverterArray {
    public static void main(String[] args) {
        int[] A = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

        InverterArray(A);
    }

    public static void InverterArray(int[] A) {
        int[] B = new int[20];

        for (int i = 0; i < 20; i++) {
            B[i] = A[19 - i];
        }

        System.out.println("Array inicial: ");
        for (int k = 0; k < 20; k++) {
            System.out.print(A[k]);
            System.out.print(" ");
        }
        System.out.println();

        System.out.println("Array invertido: ");
        for (int l = 0; l < 20; l++) {
            System.out.print(B[l]);
            System.out.print(" ");
        }
    }
}
