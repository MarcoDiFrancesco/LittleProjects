package es1;

public class ThreadWorker extends Thread{
	private int workToDo = 1000000;
	private boolean stop = false;
	@Override
	public void run() {
		while(!stop && workToDo>0){
			workToDo--;
			try {
				sleep(10);
			} catch (InterruptedException e) {
				System.err.println("Sono stato interrotto");
				
			}
			System.out.println(workToDo);
		}
		System.out.println("Sono uscito");
		if(workToDo > 0){
			System.out.println("Ma non ho finito il lavoro");
		}
			
	}
	public int getWorkToDo() {
		return workToDo;
	}
	public void stopThread() {
		stop = true;

	}
}
