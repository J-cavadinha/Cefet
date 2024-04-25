// Ex 2
public class ContaBancaria {
    private double saldo;
    private Data dataAbertura;

    ContaBancaria(){
        this.dataAbertura = new Data();
    }

    public double getsaldo() {
        return this.saldo;
    }

    public void setsaldo(double saldo) {
        this.saldo = saldo;
    }

    public Data getdataAbertura() {
        return this.dataAbertura;
    }

    public void setdataAbertura(int dia, int mes, int ano) {
        this.dataAbertura.setdia(dia);
        this.dataAbertura.setmes(mes);
        this.dataAbertura.setano(ano);
    }

    public String getDataAberturaFormatada() {
        return this.dataAbertura.getdia() + "/" + this.dataAbertura.getmes() + "/" + this.dataAbertura.getano();
    }

    public String getSaldoFormatado() {
        return "R$ " + this.getsaldo();
    }

    public void depositar(double valor) {
        double novoSaldo = this.getsaldo() + valor;
        this.setsaldo(novoSaldo);
    }

    public void sacar(double valor) {
        if (this.getsaldo() >= valor) {
            double novoSaldo = this.getsaldo() - valor;
            this.setsaldo(novoSaldo);
        } else {
            System.out.println("Saldo insuficiente.");
        }
    }
}
