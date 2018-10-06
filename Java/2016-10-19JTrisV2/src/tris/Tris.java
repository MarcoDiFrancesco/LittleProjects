package tris;

import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;

public class Tris extends JFrame implements Consts {

	private static final long serialVersionUID = 1L;

	private Game game = new Game();

	public Tris() {
		initUI();
	}

	private void initUI() {
		addKeyListener(new TAdapter());
		setFocusable(true);
		addMouseListener(new MouseListener());

		add(game);
		setTitle("Tris");

		setDefaultCloseOperation(EXIT_ON_CLOSE);
		getContentPane().setPreferredSize(new Dimension(SCREEN_WIDTH, SCREEN_HEIGHT));
		pack();
		setLocationRelativeTo(null);
		setResizable(false);
		setVisible(true);
	}

	public static void main(String[] args) {

		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				Tris game = new Tris();
				game.setVisible(true);
			}
		});
	}

	private class TAdapter extends KeyAdapter {
		@Override
		public void keyTyped(KeyEvent e) {
			System.out.println(e.getKeyCode());
			if (e.getKeyChar() == 27) {
				Tris.this.dispatchEvent(new WindowEvent(Tris.this, WindowEvent.WINDOW_CLOSING));
			}
		}
	}

	private class MouseListener extends MouseAdapter {
		@Override
		public void mouseClicked(MouseEvent e) {
			game.ckick(e);
		}
	}

}
