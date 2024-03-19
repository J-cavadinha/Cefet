public class Casa {
    public String cor;
    public int numero;
    public Janela janela;

    public void detalhes() {
        System.out.println("A casa de número " + this.numero + " tem cor " + this.cor);
    }
}
