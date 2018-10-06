package esercitazioni;

public class Main {
	public static void main(String[] args) {
		Libro libri[] = new Libro[5];
		for (int i = 0; i < libri.length; i++) {
			libri[i].setGenere("Horror");
			libri[i].setTitolo("Dr.Jekill and Mr. Hide");
			libri[i].setAutore("non ricordo");
		}
	}
}
