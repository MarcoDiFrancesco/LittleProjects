package ex7;

import java.util.LinkedList;
import java.util.Queue;

public class Segreteria {
	private Queue<String> pazienti = new LinkedList<>();

	public Segreteria(String nome) {
		for (int i = 0; i < 1000; i++) {
			pazienti.add("paziente  " + i);
		}
	}
	
	public Queue<String> getPazienti() {
		return pazienti;
	}
}
