package liste;

public class Nodo<T> {
	private T s;
	private Nodo<T> succ;


	public Nodo(T s) {
		this.s = s;
		this.setNext(null);
	}

	public Nodo(T s, Nodo<T> succ) {
		this.s = s;
		this.setNext(succ);
	}

	public T getObject(){
		return s;	
	}
	
	public void setObject(T s){
		this.s=s;

	}
	
	public void setNext(Nodo<T> succ){
		this.succ = succ;	
	}

	public Nodo<T> getNext() {
		return succ;
	}

}
