public class Exercicio4 {
    public static void main(String[] args) {
        int soma = 0;

        for (int i = 0; i < 50000; i++) {
            if (i < 100 || i > 137) {
                soma += i;
            } else {
                continue;
            }
        }

        System.out.println("Resultado: " + soma);
    }
}
