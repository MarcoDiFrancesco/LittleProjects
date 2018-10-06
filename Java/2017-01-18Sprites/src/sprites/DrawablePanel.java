package sprites;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JPanel;

public class DrawablePanel extends JPanel {
	private static final long serialVersionUID = 1L;

	private ISprite sprite = new Sprite();

	public DrawablePanel() {
		setPreferredSize(new Dimension(600, 400));
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);

		if (g instanceof Graphics2D) {
			Graphics2D g2d = (Graphics2D) g;
			if (sprite != null) {
				sprite.draw(g2d);
			}
		}
	}
	
	
	void moveSpriteUp() {
		sprite.moveUp();
		repaint();
	}

	void moveSpriteDown() {
		sprite.moveDown();
		repaint();
	}

	void moveSpriteLeft() {
		sprite.moveLeft();
		repaint();
	}

	void moveSpriteRight() {
		sprite.moveRight();
		repaint();
	}

}
