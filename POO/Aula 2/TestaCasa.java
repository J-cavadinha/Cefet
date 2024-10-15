// Ex 4
public class TestaCasa {
    public static void main(String[] args) {
        Casa c1 = new Casa();
        Casa c2 = new Casa();

        c1.cor = "azul";
        c2.cor = "amarelo";

        c1.numero = 10;
        c2.numero = 20;

        System.out.println("A case de número " + c1.numero + " tem cor " + c1.cor);
        System.out.println("A case de número " + c2.numero + " tem cor " + c2.cor);
    }
}
