// Exercício 1 e 2 - Lista 1
public class Gato {
    public boolean status;
    public String cor;
    public int idade;
    public String nome;

    public void miar() {
        System.out.println("Gato miando!");
    }

    public void detalhes() {
        System.out.println(
                "O gato está vivo? " + this.status + ", tem: " + this.idade + " anos" + " e se chama: " + this.nome);
    }
}
