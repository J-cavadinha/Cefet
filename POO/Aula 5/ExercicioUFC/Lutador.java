import java.util.List;
import java.util.ArrayList;

public abstract class Lutador {
    protected String nome;
    protected int idade;
    protected double peso;

    /*
     * Lutador(String nome, int idade, double peso) {
     * this.nome = nome;
     * this.idade = idade;
     * this.peso = peso;
     * }
     */

    public String getnome() {
        return this.nome;
    }

    public int getidade() {
        return this.idade;
    }

    public double getpeso() {
        return this.peso;
    }

    // Criar uma lista de lutadores;
    // Iterar sobre o array A de lutadores e inserir quem estiver apto na lista;
    // Exibir os lutadores da lista;
    public abstract void possiveisLutas(Lutador[] A);

    public abstract String categoriaLutador();

    public abstract Lutador sorteioLuta(Lutador[] A);
}
