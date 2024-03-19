public class Teste {
    public static void main(String[] args) {
        ContaBancaria teste2 = new ContaBancaria(19, 7, 2004);

        teste2.getDataAberturaFormatada();

        teste2.depositar(10000);
        teste2.getSaldoFormatado();
        teste2.sacar(10001);
        teste2.getSaldoFormatado();
        teste2.sacar(1);
        teste2.getSaldoFormatado();
    }
}
