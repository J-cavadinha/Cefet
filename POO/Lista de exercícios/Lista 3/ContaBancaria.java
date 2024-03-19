import java.util.Locale;
import java.text.NumberFormat;

public class ContaBancaria {
    private double saldo;
    private Data dataAbertura = new Data();

    ContaBancaria(int dia, int mes, int ano) {
        dataAbertura.setDia(dia);
        dataAbertura.setMes(mes);
        dataAbertura.setAno(ano);
    }

    Data dataObject = new Data();

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public double getSaldo() {
        return this.saldo;
    }

    public void setDataAbertura(Data dataAbertura) {
        this.dataAbertura = dataAbertura;
    }

    public Data getDataAbertura() {
        return this.dataAbertura;
    }

    public void getDataAberturaFormatada() {
        int dia = dataAbertura.getDia();
        int mes = dataAbertura.getMes();
        int ano = dataAbertura.getAno();
        String dataformatada = dia + "/" + mes + "/" + ano;
        System.out.println(dataformatada);
    }

    @SuppressWarnings("deprecation")
    Locale localeBR = new Locale("pt", "BR");
    NumberFormat dinheiro = NumberFormat.getCurrencyInstance(localeBR);

    public void getSaldoFormatado() { // ok!
        System.out.println(dinheiro.format(getSaldo()));
    }

    public void depositar(double valor) { // ok!
        setSaldo((getSaldo() + valor));
    }

    public void sacar(double valor) { // ok!
        if (getSaldo() >= valor) {
            setSaldo((getSaldo() - valor));
        } else {
            System.out.println("Fundos insuficientes");
        }
    }

}
