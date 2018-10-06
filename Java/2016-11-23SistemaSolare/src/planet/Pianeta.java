package planet;

public class Pianeta {
	private float raggio;
	private float massa;
	private float rOrbita;
	private float velangolare;
	private float x;
	private float y;

	public Pianeta(float raggio, float massa, float rOrbita, float velAngolare, float x, float y) {
		this.raggio = raggio;
		this.massa = massa;
		this.rOrbita = rOrbita;
		this.x = x;
		this.y = y;
	}

	public float getRaggio() {
		return raggio;
	}

	public void setRaggio(float raggio) {
		this.raggio = raggio;
	}

	public float getMassa() {
		return massa;
	}

	public void setMassa(float massa) {
		this.massa = massa;
	}

	public float getrOrbita() {
		return rOrbita;
	}

	public void setrOrbita(float rOrbita) {
		this.rOrbita = rOrbita;
	}

	public float getVelangolare() {
		return velangolare;
	}

	public void setVelangolare(float velangolare) {
		this.velangolare = velangolare;
	}

	public float getX() {
		return x;
	}

	public void setX(float x) {
		this.x = x;
	}

	public float getY() {
		return y;
	}

	public void setY(float y) {
		this.y = y;
	}

	public double gravita() {
		return (6.67e-11) * (massa / raggio * raggio);
	}
}
