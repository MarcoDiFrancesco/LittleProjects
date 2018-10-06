package es4;

public class Consuma extends Thread {
	Semaforo pieno;
	Semaforo vuoto;
	int dato;

	public Consuma(Semaforo s1, Semaforo s2) {
		pieno = s1;
		vuoto = s2;
	}

	public void run() {
		while (true) {
			pieno.P();
			dato = ProdConsSen.buffer;
			System.out.println("Lettore: dato letto: " + dato);
			vuoto.V();
		}
	}
}
