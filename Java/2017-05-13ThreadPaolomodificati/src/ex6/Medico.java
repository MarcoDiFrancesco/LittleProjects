package ex6;
import liste.*;

public class Medico extends Thread{
	Queue<Integer> queue;

	public Medico(String nome ,Queue<Integer> queue) {
		super(nome);
		this.queue = queue;
	}

	@Override
	public void run(){
		for (int i = 0; i <100; i++) {
			synchronized (queue) {
				if(!queue.isEmpty()){
					Integer paziente = queue.dequeue();
					System.out.println("sono il dottor"+ getName() + "e ho preso" );
				}
			}
			try {
				sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}
}