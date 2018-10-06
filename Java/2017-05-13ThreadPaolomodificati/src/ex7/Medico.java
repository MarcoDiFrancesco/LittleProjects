package ex7;

import java.util.LinkedList;
import java.util.Queue;

public class Medico extends Thread{
	private Queue<String> pazienti = new LinkedList<>();

	public Medico(String nome, Queue<String> pazienti) {
		super(nome);
		this.pazienti = pazienti;
	}

	@Override
	public void run(){
		for (int i = 0; i <100; i++) {
			synchronized (pazienti) {
				if(!pazienti.isEmpty()){
					String paziente =  pazienti.poll();
					System.out.println("sono il dottor"+ getName() + "e ho preso" + paziente );
				}
			}
			try {
				sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}
}