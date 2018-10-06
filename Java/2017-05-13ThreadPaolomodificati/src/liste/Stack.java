package liste;

public class Stack<T> {
	protected Lista<T> l;

	public Stack() {
		this.l = new Lista<T>();
	}

	public Stack(Stack<T> c){
		this.l= new Lista<T>(c.l);
	}
	
	
	public void push(T s){
		l.aggiungiInTesta(s);
	}
	
	
	public T pop(){
		T s = l.getTesta();
		l.rimuoviInTesta();
		return s;
	}
	
	public int lunghezza(){
		return l.lunghezza();
	}
	
	public boolean isEmpty() {
		return l.isEmpty();
	}
}
