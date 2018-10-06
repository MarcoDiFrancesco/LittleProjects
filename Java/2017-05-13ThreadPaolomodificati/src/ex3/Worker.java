package ex3;

public class Worker extends Thread{
	private int from, to;
	private String array[];
	
	
	
	
	
	
	public Worker(int from, int to, String[] array) {
		super();
		this.from = from;
		this.to = to;
		this.array = array;
	}






	@Override
	public void run(){
		for (int i = from; i <= to; i++) {
			array[i]=getName();
		}
	}

}
