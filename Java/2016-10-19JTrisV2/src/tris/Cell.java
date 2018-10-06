package tris;

import java.awt.Graphics2D;

public class Cell {
	private int x, y, w, h;
	private Player status = Player.NONE;

	public Cell(int x, int y, int w, int h) {
		super();
		this.x = x;
		this.y = y;
		this.w = w;
		this.h = h;
	}

	public boolean checkPosition(int x, int y) {
		return x >= this.x && x <= this.x + this.w;
	}

	public void paint(Graphics2D g2d) {
		if (status == Player.O) {
			paintO(g2d);
		} else if (status == Player.X) {
			paintX(g2d);
		}
	}

	private void paintX(Graphics2D g2d) {
		g2d.drawLine(x, y, x + w, y + h);
		g2d.drawLine(x + w, y, x, y + h);
	}

	private void paintO(Graphics2D g2d) {
		g2d.drawOval(x, y, w, h);
	}
}