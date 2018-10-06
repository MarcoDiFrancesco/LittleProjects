package es1;

import javax.swing.plaf.SliderUI;

public class Main {
	public static void main(String[] args) {
		ThreadWorker worker = new ThreadWorker();
		worker.start();
		System.out.println("Intanto faccio altro");
		
		
	}

}
