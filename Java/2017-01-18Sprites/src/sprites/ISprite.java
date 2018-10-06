package sprites;

import java.awt.Graphics2D;

public interface ISprite {
	void draw(Graphics2D g2d);

	void moveUp();

	void moveDown();

	void moveLeft();

	void moveRight();

}
