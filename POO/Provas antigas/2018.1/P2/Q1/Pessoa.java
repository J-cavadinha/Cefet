public abstract class Pessoa implements Comparable<Pessoa> {
    private String cpf;
    private String nome;
    private int idade;

    public Pessoa(String cpf) {
        this.cpf = cpf;
    }

    public void setidade(int idade) {
        this.idade = idade;
    }

    public int getidade() {
        return this.idade;
    }

    public String getnome() {
        return this.nome;
    }

    public void setnome(String nome) {
        this.nome = nome;
    }

    @Override
    public boolean equals(Object pessoa) {
        if ((pessoa == null) || this.getClass() != pessoa.getClass()) {
            return false;
        } else {
            Pessoa pessoa1 = (Pessoa) pessoa;
            return this.idade == pessoa1.getidade() && this.cpf.equals(pessoa1.cpf);
        }
    }

    @Override
    public int compareTo(Pessoa outraPessoa) {
        return this.nome.compareTo(outraPessoa.getnome());
    }

    @Override
    public String toString() {
        return "Nome: " + this.nome + "\nCPF: " + this.cpf + "\nIdade: " + this.idade + " anos.";
    }
}