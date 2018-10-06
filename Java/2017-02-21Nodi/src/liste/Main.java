package liste;

public class Main {

	public static void main(String[] args) {
		Lista lista = new Lista();
		lista.addFirst("Paolo");
		lista.addFirst("Marco");
		lista.addFirst("Riccardo");
		lista.addLast("Ciccio");
		lista.add("Luca", 0);
		lista.scrivi();
		System.out.println("CI SONO TOT." + lista.conta());
	}
}
