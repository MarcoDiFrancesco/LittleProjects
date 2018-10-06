package ex5;

public class Bubble extends Thread{
	
	private double[] b;
	
	
	
	public Bubble(double[] array) {
		super();
		this.b = array;
	}



	public void run() {

		for (int i = 0; i < b.length; i++) {
			boolean flag = false;
			for (int j = 0; j < b.length - 1; j++) {

				if (b[j] > b[j + 1]) {
					int k = (int) b[j];
					b[j] = b[j + 1];
					b[j + 1] = k;
					flag = true;
				}
			}

			if (!flag)
				break;
		}
		System.out.println("finito bubble");
	}
}
