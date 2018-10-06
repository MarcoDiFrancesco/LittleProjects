package es3;

public class BubbleSort extends Thread {
	private int[] b;

	public BubbleSort(int[] b) {
		super();
		this.b = b;
	}

	public void run() {
		for (int i = 0; i < b.length; i++) {
			boolean flag = false;
			for (int j = 0; j < b.length - 1; j++) {
				if (b[j] > b[j + 1]) {
					int k = b[j];
					b[j] = b[j + 1];
					b[j + 1] = k;
					flag = true;
				}
			}
			if (!flag)
				break;
		}

		System.out.println("Bubble Sort terminato");
	}

	public int[] getB() {
		return b;
	}
}
