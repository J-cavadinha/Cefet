public class Airplane extends Vehicle implements Flyer {
    public void takeOff() {
        System.out.println("Taking off...");
    }

    public void land() {
        System.out.println("Landing...");
    }

    public void fly() {
        System.out.println("Flying");
    }
}
