public class Q2 { // Q2 = "Substitui"
    public static void processa(String x) {
        char[] c = x.toUpperCase().toCharArray();
        String str = "";

        for (int i = 0; i < c.length; i++) {
            if (c[i] == 'A') {
                str += 4;
            } else if (c[i] == 'E') {
                str += 3;
            } else if (c[i] == 'I') {
                str += 1;
            } else if (c[i] == 'O') {
                str += 0;
            } else {
                str += c[i];
            }
        }
        System.out.println(str);
    }

    public static void main(String[] args) {
        processa("Paralelismo");
    }
}
