package ex2;

public class ThreadWorker extends Thread{

	
	  private int workToDo= 1000000;
	  private boolean stop = false;
	  
	  @Override
	  public void run(){
		  while(!stop && workToDo>0){
			  workToDo--;
			  try{
				  sleep(10);
			  }catch (InterruptedException e){
				  System.out.println("sono stato interrotto");
			  }
		  }
		  System.out.println("sono uscito");
		  if(workToDo>0){
			  System.out.println("ma non ho finito il lavoto ");
		  }
		  
	  }

	public int getWorkToDo() {
		return workToDo;
	}

	public void setWorkToDo(int workToDo) {
		this.workToDo = workToDo;
	}

	

	public void stopThread() {
	stop=true;	
	}



	




}
