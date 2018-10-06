package tartaruga;

public class Tarta {
	private double x; // punto x
	private double y; // punto y
	private double angolo; // angolo alfa
	private double lunghezza; // lunghezza del segmento

	// --------------------------------------------------------

	public Tarta(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public void sposta(double angolo, double lunghezza) {
		System.out.println(x);
		System.out.println(y);

		x = x + (Math.cos(Math.toRadians(angolo)) * lunghezza);
		y = y + (Math.sin(Math.toRadians(angolo)) * lunghezza);

		System.out.println(x);
		System.out.println(y);

	}

	// --------------------------------------------------------

	public double getX() {
		return x;
	}

	public void setX(double x) {
		this.x = x;
	}

	public double getY() {
		return y;
	}

	public void setY(double y) {
		this.y = y;
	}

	public double getAngolo() {
		return angolo;
	}

	public void setAngolo(double angolo) {
		this.angolo = angolo;
	}

	public double getLunghezza() {
		return lunghezza;
	}

	public void setLunghezza(double lunghezza) {
		this.lunghezza = lunghezza;
	}

}
