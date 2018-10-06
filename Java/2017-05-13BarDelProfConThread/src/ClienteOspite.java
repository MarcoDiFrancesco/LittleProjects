public class ClienteOspite extends Thread {
	Bar m;

	public ClienteOspite(Bar M) {
		this.m = M;
	}

	public void run() {
		try {
			m.entraO();
			System.out.print("Ospite: sto consumando...\n");
			sleep(2);
			m.esciO();
		} catch (InterruptedException e) {
		}
	}
}
