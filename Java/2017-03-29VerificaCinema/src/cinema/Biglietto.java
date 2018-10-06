package cinema;

public class Biglietto {
	private int bigliettoID = 0;
	private String fila = "a";
	private int posto = 0;
	private int costo = 10;
	private boolean ridotto = false;
	private boolean venduto = false;
	private boolean utilizzato = false;

	public Biglietto(int bigliettoID, String fila, int posto, int costo, boolean ridotto, boolean venduto,
			boolean utilizzato) {
		super();
		this.bigliettoID = bigliettoID;
		this.fila = fila;
		this.posto = posto;
		this.costo = costo;
		this.ridotto = ridotto;
		this.venduto = venduto;
		this.utilizzato = utilizzato;
	}

	public int getBigliettoID() {
		return bigliettoID;
	}

	public void setBigliettoID(int bigliettoID) {
		this.bigliettoID = bigliettoID;
	}

	public String getFila() {
		return fila;
	}

	public void setFila(String fila) {
		this.fila = fila;
	}

	public int getPosto() {
		return posto;
	}

	public void setPosto(int posto) {
		this.posto = posto;
	}

	public int getCosto() {
		return costo;
	}

	public void setCosto(int costo) {
		this.costo = costo;
	}

	public boolean isRidotto() {
		return ridotto;
	}

	public void setRidotto(boolean ridotto) {
		this.ridotto = ridotto;
	}

	public boolean isVenduto() {
		return venduto;
	}

	public void setVenduto(boolean venduto) {
		this.venduto = venduto;
	}

	public boolean isUtilizzato() {
		return utilizzato;
	}

	public void setUtilizzato(boolean utilizzato) {
		this.utilizzato = utilizzato;
	}

}
