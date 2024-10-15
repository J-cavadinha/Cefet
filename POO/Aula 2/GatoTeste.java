// Ex 2
public class GatoTeste {
        public static void main(String[] args) {
                Gato gato1 = new Gato();
                gato1.vivo = true;
                gato1.cor = "laranja";
                gato1.idade = 5;
                gato1.nome = "Garfield";

                Gato gato2 = new Gato();
                gato2.vivo = true;
                gato2.cor = "preto";
                gato2.idade = 8;
                gato2.nome = "Negro";

                Gato gato3 = new Gato();
                gato3.vivo = true;
                gato3.cor = "branco";
                gato3.idade = 2;
                gato3.nome = "Floquinho";

                System.out.println("Nome: " + gato1.nome + " Idade: " + gato1.idade +
                                " Cor: " + gato1.cor + " Status: " + gato1.vivo);

                System.out.println("Nome: " + gato2.nome + " Idade: " + gato2.idade +
                                " Cor: " + gato2.cor + " Status: " + gato2.vivo);

                System.out.println("Nome: " + gato3.nome + " Idade: " + gato3.idade +
                                " Cor: " + gato3.cor + " Status: " + gato3.vivo);
        }
}