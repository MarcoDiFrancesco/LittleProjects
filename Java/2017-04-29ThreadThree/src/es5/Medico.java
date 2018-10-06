package es5;

public class Medico {
	private Queue<Integer> queue;

	public Medico(String nome, Queue<Integer> queue) {
		super();
		this.queue = queue;
	}

	public void run() {
		for (int i = 0; i < 100; i++) {
			synchronized (queue) {
				if (!queue.isEmpty()) {
					Integer paziente = queue.dequeue();
					System.out.println("sono il dotoor " + getName() + " e ");
				}
			}
			try {
				sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
