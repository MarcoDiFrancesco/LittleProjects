package es4;

public class Produci extends Thread {
	Semaforo pieno;
	Semaforo vuoto;
	int tanti = 5;

	public Produci(Semaforo s1, Semaforo s2) {
		pieno = s1;
		vuoto = s2;
	}

	public void run() {
		for (int i = 0; i < tanti; i++) {
			vuoto.P();
			ProdConsSen.buffer = i;
			System.out.println("Scrittore: dato scritto: " + i);
			pieno.V();
		}
	} // fine run
}

