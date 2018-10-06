package liste;

import classi.Contact;

public class Pila {
	private Contact[] values = new Contact[10];
	private int pos = 0;

	public void push(Contact c) {
		if (pos == values.length) {
			Contact[] newValues = new Contact[values.length + 10];
			for (int w = 0; w < values.length; w++) {
				newValues[w] = values[w];
			}
			values = newValues;
		}
		values[pos] = c;
		pos++;
	}

	public Contact pop() {
		if (pos <= 0) {
			return null;
		}
		pos--;
		Contact c = values[pos];
		values[pos] = null;
		return c;
	}
}