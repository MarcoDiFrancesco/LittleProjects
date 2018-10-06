package cinema;

public class Proiezione {
	private int oraInizio;
	private int minutoInizio;
	private int oraFine;
	private int minutoFine;
	private int giorno;
	private String titolo;

	private int numeroBiglietti = 100;

	Biglietto[] biglietti = new Biglietto[numeroBiglietti];
	Biglietto bigliettoAnalizzato;

	public Proiezione(int oraInizio, int minutoInizio, int oraFine, int minutoFine, int giorno, String titolo) {
		super();
		this.oraInizio = oraInizio;
		this.minutoInizio = minutoInizio;
		this.oraFine = oraFine;
		this.minutoFine = minutoFine;
		this.giorno = giorno;
		this.titolo = titolo;
		// inizializzo tutti i biglietti
		for(int w=0;w<100;w++){ 
			biglietti[w]=new Biglietto(0, "a", 0, 10, false, false, false);
		}
	}

	public boolean vendita() {
		boolean venduto = false;
		for (int w = 0; w < numeroBiglietti; w++) {
			if (biglietti[w].isVenduto() == false && venduto == false) {
				biglietti[w].setVenduto(true);
				venduto = true;
			}
		}
		return venduto;
	}

	public boolean controlloBiglietto() {
		boolean esiste = false;
		for (int w = 0; w < numeroBiglietti; w++) {
			if (bigliettoAnalizzato.getBigliettoID() == biglietti[w].getBigliettoID()
					&& biglietti[w].isUtilizzato() == false) {
				esiste = true;
				biglietti[w].setUtilizzato(true);
			}
		}
		return esiste;
	}

	public int incassoTotale() {
		int totale = 0;
		for (int w = 0; w < numeroBiglietti; w++) {
			if (biglietti[w].isUtilizzato() == true) {
				totale = totale + biglietti[w].getCosto();
			}
		}
		return totale;
	}

	public int numeroBigliettiVenduti() {
		int totale = 0;
		for (int w = 0; w < numeroBiglietti; w++) {
			if (biglietti[w].isVenduto() == true) {
				totale++;
			}
		}
		return totale;
	}

	/////////////////////////////////// GETTER E SETTER

	public int getOraInizio() {
		return oraInizio;
	}

	public void setOraInizio(int oraInizio) {
		this.oraInizio = oraInizio;
	}

	public int getMinutoInizio() {
		return minutoInizio;
	}

	public void setMinutoInizio(int minutoInizio) {
		this.minutoInizio = minutoInizio;
	}

	public int getOraFine() {
		return oraFine;
	}

	public void setOraFine(int oraFine) {
		this.oraFine = oraFine;
	}

	public int getMinutoFine() {
		return minutoFine;
	}

	public void setMinutoFine(int minutoFine) {
		this.minutoFine = minutoFine;
	}

	public int getGiorno() {
		return giorno;
	}

	public void setGiorno(int giorno) {
		this.giorno = giorno;
	}

	public String getTitolo() {
		return titolo;
	}

	public void setTitolo(String titolo) {
		this.titolo = titolo;
	}

	public Biglietto[] getBiglietti() {
		return biglietti;
	}

	public void setBiglietti(Biglietto[] biglietti) {
		this.biglietti = biglietti;
	}

	public Biglietto getBigliettoAnalizzato() {
		return bigliettoAnalizzato;
	}

	public void setBigliettoAnalizzato(Biglietto bigliettoAnalizzato) {
		this.bigliettoAnalizzato = bigliettoAnalizzato;
	}
}
