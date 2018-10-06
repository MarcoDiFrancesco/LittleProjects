package ex1;

public class main {
	public static void main(String[] args) {
		ThreadWorker worker = new ThreadWorker();
		System.out.println("delego il mio lavoro al mio lavoratore");
		worker.start();
		System.out.println("intanto faccio altro");
	}
}
