package tris;

import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.MouseEvent;

import javax.swing.JPanel;

public class Game extends JPanel implements Consts {
	private static final long serialVersionUID = 1L;

	private Font font = new Font("Verdana", Font.BOLD, 18);
	private FontMetrics metrics = this.getFontMetrics(font);

	private Player player = Player.X;
	private GameStatus status = GameStatus.GAME_ON;

	@SuppressWarnings("unused")
	private void initBoard() {
		setDoubleBuffered(true);
	}

	private Board board = new Board();

	public Game() {
		setPreferredSize(new Dimension(SCREEN_WIDTH, SCREEN_HEIGHT));
		setDoubleBuffered(true);
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2d = (Graphics2D) g;
		board.paint(g2d);
	}

	@SuppressWarnings("unused")
	private void printMessage(String message, Graphics2D g2d) {
		g2d.drawString(message, (Consts.SCREEN_WIDTH - metrics.stringWidth(message)) / 2, Consts.SCREEN_WIDTH / 2);
	}

	public void ckick(MouseEvent e) {
	}

	public Player getPlayer() {
		return player;
	}

	public void setPlayer(Player player) {
		this.player = player;
	}

	public GameStatus getStatus() {
		return status;
	}

	public void setStatus(GameStatus status) {
		this.status = status;
	}
}
