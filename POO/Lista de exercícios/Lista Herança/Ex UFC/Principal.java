import java.util.Scanner;

public class Principal {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        Lutador[] lutadores = new Lutador[10];

        for (int i = 0; i < lutadores.length; i++) {
            System.out.println("Digite o nome do lutador: ");
            String nome = input.nextLine();

            System.out.println("Digite a idade:");
            int idade = input.nextInt();
            input.nextLine();

            System.out.println("Digite o peso: ");
            double peso = input.nextDouble();
            input.nextLine();

            lutadores[i] = new Lutador(nome, idade, peso);
        }
        input.close();
    }
}
