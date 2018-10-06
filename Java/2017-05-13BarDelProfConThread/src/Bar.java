import java.util.concurrent.locks.*;

public class Bar { // Dati:
	private final int N = 20; // costante che esprime la capacita` bar
	private final int Loc = 0; // indice clienti locali
	private final int Osp = 1; // indice clienti ospiti
	private int[] clienti; // clienti[0]: locali; clienti[1]: ospiti
	private boolean uscita;// indica se il bar è chiuso, o sta per chiudere
	private Lock lock = new ReentrantLock();
	private Condition clientiL = lock.newCondition();
	private Condition clientiO = lock.newCondition();
	private Condition codabar = lock.newCondition(); // coda barista
	private int[] sospesi;

	// Costruttore:
	public Bar() {
		clienti = new int[2];
		clienti[Loc] = 0;
		clienti[Osp] = 0;
		sospesi = new int[2];
		sospesi[Loc] = 0;
		sospesi[Osp] = 0;
		uscita = false;
	}

	// metodi public:
	public void entraL() throws InterruptedException {
		lock.lock();
		try {
			while ((clienti[Osp] != 0) || (clienti[Loc] == N) || uscita || (sospesi[Osp] > 0)) {
				sospesi[Loc]++;
				clientiL.await();
				sospesi[Loc]--;
			}
			clienti[Loc]++;
			if (sospesi[Loc])
				clientiL.signal();
		} finally {
			lock.unlock();
		}
		return;
	}

	public void entraO() throws InterruptedException {
		lock.lock();
		try {
			while ((clienti[Loc] != 0) || (clienti[Osp] == N) || uscita) {
				sospesi[Osp]++;
				clientiO.await();
				sospesi[Osp]--;
			}
			clienti[Osp]++;
			if (sospesi[Osp])
				clientiO.signal();
		} finally {
			lock.unlock();
		}
		return;
	}

	public void esciO() throws InterruptedException {
		lock.lock();
		try {
			clienti[Osp]--;
			if (uscita && (clienti[Osp] == 0))
				codabar.signal();
			else if (sospesi[Osp] > 0)
				clientiO.signal();
			else
				clientiL.signal();
		} finally {
			lock.unlock();
		}
	}

	public void esciL() throws InterruptedException {
		lock.lock();
		try {
			clienti[Loc]--;
			if (uscita && (clienti[Loc] == 0))
				codabar.signal();
			else if (sospesi[Osp] > 0)
				clientiO.signal();
			else
				clientiL.signal();
		} finally {
			lock.unlock();
		}
	}

	public void inizio_chiusura() throws InterruptedException {
		lock.lock();
		try {
			uscita = true;
			while ((clienti[Loc] > 0) || (clienti[Osp] > 0))
				codabar.await();
		} finally {
			lock.unlock();
		}
	}

	public void fine_chiusura() throws InterruptedException {
		lock.lock();
		try {
			uscita = false;
			if (sospesi[Osp] > 0)
				clientiO.signal();
			else
				clientiL.signal();
		} finally {
			lock.unlock();
		}
	}
}// fine classe Bar