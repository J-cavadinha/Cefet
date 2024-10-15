import java.util.Scanner;

public class Principal {
    Scanner scan = new Scanner(System.in);

    String id = scan.nextLine();
    Produto produto1 = new Produto(id);

    if(Utils.existe(Utils.getLista(),produto1))
    {
        Produto varAux = Utils.getLista(produto1);
        System.out.println(varAux.getid + varAux.getcor + varAux.getpreco);
    }

    public Produto[] transformaListEmArray(List k){
        ArrayList<Produto> listaAux = new ArrayList();
        for(int i=0; i<k.size(); i++){
            if(k.get(i) instanceof Produto){
                listaAux.add(k.get(i));
            }
        }

        int tamLista = listaAux.size();
        Produto[] arrayProduto = new Produto[tamLista];

        for(int j=0; j<tamLista; j++){
            arrayProduto[j] = listaAux.get(j);
        }

        return arrayProduto;
    }
}
