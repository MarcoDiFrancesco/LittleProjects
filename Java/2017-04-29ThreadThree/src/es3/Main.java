package es3;

public class Main {
	public static void main(String[] args) {
		int nArray = 100000;
		int array[] = new int[nArray];


		for (int i = 0; i < array.length; i++) {
			array[i] = 1;
		}

		BubbleSort bs = new BubbleSort(array);
		ExchangeSort es = new ExchangeSort(array);
		Sort ss = new Sort(array);

		bs.start();
		es.start();
		ss.start();

		try {
			bs.join();
		} catch (InterruptedException e) {
		}
		try {
			es.join();
		} catch (InterruptedException e) {
		}

		try {
			ss.join();
		} catch (InterruptedException e) {
		}

	}

}
