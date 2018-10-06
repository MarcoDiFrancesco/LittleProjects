package bar;

import java.util.LinkedList;

public class Buffer {
	LinkedList<String> coda;
	int sizeMax;

	public Buffer(int sizeMax) {
		coda = new LinkedList();
		this.sizeMax = sizeMax;
	}

	public boolean isEmpty() {
		return coda.isEmpty();
	}

	public boolean isFull() {
		return coda.size() >= sizeMax;
	}

	public synchronized void aggiungiInfo(String info) {
		while (isFull()) {
			try {
				wait();
			} catch (InterruptedException ex) {
				System.err.println("Interrupted Exception");
			}
		}
		coda.addFirst(info); // coda non sarà piena
		notifyAll();
	}

	public synchronized String prelevaInfo() {
		while (isEmpty()) {
			try {
				wait();
			} catch (InterruptedException ex) {
				System.err.println("Interrupted Exception");
			}
		}
		String info = coda.removeFirst(); // coda non sarà vuota
		notifyAll();
		return info;
	}
}
