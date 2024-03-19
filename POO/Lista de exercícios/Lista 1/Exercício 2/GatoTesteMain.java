public class GatoTesteMain {
    public static void main(String[] args) {
        Gato gato1 = new Gato();

        gato1.status = true;
        gato1.idade = 5;
        gato1.nome = "Félix";

        Gato gato2 = new Gato();

        gato2.status = true;
        gato2.idade = 8;
        gato2.nome = "Garfield";

        Gato gato3 = new Gato();
        gato3.status = true;
        gato3.idade = 10;
        gato3.nome = "Mei";

        gato1.detalhes();
        gato2.detalhes();
        gato3.detalhes();
    }
}
