package ex8;

public class Produci extends Thread{
	private Buffer buffer;
	private int nome;
	private int tanti;
	public Produci(Buffer buffer, int nome, int tanti) {
		super();
		this.buffer = buffer;
		this.nome = nome;
		this.tanti = tanti;
	}
	public void run(){
		for(int xx= 0; xx< tanti;xx++){
			buffer.metti(xx);
			System.out.println("Produttore Nr." + nome + "mette:"+ xx);
		}
	}
	
}
