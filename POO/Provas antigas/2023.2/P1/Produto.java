public class Produto {
    private String id;
    private String cor;
    private double preco;

    Produto(String id) {
        setid(id);
    }

    public void setid(String id) {
        this.id = id;
    }

    public String getid() {
        return this.id;
    }

    public String getcor() {
        return this.cor;
    }

    public double getpreco() {
        return this.preco;
    }

    public String toString() {
        return getid() + " / " + getcor() + " / " + getpreco();
    }
}
