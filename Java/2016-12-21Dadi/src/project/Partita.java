package project;

public class Partita {
	private int primoTiro;
	private int secondoTiro;
	private int terzoTiro;

	public Partita() {
		Dadi tiro1 = new Dadi(6);
		System.out.println(tiro1.getUltimaFaccia());
		// tiro1.getUltimaFaccia()=primoTiro;
	}

	// ----------------------------------------
	public int getPrimoTiro() {
		return primoTiro;
	}

	public void setPrimoTiro(int primoTiro) {
		this.primoTiro = primoTiro;
	}

	public int getSecondoTiro() {
		return secondoTiro;
	}

	public void setSecondoTiro(int secondoTiro) {
		this.secondoTiro = secondoTiro;
	}

	public int getTerzoTiro() {
		return terzoTiro;
	}

	public void setTerzoTiro(int terzoTiro) {
		this.terzoTiro = terzoTiro;
	}

}
