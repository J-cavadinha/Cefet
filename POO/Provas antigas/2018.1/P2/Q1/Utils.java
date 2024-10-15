import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Utils {
    public boolean existe(List<Pessoa> x, Pessoa y) {
        if (x.contains(y)) {
            return true;
        } else {
            return false;
        }
    }

    public static void ordena(List<Pessoa> x) {
        Collections.sort(x);
    }

    public Map<String, Pessoa> retornaDados(Set<String> conjuntoPessoas) throws FormatoIncorretoException {
        Map<String, Pessoa> pessoasMap = new HashMap<>();

        for (String formatString : conjuntoPessoas) {
            String[] arraySplitted = formatString.split("#");

            String cpf = arraySplitted[0];
            String nome = arraySplitted[1];
            int idade = Integer.parseInt(arraySplitted[2]);
            String tipo = arraySplitted[3];

            if (tipo.length() > 2) {
                throw new FormatoIncorretoException("O formato da String " + formatString + " está incorreto.");
            }

            if (tipo.equals("PJ")) {
                PessoaJuridica pessoa = new PessoaJuridica(cpf);
                pessoa.setidade(idade);
                pessoa.setnome(nome);
                pessoasMap.put(cpf, pessoa);
            } else {
                PessoaFisica pessoa = new PessoaFisica(cpf);
                pessoa.setidade(idade);
                pessoa.setnome(nome);
                pessoasMap.put(cpf, pessoa);
            }
        }
        return pessoasMap;
    }
}
