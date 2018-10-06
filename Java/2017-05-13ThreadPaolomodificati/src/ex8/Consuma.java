package ex8;

public class Consuma extends Thread {
	private Buffer buffer;
	private int nome;
	private int tanti;
	public Consuma(Buffer buffer, int nome, int tanti) {
		super();
		this.buffer = buffer;
		this.nome = nome;
		this.tanti = tanti;
	}
	
	public void run(){
		for(int xx=0;xx<tanti;xx++){
			int valore = buffer.togli();
			System.out.println("Consumatore Nr."+ nome +"prende"+ valore);
		}
	}
}
