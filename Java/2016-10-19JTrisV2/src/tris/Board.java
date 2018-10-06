package tris;

import java.awt.Graphics2D;

public class Board implements Consts {
	private Cell cells[][] = new Cell[CELLS][CELLS];

	public Board() {
		int cellW = SCREEN_WIDTH / CELLS;
		int cellH = SCREEN_HEIGHT / CELLS;

		for (int i = 0; i < cells.length; i++) {
			for (int j = 0; j < cells[i].length; j++) {
				cells[j][i] = new Cell(j * cellW, i * cellH, cellW, cellH);
			}
		}
	}

	public void paint(Graphics2D g2d) {
		// codice di disegno della board
		int cellWidth = SCREEN_WIDTH / 3;
		int cellHeight = SCREEN_HEIGHT / 3;

		g2d.drawLine(0, cellHeight, SCREEN_WIDTH, cellHeight);
		g2d.drawLine(0, cellHeight * 2, SCREEN_WIDTH, cellHeight * 2);
		g2d.drawLine(cellWidth, 0, cellWidth, SCREEN_WIDTH);
		g2d.drawLine(cellWidth * 2, 0, cellWidth * 2, SCREEN_WIDTH);

		// chiamo il paint delle celle
		for (int i = 0; i < cells.length; i++) {
			for (int j = 0; j < cells[i].length; j++) {
				cells[j][i].paint(g2d);
			}
		}
	}
}