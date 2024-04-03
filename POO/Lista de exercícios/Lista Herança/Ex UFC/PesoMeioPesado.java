public class PesoMeioPesado extends Lutador {
    PesoMeioPesado(String nome, int idade, double peso) {
        super(nome, idade, peso);
    }

    @Override
    public String impressao(String nome, int idade, double peso, int categoria) {
        return nome + "/" + idade + "/" + peso + "/" + categoria;
    }

    private int modalidade = 2;

    public int getCategoria() {
        return this.modalidade;
    }
}
