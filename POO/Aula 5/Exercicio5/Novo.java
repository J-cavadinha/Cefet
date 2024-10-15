public class Novo extends Imovel {
    @Override
    public double getpreco() {
        return super.getpreco() + (super.getpreco() * 0.1);
    }
}
