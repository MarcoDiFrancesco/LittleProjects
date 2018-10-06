package liste;

public class Lista {
	private Object[] values = new Object[10];
	private int pos = 0;

	public void push(Object c) {
		if (pos == values.length) {
			Object[] newValues = new Object[values.length + 10];
			for (int w = 0; w < values.length; w++) {
				newValues[w] = values[w];
			}
			values = newValues;
		}
		values[pos] = c;
		pos++;
	}

	public void rimuovi(int p) {
		for (int w = 0; w < values.length; w++) {
			values[w] = values[w + 1]; // cambio posizione
		}
	}

	public int getPosizione() {
		return pos;
	}

}