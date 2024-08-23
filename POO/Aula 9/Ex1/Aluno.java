public class Aluno {
    private String id;
    private String nome;
    private double nota;

    Aluno(String id) {
        this.id = id;
    }

    @Override
    public String toString() {
        return this.id
                + " "
                + this.nome
                + " "
                + this.nota;
    }
}
