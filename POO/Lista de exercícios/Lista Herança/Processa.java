/*  Código da questão, não compila devido a tentativa de chamar um método não estático de um contexto
    estático

    public class Processa{
    public static void main(String[] args) {
        System.out.println(calcula(2,3));
    }

    public double calcula(double a, double b){
        return (a+b) * (a*0.1) + (b*0.9);
    }
    }

*/

/* Solução 1: tornando o método estático

    public static double calcula(double a, double b){
    return (a+b) * (a*0.1) + (b*0.9);
    }

*/

// Solução 2: instanciando o método (Resposta questão 6 - Sim, compila.)
/*public class Processa {
    public static void main(String[] args) {
        Processa instancia = new Processa();
        System.out.println(instancia.calcula(2, 3));
    }

    public double calcula(double a, double b) {
        return (a + b) * (a * 0.1) + (b * 0.9);
    }
} */

// Resposta questão 5 - Sim, compila.
public class Processa {
    public static void main(String[] args) {
        System.out.println(new Processa().calcula(2, 3));
    }

    public double calcula(double a, double b) {
        return (a + b) * (a * 0.1) + (b * 0.9);
    }
}
