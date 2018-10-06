package ex5;

public class Sort extends Thread {

	private double[] b;
	
	
	
	 public Sort(double[] array) {
		super();
		this.b = array;
	}



	public  void run() {
		    int inner, outer;
		    int temp;
		 
		    int h = 1;
		    while (h <= b.length / 3) {
		      h = h * 3 + 1;
		    }
		    while (h > 0) {
		      for (outer = h; outer < b.length; outer++) {
		        temp = (int) b[outer];
		        inner = outer;
		 
		        while (inner > h - 1 && b[inner - h] >= temp) {
		          b[inner] = b[inner - h];
		          inner -= h;
		        }
		        b[inner] = temp;
		      }
		      h = (h - 1) / 3;
		    }
		    System.out.println("finito sort");
		  }
}
