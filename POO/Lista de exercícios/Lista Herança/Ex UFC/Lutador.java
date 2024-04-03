import java.lang.Math;

class Lutador {

    private String nome;
    private int idade;
    private double peso;
    private int categoria;

    Lutador(String nome, int idade, double peso) {
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
    }

    public String getNome() {
        return this.nome;
    }

    public int getIdade() {
        return this.idade;
    }

    public double getPeso() {
        return this.peso;
    }

    public int getCategoria() {
        return this.categoria;
    }

    // Questão 4
    public static Lutador[] possiveisLutas(Lutador[] lutadores, int posLutadorEscolhido) {
        Lutador escolhido = lutadores[posLutadorEscolhido];
        Lutador[] novoArrayLutadores = new Lutador[lutadores.length - 1];

        System.out.println("Lutas possíveis: ");
        int novoIndex = 0;
        for (int i = 0; i < lutadores.length; i++) {
            if (i != posLutadorEscolhido && lutadores[i].getCategoria() == escolhido.getCategoria()) {
                System.out.println(escolhido.getNome() + " x " + lutadores[i].getNome());
                novoArrayLutadores[novoIndex++] = lutadores[i];
            }
            System.out.println();
        }
        return novoArrayLutadores;
    }

    // Questão 5
    public String categoriaLutador() {
        if (this.getPeso() <= 120.2 && this.getPeso() > 93.0) {
            return "Peso pesado";
        } else if (this.getPeso() <= 93.0 && this.getPeso() > 83.9) {
            return "Peso meio pesado";
        } else if (this.getPeso() <= 83.9 && this.getPeso() > 65.0) {
            return "Peso médio";
        } else if (this.getPeso() <= 65.0) {
            return "Peso pena";
        } else {
            return "Sem categoria";
        }
    }

    public String impressao(String nome, int idade, double peso, int categoria) {
        return nome + "/" + idade + "/" + peso + "/" + "/" + categoria;
    }

    int k = 0;

    public static Lutador sorteioLuta(Lutador[] lutadores) {
        int count = 0;

        for (int i = 0; i < lutadores.length; i++) {
            if (lutadores[i] != null) {
                count++;
            }
        }

        Lutador[] arraySorteioFormatado = new Lutador[count];

        int index = 0;
        for (int k = 0; k < arraySorteioFormatado.length; k++) {
            if (lutadores[k] != null) {
                arraySorteioFormatado[index] = lutadores[k];
                index++;
            }
        }

        int max = arraySorteioFormatado.length - 1;
        int min = 0;
        int range = max - min;
        int rand = (int) (Math.random() * range) + min;
        return arraySorteioFormatado[rand];
    }
}