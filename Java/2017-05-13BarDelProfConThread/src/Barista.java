public class Barista extends Thread {
	Bar m;

	public Barista(Bar M) {
		this.m = M;
	}

	public void run() {
		try {
			while (1) {
				m.inizio_chiusura();
				System.out.print("Barista: sto pulendo...\n");
				sleep(8);
				m.fine_chiusura();
				sleep(10);
			}
		} catch (InterruptedException e) {
		}
	}
}
