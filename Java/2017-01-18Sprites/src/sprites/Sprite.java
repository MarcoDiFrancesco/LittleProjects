package sprites;

import java.awt.Graphics2D;

public class Sprite implements ISprite {
	private int x = 100, y = 100, w = 50, h = 50;

	public void draw(Graphics2D g2d) {
		g2d.drawRect(x, y, w, h);
	}

	public void moveUp() {
		y = y - 10;
	}

	public void moveDown() {
		y = y + 10;
	}

	public void moveLeft() {
		x = x - 10;
	}

	public void moveRight() {
		x = x + 10;
	}

}
