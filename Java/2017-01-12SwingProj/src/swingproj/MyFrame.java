package swingproj;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class MyFrame {

	private JFrame frame;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MyFrame window = new MyFrame();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public MyFrame() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		// frame.setBounds(50, 50, 600, 600);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JTextField text = new JTextField();
		frame.add(text, BorderLayout.PAGE_START);
		JPanel panel = new JPanel();
		frame.add(panel, BorderLayout.CENTER);
		panel.setLayout(new GridLayout(4, 4));

		ActionListener al = new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Object o = e.getSource();
				if (o instanceof JButton) {
					JButton button = (JButton) o;
					System.out.println();
					if (button.getText().equals("2")) {
						text.setText("Due"); 
						// Devo mettere il coso che clicco in un intero poi fare i calcoli
					}
				}
			}
		};

		for (int w = 0; w < 13; w++) {
			JButton button = new JButton(Integer.toString(w));
			panel.add(button);
			button.addActionListener(al);
		}
		frame.pack();
		frame.setLocationRelativeTo(null);
	}
}
