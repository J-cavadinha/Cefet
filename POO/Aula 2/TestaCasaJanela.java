public class TestaCasaJanela {
    public static void main(String[] args) {
        Janela janela1 = new Janela();
        janela1.cor = "branca";
        janela1.material = "madeira";

        Casa casa1 = new Casa();
        casa1.cor = "azul";
        casa1.numero = 100;
        casa1.janela = janela1;

        System.out.println("A casa é " + casa1.cor + " é de número " + casa1.numero
                + " e tem as janelas de " + casa1.janela.material +
                " de cor " + casa1.janela.cor);
    }
}
