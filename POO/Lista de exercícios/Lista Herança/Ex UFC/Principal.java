import java.util.Scanner;

public class Principal {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        Lutador[] lutadores = new Lutador[7];

        for (int i = 0; i < lutadores.length; i++) {
            System.out.print("Digite o nome do lutador: ");
            String nome = input.nextLine();

            System.out.print("Digite a idade:");
            int idade = input.nextInt();
            input.nextLine();

            System.out.print("Digite o peso: ");
            double peso = input.nextDouble();
            input.nextLine();

            if (peso <= 65.0) {
                lutadores[i] = new PesoPena(nome, idade, peso);
            } else if (peso > 65.0 && peso <= 83.9) {
                lutadores[i] = new PesoMedio(nome, idade, peso);
            } else if (peso > 83.9 && peso <= 93.0) {
                lutadores[i] = new PesoMeioPesado(nome, idade, peso);
            } else if (peso > 93.0 && peso <= 120.2) {
                lutadores[i] = new PesoPesado(nome, idade, peso);
            } else {
                System.out.println("Não são aceitos lutadores com mais de 120,2 kg");
                i--;
            }
        }

        System.out.println("\nDigite um número: ");
        int numero = input.nextInt();
        System.out.println(
                lutadores[numero].impressao(lutadores[numero].getNome(),
                        lutadores[numero].getIdade(), lutadores[numero].getPeso(),
                        lutadores[numero].getCategoria()));

        Lutador[] novoArrayLutadores = Lutador.possiveisLutas(lutadores, numero);
        Lutador sorteado = Lutador.sorteioLuta(novoArrayLutadores);

        System.out.println("A luta será: " + lutadores[numero].getNome() + " x " + sorteado.getNome());

        // Código para debug apenas
        // for (int j = 0; j < lutadores.length; j++) {
        // System.out.println(
        // lutadores[j].impressao(lutadores[j].getNome(), lutadores[j].getIdade(),
        // lutadores[j].getPeso(), lutadores[j].getCategoria()));
        // }

        input.close();
    }
}