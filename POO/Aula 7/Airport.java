public class Airport {

    private String nome;

    public String getnome() {
        return this.nome;
    }

    public void setnome(String nome) {
        this.nome = nome;
    }

    public static void main(String[] args) {

        /*
         * Airport metropolisAirport = new Airport();
         * Helicopter copter = new Helicopter();
         * SeaPlane splane = new SeaPlane();
         * 
         * metropolisAirport.givePermissionToLand(copter);
         * metropolisAirport.givePermissionToLand(splane);
         */

        Airport aP1 = new Airport();
        Helicopter copter = new Helicopter();
        aP1.setnome("Galeão");
        System.out.println("Aeroporto " + aP1.getnome() + " vai dar permissão para pouso.");
        aP1.givePermissionToLand(copter);
    }

    private void givePermissionToLand(Flyer f) {
        f.land();
    }
}
