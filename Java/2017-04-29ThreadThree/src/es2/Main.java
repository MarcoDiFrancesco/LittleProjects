package es2;

public class Main {
	public static void main(String[] args) {
		int[] as = new int[10];
		for (int i = 0; i < as.length; i++) {
			as[i] = 1;
		}
		System.out.println("La somma totale è: " + somma(as));
		Worker w1 = new Worker(0, 4, as);
		Worker w2 = new Worker(5, 9, as);
		w1.start();
		w2.start();

		try {
			w1.join();
		} catch (InterruptedException e) {
			// TODO: handle exception
		}
		try {
			w2.join();
		} catch (InterruptedException e) {
			// TODO: handle exception
		}
		System.out.println("La somma Totale è: " + (w1.getResult() + w2.getResult()));
	}

	private static int somma(int k[]) {
		int n1 = 1, n2 = 1;
		System.out.println("Prima somma");
		for (int i = 0; i < 4; i++) {
			n1 = n1 + k[i];

			System.out.println(n1 - 1 + "+" + k[i] + "=" + n1);
		}
		System.out.println("Seconda somma");
		for (int i = 5; i < 9; i++) {
			n2 = n2 + k[i];

			System.out.println(n2 - 1 + "+" + k[i] + "=" + n2);
		}
		return n1 + n2;
	}
}
