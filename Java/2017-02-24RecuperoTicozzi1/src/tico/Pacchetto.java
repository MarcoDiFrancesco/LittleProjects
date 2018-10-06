package tico;

public class Pacchetto {
	private int numeroPatatine;

	public Pacchetto(int numeroPatatine) {
		this.numeroPatatine = numeroPatatine;
	}

	public Pacchetto() {
		numeroPatatine = 100;
	}

	public boolean isEmpty() {
		boolean vuoto = false;
		if (numeroPatatine == 0) {
			vuoto = true;
		}
		return vuoto;
	}

	public void mangiaPatatine() {
		if (isEmpty()) {
			numeroPatatine--;
		}
	}

	public void mangiaNPatatine(double n) {
		for (int w = 0; w < n; w++) {
			mangiaPatatine();
		}
	}

	public int getNumero() {
		return numeroPatatine;
	}
}
