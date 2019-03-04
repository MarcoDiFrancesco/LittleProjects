package figuregeometriche;

public class Quadrato extends FiguraGeometrica {
	private float lato;

	public Quadrato(float l) {
		lato = l;
	}

	public float calcolaArea() {
		return lato;
	}
}
