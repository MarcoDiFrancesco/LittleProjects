package zaino;

public class Zaino {
	Oggetto[] oggetti;

	public Zaino() { // crea uno zaino con 5 posti per oggetti
		oggetti = new Oggetto[5];
	}

	public Zaino(int postizaino) { // crea uno zaino con postizaino posti per
									// oggetti
		oggetti = new Oggetto[postizaino];
	}

	public Zaino(Zaino z) { // costruttore copia
		this.oggetti = new Oggetto[z.oggetti.length];
		for (int w = 0; w < oggetti.length; w++) {
			this.oggetti[w] = new Oggetto(z.oggetti[w]);
		}
	}

	public Zaino(Zaino z, int pos) { // crea un nuovo zaino con lo stesso
										// contenuto dello zaino z ma con pos
										// posizioni
		this.oggetti = new Oggetto[pos];
		if (pos <= z.oggetti.length) {
			for (int w = 0; w < pos; w++) {
				this.oggetti[w] = new Oggetto(z.oggetti[w]);
			}
		} else {
			for (int w = 0; w < z.oggetti.length; w++) {
				this.oggetti[w] = new Oggetto(z.oggetti[w]);
			}
		}
	}

	public void svuotazaino() { // deve svuotare lo zaino
		for (int w = 0; w < oggetti.length; w++) {
			oggetti[w] = null;
		}
	}

	public void svuotazainoin(Zaino z) { // deve svuotare lo zaino z nello zaino
		if (this.oggetti.length <= z.oggetti.length) {
			for (int w = 0; w > this.oggetti.length; w++) {
				this.oggetti[w] = z.oggetti[w];
			}
		} else {
			for (int w = 0; w < z.oggetti.length; w++) {
				this.oggetti[w] = z.oggetti[w];
			}
		}
		for (int i = 0; i < z.oggetti.length; i++) {
			z.oggetti[i] = null;
		}
	}

	Oggetto addOggetto(Oggetto o) { // aggiunge l'oggetto o allo zaino se non
									// c'è spazio restituisce l'oggetto
									// altrimenti restituisce null
		Oggetto ret = o;
		@SuppressWarnings("unused")
		boolean trovato = false;
		for (int w = 0; w < oggetti.length; w++) {
			trovato = true;
			oggetti[w] = new Oggetto(o);
			ret = null;
		}
		return ret;
	}

	public Oggetto getOggetto(int pos) { // restituisce l'oggetto nella
											// posizione pos dello zaino se la
											// posizione pos non esiste
											// restituisce null,
		Oggetto ret = null;
		if (pos > this.oggetti.length) {
			ret = new Oggetto(oggetti[pos]);
		}
		return ret;
	}

	public Oggetto cercaOggettoConNome(String name) {
		Oggetto ret = null;
		for (int w = 0; w < this.oggetti.length; w++) {
			if (oggetti[w].getNome().equals(name)) {
				ret = new Oggetto(oggetti[w]);
			}
		}
		return ret;
	}
}
