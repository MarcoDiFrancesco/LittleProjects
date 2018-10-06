package project;

public class Dadi {
	private int numeroFacce;
	private int ultimaFaccia;

	public Dadi(int numeroFacce) {
		this.numeroFacce = numeroFacce;
		double risultatoRandom = Math.random() * numeroFacce + 1;
		this.ultimaFaccia = (int) risultatoRandom;
	}

	// --------------------------------------------

	public int getNumeroFacce() {
		return numeroFacce;
	}

	public int getUltimaFaccia() {
		return ultimaFaccia;
	}
}
