public class Exercicio3 {
    public static void main(String[] args) {
        int somaimpares = 0;

        for (int i = 1; i < 10000; i++) {
            if ((i % 2) == 1) {
                somaimpares = somaimpares + i;
            } else {
                continue;
            }
        }

        System.out.println("Resultado: " + somaimpares);
    }
}
