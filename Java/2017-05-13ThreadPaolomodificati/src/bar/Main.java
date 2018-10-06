package bar;

public class Main {

	public static void main(String[] args) {
		Buffer bar = new Buffer(10);
		Thread produttore = new Thread(new Produttore(bar, 1000));
		Thread consumatore = new Thread(new Consumatore(bar, 1000));
		produttore.start();
		consumatore.start();
		produttore.run();
	}
}
