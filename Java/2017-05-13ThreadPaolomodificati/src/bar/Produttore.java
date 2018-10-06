package bar;

public class Produttore implements Runnable {
	Buffer buffer;
	int ritardo;
	int i = 0;

	public Produttore(Buffer buffer, int ritardo) {
		super();
		this.buffer = buffer;
		this.ritardo = ritardo;
	}

	public void run() {
		while (true) {
			try {
				String s = "Info" + i;
				buffer.aggiungiInfo(s);
				System.out.println("Prod produce" + s);
				i++;
				Thread.sleep(ritardo);
			} catch (Exception e) {
				System.out.println("err ");
			}
		}
	}
}
