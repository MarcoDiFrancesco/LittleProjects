package tico;

public class Main {
	public static void main(String[] args) {
		Pacchetto cantarella = new Pacchetto(120);
		Pacchetto ticozzi = new Pacchetto(); // 100 patatine
		Pacchetto prov = new Pacchetto();
		
		System.out.println(cantarella.getNumero());
		System.out.println(ticozzi.getNumero());
		System.out.println((int)(Math.random() * 100));
		
		cantarella.mangiaNPatatine((int)(Math.random() * 100));
		ticozzi.mangiaNPatatine((int)(Math.random() * 100));
		
		System.out.println(cantarella.getNumero());
		System.out.println(ticozzi.getNumero());

		if (cantarella.getNumero() > ticozzi.getNumero()) {
			// Cantarella ha più patatine
			prov = ticozzi;
			ticozzi = cantarella;
			cantarella = prov;
		}
	}
}