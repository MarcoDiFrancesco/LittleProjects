package sprites;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class MainFrame extends JFrame implements ActionListener {
	private static final long serialVersionUID = 1L;
	private DrawablePanel drawablePanel;
	private JButton up, down, left, right;

	public MainFrame() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		drawablePanel = new DrawablePanel();
		add(drawablePanel, BorderLayout.CENTER);

		up = new JButton("Up");
		up.addActionListener(this);
		down = new JButton("Down");
		down.addActionListener(this);
		left = new JButton("Left");
		left.addActionListener(this);
		right = new JButton("Right");
		right.addActionListener(this);

		JPanel buttonPanel = new JPanel(new GridLayout(3, 3));
		buttonPanel.add(new JPanel());
		buttonPanel.add(up);
		buttonPanel.add(new JPanel());
		buttonPanel.add(left);
		buttonPanel.add(new JPanel());
		buttonPanel.add(right);
		buttonPanel.add(new JPanel());
		buttonPanel.add(down);
		buttonPanel.add(new JPanel());
		add(buttonPanel, BorderLayout.PAGE_END);

		pack();
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		Object source = e.getSource();

		if (source == up) {
			drawablePanel.moveSpriteUp();
		}
		if (source == down) {

			drawablePanel.moveSpriteDown();
		}
		if (source == left) {

			drawablePanel.moveSpriteLeft();
		}
		if (source == right) {

			drawablePanel.moveSpriteRight();
		}

		System.out.println(e.getActionCommand());
	}

}
