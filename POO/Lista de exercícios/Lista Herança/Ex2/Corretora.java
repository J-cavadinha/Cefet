public class Corretora {
    public static void main(String[] args) {
        Imovel[] arrayimoveis = new Imovel[5];
        double soma = 0;

        for (int i = 0; i < 5; i++) {
            arrayimoveis[i] = new Imovel();
        }

        arrayimoveis[0].setEndereco("Maracanã");
        arrayimoveis[0].setPreco(10);

        arrayimoveis[1].setEndereco("Ipanema");
        arrayimoveis[1].setPreco(200);

        arrayimoveis[2].setEndereco("Leblon");
        arrayimoveis[2].setPreco(3000);

        arrayimoveis[3].setEndereco("Tijuca");
        arrayimoveis[3].setPreco(40000);

        arrayimoveis[4].setEndereco("Cachambi");
        arrayimoveis[4].setPreco(500000);

        for (int j = 0; j < 5; j++) {
            soma += arrayimoveis[j].getPreco();
        }

        System.out.println(soma);
    }
}