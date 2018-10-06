package esercitazioni;

public class Biblioteca {
	private Libro libri[];

	public void setLibri(Libro[] libri) {
		this.libri = libri;
	}

	public Libro getLibro(String autore, String titolo) {
		for (int i = 0; i < libri.length; i++) {
			if ((libri[i].getAutore()).equals(autore) && (libri[i].getTitolo()).equals(titolo)) {
				return libri[i];
			}
		}
		return null;
	}

	public Libro[] getLibri(String autore) {
		Libro l[] = new Libro[1000];
		int k = 0;
		for (int i = 0; i < libri.length; i++) {
			if ((libri[i].getAutore()).equals(autore)) {
				l[k] = libri[i];
				k++;
			}
		}
		return l;
	}

	public String[] getAutori(String autore) {
		String a[] = new String[1000];
		int k = 0;
		for (int i = 0; i < libri.length; i++) {
			if ((libri[i].getAutore()).equals(autore)) {
				a[k] = libri[i].getAutore();
				k++;
			}
		}
		return a;
	}
}