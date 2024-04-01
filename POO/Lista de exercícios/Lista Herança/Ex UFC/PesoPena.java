public class PesoPena extends Lutador {
    PesoPena(String nome, int idade, double peso) {
        super(nome, idade, peso);
    }

    @Override
    public String impressao(String nome, int idade, double peso) {
        return nome + "/" + idade + "/" + peso;
    }

    private int modalidade = 4;

    public int getCategoria() {
        return this.modalidade;
    }
}
