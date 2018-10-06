package sprites;

import java.awt.Graphics2D;

import javax.swing.ImageIcon;

public class RobotSprite implements ISprite {
	private int x = 100, y = 100;
	private ImageIcon images[];

	public void draw(Graphics2D g2d) {
	}

	public void moveUp() {
	}

	public void moveDown() {
	}

	public void moveLeft() {
	}

	public void moveRight() {
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public ImageIcon[] getImages() {
		return images;
	}

	public void setImages(ImageIcon images[]) {
		this.images = images;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}
}
