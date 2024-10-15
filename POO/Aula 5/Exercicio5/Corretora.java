import java.util.Scanner;

public class Corretora {
    public static void main(String[] args) {
        Imovel[] A = new Imovel[5];
        Scanner scan = new Scanner(System.in);

        for (int i = 0; i < 5; i++) {
            A[i] = new Imovel();
            System.out.println("Digite o endereço da " + i + "a casa: ");
            String endereco = scan.nextLine();
            System.out.println("Digite o preço da " + i + "a casa: ");
            double valor = scan.nextDouble();

            A[i].setendereco(endereco);
            A[i].setpreco(valor);

            scan.nextLine();
        }

        System.out.println("A soma de todos os imóveis é: " + somaImoveis(A));
        System.out.println(A[1]);
    }

    public static double somaImoveis(Imovel[] A) {
        double somaTotal = 0;

        for (int i = 0; i < 5; i++) {
            somaTotal += A[i].getpreco();
        }

        return somaTotal;
    }
}
