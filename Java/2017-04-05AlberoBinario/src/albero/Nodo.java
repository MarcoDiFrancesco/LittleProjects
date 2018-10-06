package albero;

public class Nodo {
	private int colorInt;
	private char colorChar;
	public Nodo sx;
	public Nodo dx;

	public Nodo(int colorInt, char colorChar) {
		super();
		this.colorInt = colorInt;
		this.colorChar = colorChar;
	}

	public int getColorInt() {
		return colorInt;
	}

	public void setColorInt(int colorInt) {
		this.colorInt = colorInt;
	}

	public char getColorChar() {
		return colorChar;
	}

	public void setColorChar(char colorChar) {
		this.colorChar = colorChar;
	}

}
