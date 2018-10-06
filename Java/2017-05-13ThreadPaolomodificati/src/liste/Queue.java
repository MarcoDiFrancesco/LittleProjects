package liste;

public class Queue<T> {
	protected Lista<T> l;

	public Queue() {
		this.l = new Lista<T>();
	}
	
	public Queue(Queue<T> c){
		this.l= new Lista<T>(c.l);
	}
	
	public void enqueue(T s){
		l.aggiungiInTesta(s);
	}
	
	public T dequeue(){
		T s = l.getCoda();
		l.rimuoviInCoda();
		return s;
	}
	
	public int lunghezza(){
		return l.lunghezza();
	}
	
	public boolean isEmpty() {
		return l.isEmpty();
	}
	
	@Override
	public String toString(){
		return l.toString().replaceAll("\t", "");
	}
	
	
}
