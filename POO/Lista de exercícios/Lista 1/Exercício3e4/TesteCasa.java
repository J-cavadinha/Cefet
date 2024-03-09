public class TesteCasa {
    public static void main(String[] args) {

        Casa casa1 = new Casa();
        casa1.cor = "Azul";
        casa1.numero = 1;

        Casa casa2 = new Casa();
        casa2.cor = "Branca";
        casa2.numero = 5;

        casa1.detalhes();
        casa2.detalhes();
    }
}
