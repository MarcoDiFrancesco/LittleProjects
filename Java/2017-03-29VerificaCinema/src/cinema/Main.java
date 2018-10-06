package cinema;

public class Main {

	public static void main(String[] args) {
		Sala primo = new Sala(100);
		Sala secondo = new Sala(150);
		Sala terzo = new Sala(200);

		primo.proiezione1.biglietti[0].setBigliettoID(0);
		secondo.proiezione3.bigliettoAnalizzato.setCosto(15);
		terzo.proiezione2.biglietti[14].setFila("a");
	}
}
