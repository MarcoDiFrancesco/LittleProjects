package ex6;

import liste.*;
public class Segreteria extends Thread{
	private Queue<Integer> queue;
//segretaria prende i pazienti e i thread medici prendono i pazienti e li mettono nella propria coda

	public Segreteria(Queue<Integer> queue) {
		super();
		this.queue = queue;
	}

@Override
	public void run(){
		for (int i = 0; i <50; i++) {

		}
		int paziente = (int) (Math.random()*1000+100) ;
	}
}
