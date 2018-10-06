package liste;

public class Lista<T> {
	private Nodo<T> testa;

	public Lista (){
		testa=null;
	}
	public Lista (Lista<T> l){
		this.testa=null;
		if(l!=null){
			Nodo<T> n1=l.testa;
			Nodo<T> n2 = null;

			while (n1!=null) {

				Nodo<T> nuovo = new Nodo<T>(n1.getObject());
				
				if(this.testa==null){

					this.testa = nuovo;
					n2=this.testa;

				}else {
					n2.setNext(nuovo);
					n2=n2.getNext();
				}
				n1=n1.getNext();
			}	

		}
	}

	public void aggiungiInTesta(T s){
		Nodo<T> nuovo= new Nodo<T>(s,testa);
		testa = nuovo;
	}
	
	public void svuota(){ 
		testa = null;
	}
	
	public void rimuoviInTesta(){  //---------//
		if(testa!=null){
			testa=testa.getNext();
		}
	}

	public void aggiungiInCoda(T s){
		if(testa==null){
			aggiungiInTesta(s);
		}else{
			Nodo<T> ultimo = new Nodo<T>(s);
			Nodo<T> aus = testa;

			while(aus.getNext()!=null){
				aus=aus.getNext();	
			}
			aus.setNext(ultimo);
		}
	}
       
	public void rimuoviInCoda(){   // l1.next = null;
		Nodo<T> aux = testa;
		int l = lunghezza();
		if (l == 0) return;
		else if (l == 1) {
			svuota();
		} else {
			for (int i = 0; i < l-2; i++) {
				aux=aux.getNext();
			}
			aux.setNext(null);
		}
		//	l1.testa.getSucc().getSucc();

	}
	public void aggiungiIesimo(T s,int i){
		if(i<0||i>lunghezza())
			throw new IndexOutOfBoundsException();
		if(i==0) 
			aggiungiInTesta(s);
		else if(i==lunghezza())
			aggiungiInCoda(s);
		else{
			Nodo<T> aus = testa;
			for (int j = 0; j < i - 1; j++) {
				aus=aus.getNext();
			}
			Nodo<T> nuovo = new Nodo<T>(s, aus.getNext());
			aus.setNext(nuovo);
		}
	}
	public void rimuoviIesimo(int i){ //   l1.next = l1.next.next;
		if(i<0||i>=lunghezza())
			throw new IndexOutOfBoundsException();
		if(i==0) 
			rimuoviInTesta();
		else if(i==lunghezza()-1)
			rimuoviInCoda();
		else{
			Nodo<T> aus = testa;
			for (int j = 0; j < i - 1; j++) {
				aus=aus.getNext();
			}
			//Nodo nuovo = null;
			aus.setNext(aus.getNext().getNext());
		}
	}
	public int lunghezza(){
		Nodo<T> aus=testa;
		int i=0;
		while(aus!=null){
			i++;
			aus=aus.getNext();
		}
		return i;
	}
	public T getTesta(){
		if(testa==null) return null;
		return testa.getObject();
	}
	
	public T getCoda(){
		Nodo<T> aux = testa;
		if(aux==null) return null;
		while(aux.getNext()!= null){
			aux=aux.getNext();
		}
        return aux.getObject();
	}
	
	public T getIesimo(int i){
		if(i<0||i>=lunghezza())
			throw new IndexOutOfBoundsException();
		
		Nodo<T> aux = testa;
		
		for (int j = 0; j < i; j++) {
			aux = aux.getNext();
		}
		return aux.getObject();
	}
	
	@Override
	public String toString() {
		Nodo<T> aus = testa;
		String s = "";
		while(aus != null) {
			s += aus.getObject() + "\t";
			aus = aus.getNext();
		}
		return s;
	}
	
	public boolean isEmpty() {
		return testa == null;
	}
}
