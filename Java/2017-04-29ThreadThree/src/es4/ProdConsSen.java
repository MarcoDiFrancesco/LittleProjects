package es4;

public class ProdConsSen {

	protected static int buffer;

	public static void main(String[] args) {

		Semaforo pieno = new Semaforo(0);
		Semaforo vuoto = new Semaforo(1);

		Produci pr = new Produci(pieno, vuoto);
		Consuma co = new Consuma(pieno, vuoto);

		pr.start();
		co.start();
	}
}
