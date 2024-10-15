public class Velho extends Imovel {
    @Override
    public double getpreco() {
        return (super.getpreco() * 0.9);
    }
}
