import java.lang.Math;

public class Lutador {

    private String nome;
    private int idade;
    private double peso;

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

    // Questão 4
    int j = 0;

    public void possiveisLutas(Lutador[] lutadores) {
        Lutador[] lutadores_aptos = new Lutador[10];

        for (int i = 0; i < lutadores.length; i++) {
            if (lutadores[i].getPeso() == this.getPeso()) {
                if (lutadores[i].getNome() != this.getNome()) {
                    lutadores_aptos[j] = lutadores[i];
                    j++;
                }
            }
        }
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

    int k = 0;

    public Lutador sorteioLuta(Lutador[] lutadores) {
        Lutador[] lut_categoria = new Lutador[10];

        for (int i = 0; i < lutadores.length; i++) {
            if (lutadores[i].categoriaLutador() == this.categoriaLutador()) {
                lut_categoria[k] = lutadores[i];
                k++;
            }
        }

        int max = lut_categoria.length - 1;
        int min = 0;
        int range = max - min;
        int rand = (int) (Math.random() * range) + min;
        return lut_categoria[rand];
    }
}
