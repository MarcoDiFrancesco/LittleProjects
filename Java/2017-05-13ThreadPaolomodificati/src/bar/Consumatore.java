package bar;

public class Consumatore implements Runnable {
	Buffer buffer;
	int ritardo;
	int i = 0;

	public Consumatore(Buffer buffer, int ritardo) {
		super();
		this.buffer = buffer;
		this.ritardo = ritardo;
	}

	public void run() {
		while (true) {
			try {
				String s = buffer.prelevaInfo();
				System.out.println("Cons prende" + s);
				Thread.sleep(ritardo);
			} catch (Exception e) {
				System.out.println("err ");
			}
		}
	}

}
