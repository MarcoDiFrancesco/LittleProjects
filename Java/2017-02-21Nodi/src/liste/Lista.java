package liste;

public class Lista {
	private Nodo head;

	public void scrivi() {
		Nodo p = head;
		while (p != null) {
			System.out.println(p.nome);
			p = p.next;
		}
	}

	public void addFirst(String s) {
		Nodo n = new Nodo(s);
		n.next = head;
		head = n;
	}

	public void addLast(String s) {
		Nodo n = new Nodo(s);
		if (head == null) {
			head = n;
		} else {
			Nodo p = head;
			while (p.next != null) {
				p = p.next;
			}
			 p.next = n;
		}
	}
	public void add(String s,  int position){
		Nodo n =new Nodo(s);
		int count=0;
		Nodo p = head;
		while(count != position){
			count++;
			p= p.next;
		}
		p.next =n;
		n= n.next;
	}

	public int conta() {
		Nodo p = head;
		int count = 0;
		while (p != null) {
			p = p.next;
			count++;
		}
		return count;
	}
}
