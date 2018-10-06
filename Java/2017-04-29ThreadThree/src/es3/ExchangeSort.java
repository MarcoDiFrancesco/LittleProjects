package es3;

public class ExchangeSort extends Thread {

	private int[] b;

	public ExchangeSort(int[] b) {
		super();
		this.b = b;
	}

	public void run() {
		int i, j, temp;
		for (i = 0; i < b.length - 1; i++) {
			for (j = i + 1; j < b.length; j++) {
				if (b[i] < b[j]) {
					temp = b[i];
					b[i] = b[j];
					b[j] = temp;
				}
			}
		}
		System.out.println("Exchange Sort terminato");
	}

	public int[] getB() {
		return b;
	}
}
