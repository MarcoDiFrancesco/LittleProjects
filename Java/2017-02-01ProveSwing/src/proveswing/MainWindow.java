package proveswing;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JProgressBar;
import javax.swing.JTextField;

public class MainWindow extends JFrame implements ActionListener {
	private static final long serialVersionUID = 1L;
	private JProgressBar progBar;
	// private Timer timer = new Timer(1000, this);

	public MainWindow() {
		super("Prove Swing");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new FlowLayout());
		add(new JLabel("Questa è un'etichetta"));
		add(new JTextField("Questo è un pulsante"));
		progBar = new JProgressBar(JProgressBar.VERTICAL, 15, 25);
		progBar.setValue(25);
		add(progBar);

		pack();
	}

	public void actionPerformed(ActionEvent e) {
		progBar.setValue(progBar.getValue() + 10);
	}
}
