public class testeConta {
    public static void main(String[] args) {
        Data data = new Data();
        ContaBancaria conta = new ContaBancaria();

        conta.setdataAbertura(24, 04, 2024);

        conta.depositar(100);
        System.out.println(conta.getSaldoFormatado());

        conta.sacar(150);
        System.out.println(conta.getSaldoFormatado());

        conta.depositar(900);
        System.out.println(conta.getSaldoFormatado());

        conta.sacar(1000);
        System.out.println(conta.getSaldoFormatado());

        System.out.println(conta.getDataAberturaFormatada());
        System.out.println(conta.getSaldoFormatado());
    }
}
