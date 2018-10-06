public class ClienteLocale extends Thread {
	Bar m;

	public ClienteLocale(Bar M) {
		this.m = M;
	}

	public void run() {
		try {
			m.entraL();
			System.out.print("Locale: sto consumando...\n");
			sleep(2);
			m.esciL();
		} catch (InterruptedException e) {
		}
	}
}