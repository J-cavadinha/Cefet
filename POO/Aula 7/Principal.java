public class Principal {

    public static void main(String[] args) {
        retornaAleatorio();
    }

    public static Airplane[] retornaAleatorio() {
        int numeroAleatorio = (int) (Math.random() * 101);
        Airplane[] arrayAp = new Airplane[numeroAleatorio];

        for (int i = 0; i < numeroAleatorio; i++) {
            int num = ale();
            if ((num % 2) == 0) {
                arrayAp[i] = new SeaPlane();
            } else {
                arrayAp[i] = new Helicopter();
            }
        }
        decolagem(arrayAp);
        return arrayAp;
    }

    public static int ale() {
        int numeroAleatorio2 = (int) (Math.random() * 2) + 1;
        return numeroAleatorio2;
    }

    public static void decolagem(Airplane[] arrayAp) {
        for (int i = 0; i < arrayAp.length; i++) {
            if (arrayAp[i] instanceof Helicopter) {
                ((Helicopter) arrayAp[i]).ligarHelice();
                System.out.println("Helicóptero decolando...");
            } else {
                ((SeaPlane) arrayAp[i]).ligarTurbinas();
                System.out.println("Seaplane decolando...");
            }
        }
    }

}
