package ex8;

public class Buffer {
	private int dato;
	private boolean disponibile = false;
	
	public synchronized int togli(){
	    while(disponibile == false){
	    	try{
	    		wait();
	    	}catch(InterruptedException e){}}
	    disponibile = false;
	    notify();
	    return dato;
	}
	
	public synchronized void metti(int valore){
		while(disponibile == true){
			try{
			    wait();
			}catch(InterruptedException e){}
		}
		dato= valore;
		disponibile = true;
		notify();
	}
}
