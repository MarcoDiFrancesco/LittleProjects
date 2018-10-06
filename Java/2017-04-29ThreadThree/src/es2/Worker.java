package es2;

public class Worker extends Thread {
	private int from, to;
	private int array[];
	private int result;

	public Worker(int from, int to, int[] array) {
		super();
		this.from = from;
		this.to = to;
		this.array = array;
	}

	@Override
	public void run() {
		int k = 1;
		for (int i = from; i < to; i++) {
			k = k + array[i];

		}
		result = k;

	}

	public int getResult() {
		return result;
	}

}
