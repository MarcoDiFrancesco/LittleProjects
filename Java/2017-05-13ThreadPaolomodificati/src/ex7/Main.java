package ex7;

public class Main {
	public static void main(String[] args) {
		Segreteria segreteria = new Segreteria("giovanna");
		
		Thread dottorBianchi = new Thread(new Medico("dottorBianchi", segreteria.getPazienti()));
		Thread dottorNeri = new Thread(new Medico("dottorNeri", segreteria.getPazienti()));
		Thread dottorRossi = new Thread(new Medico("dottorRossi", segreteria.getPazienti()));
		Thread dottorVerdi = new Thread(new Medico("dottorVerdi", segreteria.getPazienti()));
		
		dottorBianchi.start();
		dottorNeri.start();
		dottorRossi.start();
		dottorVerdi.start();
	}
}
