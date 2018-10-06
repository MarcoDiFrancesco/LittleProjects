package ex1;

public class ThreadWorker extends Thread{
	private long workToDo = Long.MAX_VALUE;

	@Override
	public void run(){
		while (workToDo>0){
			workToDo--;
		}
	}

}
