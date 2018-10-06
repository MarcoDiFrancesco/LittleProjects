package albero2;

public class Nodo {
	private int n;
	private Nodo Minore;
	private Nodo Maggiore;

	public Nodo(int oggetto) {
		n = oggetto;
		Minore = null;
		Maggiore = null;
	}

	public int getN() {
		return n;
	}

	public void setN(int n) {
		this.n = n;
	}

	public Nodo getMinore() {
		return Minore;
	}

	public void setMinore(Nodo minore) {
		Minore = minore;
	}

	public Nodo getMaggiore() {
		return Maggiore;
	}

	public void setMaggiore(Nodo maggiore) {
		Maggiore = maggiore;
	}
}
