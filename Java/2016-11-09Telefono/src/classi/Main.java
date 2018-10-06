package classi;

import liste.Pila;

public class Main {
	public static void main(String[] args) {
		Pila coda = new Pila();	
		for(int w=0;w<15;w++){
			Contact c = new Contact("nome" + w, "cognome" + w);
			coda.push(c);
		}
		Contact c=(Contact) coda.pop();
		System.out.println(c.getFamilyName());
	}
}