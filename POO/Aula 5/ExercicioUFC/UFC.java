import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class UFC {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Lutador[] arrayLutadores = new Lutador[10];

        for (int i = 0; i < arrayLutadores.length; i++) {
            System.out.println("Digite o nome do lutador: ");
            String nome = scan.nextLine();
            System.out.println("Digite a idade do lutador: ");
            int idade = scan.nextInt();
            scan.nextLine();
            System.out.println("Digite o peso do lutador: ");
            double peso = scan.nextDouble();
            scan.nextLine();

            if (peso <= 65.0) {
                arrayLutadores[i] = new PesoPena(nome, idade, peso);
            } else if (peso > 65 && peso <= 83.9) {
                arrayLutadores[i] = new PesoMedio(nome, idade, peso);
            } else if (peso > 83.9 && peso <= 93.0) {
                arrayLutadores[i] = new MeioPesado(nome, idade, peso);
            } else if (peso > 93.0 && peso <= 120.2) {
                arrayLutadores[i] = new PesoPesado(nome, idade, peso);
            }
        }

        System.out.println("Digite um número de 0 a 9: ");
        int escolha = scan.nextInt();

        System.out.println(arrayLutadores[escolha].getnome() + " / " + arrayLutadores[escolha].getidade()
                + " / " + arrayLutadores[escolha].getpeso());

        arrayLutadores[escolha].possiveisLutas(arrayLutadores);
        Lutador sorteado = arrayLutadores[escolha].sorteioLuta(arrayLutadores);
        if (sorteado != null) {
            System.out.println(arrayLutadores[escolha].getnome() + " x " + sorteado.getnome());
        } else {
            System.out.println("Sem lutadores aptos");
        }
    }
}
