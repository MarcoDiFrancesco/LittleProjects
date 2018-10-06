package ex8;

public class Main {

	public static void main(String[] args) {
		int tanti = 5;
		Buffer buffer = new Buffer();
		Produci prod1 = new Produci(buffer,1, tanti);
		Consuma cons1 = new Consuma(buffer,1, tanti);
		prod1.start();
		cons1.start();

	}

}
