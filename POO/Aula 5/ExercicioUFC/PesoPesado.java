import java.util.List;
import java.util.ArrayList;

public class PesoPesado extends Lutador {

    public int atributo = 1;

    PesoPesado(String nome, int idade, double peso) {
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
    }

    @Override
    public void possiveisLutas(Lutador[] A) {
        List<Lutador> lutadoresAptos = new ArrayList<>();

        for (int i = 0; i < A.length; i++) {
            if (this.getClass().equals(A[i].getClass()) && !this.nome.equals(A[i].getnome())) {
                lutadoresAptos.add(A[i]);
            }
        }

        for (int j = 0; j < lutadoresAptos.size(); j++) {
            System.out.println(lutadoresAptos.get(j).nome);
        }
    }

    public Lutador sorteioLuta(Lutador[] A) {
        List<Lutador> lutadoresAptos = new ArrayList<>();

        for (int i = 0; i < A.length; i++) {
            if (this.getClass().equals(A[i].getClass()) && !this.nome.equals(A[i].getnome())) {
                lutadoresAptos.add(A[i]);
            }
        }

        int tamanhoLista = lutadoresAptos.size();
        int indexAleatorio = (int) (Math.random() * tamanhoLista);
        return lutadoresAptos.get(indexAleatorio);
    }

    public String categoriaLutador() {
        return "Peso pesado";
    }
}
