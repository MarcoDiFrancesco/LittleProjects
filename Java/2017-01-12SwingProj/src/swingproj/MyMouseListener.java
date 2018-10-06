package swingproj;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class MyMouseListener implements MouseListener {
	public void mouseClicked(MouseEvent e) {
		System.out.println("Mouse clicked");
	}

	public void mousePressed(MouseEvent e) {
		System.out.println("Mouse pressed");
	}

	public void mouseReleased(MouseEvent e) {
		System.out.println("Mouse relased");
	}

	public void mouseEntered(MouseEvent e) {
		System.out.println("Mouse entered");
	}

	public void mouseExited(MouseEvent e) {
		System.out.println("Mouse exited");
	}

}
