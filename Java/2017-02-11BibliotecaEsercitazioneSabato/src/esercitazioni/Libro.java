package esercitazioni;

public class Libro {
	private String autore;
	private String titolo; 
	private String genere;
	
	public Libro(String autore, String titolo, String editore, String genere) {
		super();
		this.autore = autore;
		this.titolo = titolo;
		this.genere = genere;
	}

	public void setAutore(String autore) {
		this.autore = autore;
	}

	public void setTitolo(String titolo) {
		this.titolo = titolo;
	}

	public void setGenere(String genere) {
		this.genere = genere;
	}

	public String getAutore() {
		return autore;
	}
	public String getTitolo() {
		return titolo;
	}
	public String getGenere() {
		return genere;
	}

}
