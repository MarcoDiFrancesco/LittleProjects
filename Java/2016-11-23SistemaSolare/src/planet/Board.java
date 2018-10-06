package planet;

public class Board {
	public int SCREEN_WIDHT = 800;
	public int SCREEN_HEIGHT = 600;

	private int x0;
	private int y0;

	public Board(int SCREEN_WIDHT, int SCREEN_HEIGHT) {
		this.SCREEN_HEIGHT = SCREEN_HEIGHT;
		this.SCREEN_WIDHT = SCREEN_WIDHT;
	}

	public int getX0() {
		return x0;
	}

	public void setX0(int x0) {
		this.x0 = SCREEN_WIDHT / 2;
	}

	public int getY0() {
		return y0;
	}

	public void setY0(int y0) {
		this.y0 = SCREEN_HEIGHT / 2;
	}

}
