public class TesteCasaJanela {
    public static void main(String[] args) {
        Janela janela1 = new Janela();
        janela1.cor = "Amarela";
        janela1.material = "Madeira";

        Casa casa1 = new Casa();
        casa1.cor = "Amarela";
        casa1.numero = 20;
        casa1.janela = janela1;

    }
}
