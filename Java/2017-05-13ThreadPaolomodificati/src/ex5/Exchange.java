package ex5;

public class Exchange extends Thread {
	
	private double[] b;
	
	
	
	public Exchange(double[] array) {
		super();
		this.b = array;
	}



	@Override
	public void run() {
		int i, j, temp;
		for (i = 0; i < b.length - 1; i++) {
			for (j = i + 1; j < b.length; j++) {
				if (b[i] < b[j]) {
					temp = (int) b[i];
					b[i] = b[j];
					b[j] = temp;
				}
			}
		}
	System.out.println("ho finito EX");
	}
	
}
