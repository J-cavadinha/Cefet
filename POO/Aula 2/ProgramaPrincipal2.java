public class ProgramaPrincipal2 {

	public static void main(String[] args) {
	Cachorro c = new Cachorro();
	Cachorro d = c;
	c.nome = "Pluto";
	d.nome = "Rex";
	System.out.println(c.nome);

	}

}
